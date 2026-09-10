# lcagent — LeetCode Practice Multi-Agent System

A command-line multi-agent system for this practice repo. A **master agent runs
in a loop** dispatching to specialist agents that fetch problems, render
readable question files, verify solutions, score them, and archive the result.

Runs on **Windows and Linux**, from `cmd.exe` or any POSIX shell, and is
**free to run end to end** — no subscription, and no paid API. Roughly half the
agents are deterministic Python that always work offline; the rest run on a
free tier (Groq, Gemini, Cerebras, OpenRouter) or a fully local Ollama model.

```bash
./lc                       # Linux            \
lc.bat                     # Windows           }  the menu-driven loop
python -m lcagent          # either            /
python -m lcagent run 2859 # one-shot, scriptable, real exit codes
```

The loop opens on a numbered menu and redisplays it after every action.
Pick a number, or type any command name — both go down the same path, so the
menu is a front end and never a second implementation.

```
┌────────────────────────────────────────────────────────────┐
│ lcagent · 2859                                        groq │
└────────────────────────────────────────────────────────────┘
  PROBLEM
   1  New problem     fetch, scaffold, write the question file
   2  Show question   statement, constraints, test cases
  SOLVE
   3  Run tests       compile, run, per-case results
   4  Watch           auto test + score on every save
   5  Score           grade + better-approach check
  SESSION
   6  Status          what is loaded, which files exist
   7  Agents          the agent roster
   8  Providers       model backends, and which are usable
   9  Help            every command and alias
   0  Quit            save the session and exit
  choose [0-9] or type a command >
```

Bare **Enter** redisplays the menu. The header shows the loaded problem and
whether a model provider is live.

All agent-produced data lives under `lcagent/data/` — nothing is scattered into
the practice repo.

---

## Phase status

| Phase | Scope | LLM | Status |
|:--|:--|:--:|:--|
| **0** | `core/` — paths, compiler discovery, run, per-case diff | no | ✅ done |
| **1** | Statement agent → `<id>_problem.txt` | no | ✅ done |
| **2** | Fetcher + Verifier agents, Master loop (REPL + watcher) | no | ✅ done |
| **3** | Providers (free-first) + Scorer — rubric, benchmark, reference diff | partial | ✅ done |
| **3.5** | Improver — write, verify and install the better solution | yes | ✅ done |
| **4** | DriverRepair / Solver / Debugger | yes | ✅ done |
| **5** | Archiver + Tracker + Classifier + Committer | no | ⬜ next |
| **6** | Notes + reporting | partial | ⬜ |

---

## Development log

### Phase 0 — Portable execution core (2026-09-10) ✅

The foundation every other phase sits on: locate a compiler, build a solution,
run it, compare output per test case — without bash.

| File | Role |
|:--|:--|
| `core/paths.py` | Repo-root discovery, agent-data root, `ProblemPaths` |
| `core/compiler.py` | `g++` discovery, `compile_cpp()`, precompiled-header cache |
| `core/runner.py` | `run_binary()` — stdin feed, capture, cross-platform timeout |
| `core/testcase.py` | `verify()` → `TestReport` — the Python port of `run.sh` |

**Decisions**

1. **`run.sh` was ported, not wrapped.** `cmd.exe` has no bash, so shelling out
   would have made Windows support impossible. The payoff beyond portability:
   results come back as a `TestReport` dataclass that the scoring and debugging
   agents read directly, instead of text they would have to re-parse. It also
   sidesteps the `cd`-prefix permission quirk noted in the project memory.
2. **MinGW-w64 required on Windows.** Solutions `#include <bits/stdc++.h>`, a
   libstdc++ extension — MSVC cannot compile them. `find_compiler()` searches
   `PATH`, then standard MSYS2 / TDM-GCC locations, then fails with install
   instructions. `CXX` overrides.
3. **Binaries build to a temp dir, never the repo.** `run.sh` writes `./sol_<N>`
   into the working tree and removes it only on the happy path — which is how a
   stale 45 KB `sol_18` got committed.
4. **The compile target is the driver, not the solution**, mirroring `run.sh`'s
   `<id>_*.cpp`-over-`<id>.cpp` preference.
5. **`subprocess`'s own timeout**, not `signal.alarm` — signals are the sharpest
   Windows/POSIX divergence in process control.

**Verified** against problem 2859 plus five injected faults: passing (`OK`,
output identical to `run.sh`), wrong answer (per-case expected/got **plus the
failing input**, recovered from the driver's stderr echo), missing semicolon
(`COMPILE_ERROR`, diagnostics trimmed), null deref (`RUNTIME_ERROR`, exit −11),
infinite loop (`TIMEOUT`, killed not hung), deleted files (`MISSING_FILES`).

---

### Phase 1 — Statement agent (2026-09-10) ✅

`<id>_problem.txt`: the question, its constraints, and every example test case
with its expected result — written **at the repo root at fetch time**, beside
the code it describes, and swapped out with the rest of the scaffold when a new
problem is fetched. It is part of the problem scaffold, not an agent
by-product, which is why it does not live under `data/`.

| File | Role |
|:--|:--|
| `core/leetcode.py` | GraphQL client + persistent JSON cache |
| `core/state.py` | `Context` — the blackboard agents share |
| `agents/base.py` | `Agent` contract, `AgentResult` |
| `agents/statement.py` | HTML → sectioned, wrapped text file |

**Decisions**

1. **A richer GraphQL query than `fetch_problem.py` uses.** It never requests
   `difficulty`, `topicTags` or `hints` — all of which the statement file and
   the topic classifier need. Responses are cached to `data/cache/<id>.json`, so
   re-rendering costs no network.
2. **Superscripts are resolved before tags are stripped.** `fetch_problem.py`'s
   `strip_html` replaces every tag with a newline, turning `10<sup>5</sup>` into
   `"10\n5\n"` — destroying exactly the constraint magnitudes that decide which
   complexity is required. This parser emits `10^5`.
3. **Newline-straddling `<sub>` tags preserved.** LeetCode writes
   `100<sub>2 \n</sub>Indices ...`; a naive `\s*` strip welds two sentences into
   `1002Indices`. Any newline inside the tag survives.
4. **Three-level degradation:** live fetch → cache → local `_input`/`_expected`
   files. Fully offline still produces a usable file.

**Verified** across problem shapes — design (146: constructor + `get` + `put`
all extracted, trailing usage comment stripped), tree (104), hard (4), string
(5), matrix (37), linked list (2), array (1). Offline-with-cache and
offline-without-cache both behave.

#### Later corrections to the statement agent (2026-09-11)

Fetching problem **4046** live exposed two parser faults, both silent:

1. **Every recent problem was losing its examples.** LeetCode changed markup:
   older problems wrap examples in `<pre>`, newer ones use
   `<div class="example-block">` with `<span class="example-io">`. The parser
   knew only `<pre>`, so 4046 produced **zero** examples and quietly fell back
   to reading the local `_input`/`_expected` files — losing every explanation.
   Both markups are now matched in document order; regression-checked across
   nine problems spanning both formats.
2. **Zero-width characters leaked into the output.** LeetCode embeds runs of
   `U+200B` in explanations, which rendered as phantom blank lines. Now
   stripped along with `U+2009`, `U+2060` and `U+FEFF`.

Two attempts at fix (2) **silently did nothing** before it took: `str.replace`
returns its input unchanged on a miss rather than raising, and the match string
had escape-mangled characters. Every patch here now asserts that its anchor was
found.

The file is also **brief by default** — hints are omitted (they are spoilers,
and on a hard problem run longer than the statement itself) and explanations cap
at three lines. `render(..., brief=False)` restores them.

---

### Phase 2 — Fetcher, Verifier, and the Master loop (2026-09-10) ✅

The system becomes usable: a loop you talk to.

| File | Role |
|:--|:--|
| `agents/fetcher.py` | Scaffold a problem — LeetCode, or the local archive |
| `agents/verifier.py` | Compile / run / diff, wrapped as an agent |
| `agents/master.py` | The REPL, the file watcher, session persistence |
| `core/ui.py` | Colour that degrades correctly on `cmd.exe` |
| `__main__.py`, `lc`, `lc.bat` | Entry point and per-OS shims |

**Decisions**

1. **`fetch_problem.py` is delegated to, not reimplemented.** Its snippet
   parsing and driver generation are the hard-won parts. It is invoked through
   `sys.executable` because `python3` is usually absent from PATH on Windows.
2. **Offline scaffolding from the archive.** `Code Dirs/All LC 1 - 4017/<id>/`
   already holds driver + input + expected for 3356 problems, so `new --offline`
   works with no network at all.
3. **Polling, not `watchdog`.** Keeps the system on the standard library — no
   pip install, nothing that fails differently across the two OSes. 0.4 s poll,
   0.6 s debounce so a half-written editor save is never compiled.
4. **Windows colour is opted into explicitly** via `SetConsoleMode`, and
   disabled when piped or when `NO_COLOR` is set.
5. **A precompiled header for `bits/stdc++.h`.** Measured: parsing that one
   header was **4.5 s of a 5.0 s build**, and the optimisation level barely
   moved it (`-O0` was *slower*). Precompiling cut a warm rebuild to **2.8 s**.
   The `.gch` is 139 MB and valid only for the flags that built it, so the cache
   is pinned to the single flag set the verify path uses; debug builds skip it
   rather than spawning a second copy. It lives in temp, not the repo.

| | before | after |
|:--|--:|--:|
| warm compile | 5.0 s | **2.8 s** |
| cold (builds PCH, once) | — | 12 s |
| run | 3 ms | 3 ms |

**Verified** — REPL dispatch, aliases, unknown-command handling, one-shot mode
with correct exit codes, and watch mode driven live: an injected bug was caught
automatically on save, and the fix was confirmed green on the next save without
a keystroke.

**Two defects found and fixed during testing**
- A failed `new 9999` left the session pointing at a nonexistent problem, and
  persisted it. `cmd_new` now restores the previous context on failure, and
  `_restore` refuses to resume onto a problem with no files on disk.
- `status` showed no title because nothing hydrated `ctx.problem`; it now reads
  the cache with no network.

#### Fetcher hardening — premium problems and the no-clobber rule (2026-09-10)

Testing the fetcher against problem **186** (*Reverse Words in a String II*)
exposed a class of failure the design had not accounted for.

**LeetCode Premium problems return metadata but no body.** `title`,
`difficulty` and `tags` come back; `content` and `codeSnippets` are empty or
`null`. Three consequences, all now handled:

1. **`fetch_problem.py` crashed on them.** It read
   `data.get("codeSnippets", [])`, but a `dict.get` default only applies when
   the key is *absent* — LeetCode sends the key with a `null` value, so it
   returned `None` and the generator raised
   `TypeError: 'NoneType' object is not iterable`. Fixed to
   `data.get("codeSnippets") or []`. *(This was a pre-existing bug in the
   script, not in the agent layer.)*
2. **The error explained nothing.** A raw `TypeError` gave no hint that the
   cause was a paywall. `leetcode.fetch_question` now returns a `locked` flag,
   and the fetcher reports *"186 (Reverse Words in a String II) is a LeetCode
   Premium problem — no statement or code snippet is served"*.
3. **The statement file said only "(unavailable)".** It now names the reason
   and still renders the test cases recovered from the local files.

**The no-clobber rule.** The more serious finding: a failed fetch used to fall
back to the archive *unconditionally*, overwriting whatever sat at the repo
root — including a solution in progress. `fetch_problem.py` also writes
directly into the working tree and can die part-way through, leaving a
half-written scaffold. The fetcher is now transactional, and **destroys
nothing**. Two kinds of file can be on disk after a failure, and they are
treated differently:

| On disk after a failed fetch | What happens |
|:--|:--|
| Existed beforehand (your work) | **Restored byte-for-byte** — a truncated or overwritten file is put back exactly as it was |
| Created by the failed attempt | **Kept where it is** — a partial scaffold is evidence about what went wrong and may be usable, so it is never thrown away |

- Owned files are **snapshotted before any write** and reconciled on failure.
- The archive fallback runs **only when it cannot destroy anything**: the slot
  is empty, or `--force` was given explicitly.
- A total failure reports **every reason**, and names anything it restored or
  kept.

```
✗ could not fetch problem 9999
      · LeetCode: Problem 9999 not found (no entry with frontend id 9999)
      · archive: no archive copy at 9999/
! partial files kept for inspection: 9999_driver.cpp
· none of your existing work was modified or deleted
```

**Verified** — driving the rollback against a realistic partial write (one file
clobbered, one truncated, one newly created): both pre-existing files came back
byte-for-byte and the new one was left in place. End to end, a hand-written
work-in-progress solution survived `new 9999 --force` with an identical md5
before and after, and `new 186` on an already-populated slot refuses to touch
it at all.

**Incidental findings**
- `debug.sh` compiles without `-std=`, so GCC defaults to `gnu++17`: any C++20
  solution that builds under `run.sh` fails under `debug.sh`. `compile_cpp`
  always passes `-std` explicitly.
- `sol_18` (a committed 45 KB binary) and `__pycache__/` were untracked by
  `.gitignore` — entries added.
- 4 archived solutions are empty stubs: `1114`, `189`, `237`, `3347`.
  `Code Dirs/448/` exists with no matching `All Codes/448.cpp`.

---

### Phase 3 — Providers and the Scorer (2026-09-10) ✅

Grading a submission, and saying whether a better approach exists.

| File | Role |
|:--|:--|
| `providers/base.py` | `Provider` contract, `NullProvider` |
| `providers/openai_compat.py` | Groq / Gemini / Cerebras / OpenRouter (one wire format) |
| `providers/ollama_p.py` | Fully local, no key |
| `providers/anthropic_p.py` | Paid; only used if a key is deliberately set |
| `providers/__init__.py` | Free-first auto-detection |
| `agents/scorer.py` | Rubric, head-to-head benchmark, better-approach verdict |
| `config.toml` | Provider choice, model ids, rubric weights |

**Decisions**

1. **The provider layer moved forward from Phase 4**, because the scorer needs it.
2. **Everything is free.** Auto-detection order is
   `groq → gemini → cerebras → openrouter → ollama → anthropic` — free hosted
   first, local second, paid strictly last. A machine with no key still runs;
   a machine with a free key never silently starts spending money.
3. **One OpenAI-compatible client covers four free tiers.** They share the
   `/chat/completions` shape, so Groq, Gemini, Cerebras and OpenRouter are one
   implementation plus a preset table. `urllib` is used, so nothing to install.
4. **Model ids are config, not code, and `provider models` asks the endpoint.**
   Free-tier catalogues churn; a model name hardcoded in source goes stale
   silently.
5. **Ollama defaults were re-sized to `qwen2.5-coder:3b` (~2 GB).** A 7B model
   needs ~4.5 GB and will not fit a 2 GB laptop GPU, so it would fall to CPU at
   a few tokens a second — minutes per generation, which the watch loop cannot
   absorb. 3B on CPU is workable.
6. **The scorer degrades rather than fabricating.** With no provider, the
   model-judged weight is redistributed onto the measured components and the
   card says why — it never invents a complexity grade.
7. **Efficiency is reported honestly.** The solution is compiled and benchmarked
   head-to-head against the archived reference on the same input, best-of-5. But
   the example tests are tiny: when both sides land under an 8 ms noise floor the
   card *says so* instead of pretending the difference is signal.

**Verified** — provider selection with no keys degrades to `NullProvider` and
every backend reports an actionable reason; scoring 2859 with no model yields
100/100 on the measured components with the model half explicitly marked
unavailable; the reference benchmark compiles and runs the archived solution
against the same driver.

**Defect found and fixed during testing** — the reference staging directory and
the output binary were both named `ref_<pid>`, so the linker tried to write its
output over its own staging directory. Efficiency silently reported "no
reference to compare against" for every problem. Renamed to `refstage_` /
`refbin_`.

#### Live integration against Groq's free tier

Wiring a real free key surfaced three things worth recording, all of which
would have silently degraded the system:

1. **Cloudflare rejects `Python-urllib`.** The `/models` call came back
   `HTTP 403, error code 1010` — a browser-signature ban, not an auth failure.
   Requests now send a real `User-Agent`, the same workaround `fetch_problem.py`
   already needed for LeetCode.
2. **The model ids in config were already retired.** `llama-3.3-70b-versatile`
   and `llama-3.1-8b-instant` no longer exist on Groq. This is exactly why
   `provider models` queries the endpoint instead of trusting hardcoded names —
   the catalogue is now `openai/gpt-oss-120b` (smart) and `openai/gpt-oss-20b`
   (fast), verified live on 2026-09-10.
3. **Reasoning models spend the completion budget before emitting content.**
   A `max_tokens=50` request returned an *empty string* having burned 93
   reasoning tokens. An agent would read that as a valid-but-useless answer.
   Three fixes: `reasoning_effort` is sent (`low` on Groq), a
   `MIN_REASONING_BUDGET` floor of 1500 tokens applies, and an empty response
   now raises `ProviderError` naming the reasoning-token spend rather than
   returning `""`.

**Scorer validated on both sides of the verdict** — a scorer that always says
"optimal" is worthless, so it was checked against a known-suboptimal solution:

| Solution | Score | Complexity | Verdict |
|:--|:--|:--|:--|
| 2859, optimal `bitset::count` | 98/100 **A** | 25/25 — O(n), optimal | "no better approach found" |
| Two Sum, brute-force O(n²) | 77/100 **C** | 5/25 — O(n²) vs optimal O(n) | "better solution exists — one-pass hash map, O(n)" |

**Cost so far: $0.**

---

### Phase 3.5 — Improver (2026-09-11) ✅

Unplanned, added on request: the scorer's verdict ("use a binary search
partition, O(log(min(m,n)))") named an approach but left the work undone.

| File | Role |
|:--|:--|
| `agents/improve.py` | Generate the suggested solution, verify it, install it |

**Decisions**

1. **Verify before overwriting.** The candidate is compiled and run against the
   real driver *first*; only a clean pass earns the right to touch `<id>.cpp`.
   Tested with a deliberately non-compiling suggestion: `installed: False`,
   solution byte-identical afterwards. A suggestion that fails stays in
   `data/improved/` and says so.
2. **The previous solution is always backed up** to
   `data/replaced/<id>_before_improve.cpp` before the write.
3. **The candidate never lands at the repo root.** `run.sh` picks its compile
   target with the glob `<id>_*.cpp` and takes the first sorted match, so a
   root-level `<id>_better.cpp` sorts *ahead of* `<id>_driver.cpp` and would
   make `./run.sh <id>` compile a file with no `main()`. It goes to
   `data/improved/` instead, and `ProblemPaths.compile_target()` now names the
   driver explicitly rather than trusting sort order. **`run.sh` still has this
   fragility** if any other `<id>_*.cpp` ever lands at root.
4. **The cached report and score are cleared after installing**, so a stale
   verdict cannot be shown against a file that just changed.

**Verified** end to end on problem 4: brute force 74/C → improver wrote a
commented binary-search partition, verified 2/2, installed it → re-score
94/A with complexity 25/25 and "no better approach found".

**A limit worth stating:** "verified" means *passes the example test cases* —
two of them for problem 4. For partition binary search that is weak; its real
failure modes are empty arrays and boundary partitions, which those cases never
touch. A stress-test generator would make the badge mean much more.

**Naming corrected** — the roster labelled agents `free` / `LLM`, implying the
model-backed ones cost money. On a free tier nothing here does. The tags are now
`offline` (needs no model at all) and `model` (needs a provider), with the
active provider shown alongside.

**Rate limits handled** — measured on Groq's free tier: 8,000 tokens/minute and
1,000 requests/day, against ~1,322 tokens per score (≈6 scores/minute). A 429
now degrades to "rate limit reached — retry in Ns" and the scorer falls back to
its measured half rather than failing the command.

---

### Phase 4 — DriverRepair, Solver, Debugger (2026-09-11) ✅

The agents that write C++. All three share one generate → verify → retry loop.

| File | Role |
|:--|:--|
| `agents/codegen.py` | Extract code from a reply, verify it in a scratch dir, retry on failure |
| `agents/driver_repair.py` | Fill the driver's `// TODO` scaffolding |
| `agents/solver.py` | Write the solution from the statement |
| `agents/debugger.py` | Patch a failing solution from the verifier's report |

**Decisions**

1. **One retry loop, shared.** Free-tier models are weaker at C++ than frontier
   ones, so a first attempt often does not compile — but the compiler error is
   an excellent correction signal. Each retry appends the previous attempt *and
   its failure output*, which converges far faster than restating the request.
   Capped at 3 attempts so a model that cannot converge fails fast instead of
   burning the token budget.
2. **Nothing is written until it passes.** Candidates are compiled and run in a
   scratch directory against the *real* counterpart file — a candidate driver is
   tested against the real solution and vice versa. The working tree is only
   touched after a clean run.
3. **`compile_only` for stub solutions.** DriverRepair usually runs while
   `<id>.cpp` is still an empty stub, where no output could match the expected
   file however good the driver is. The driver is then held only to compiling
   against the real type definitions. Without this the repair loop would retry
   a correct driver three times and give up.
4. **Solver refuses to overwrite your work** unless `--force`, and backs up
   first either way. The point of the repo is that you solve the problems.
5. **Debugger is the only cycle** in the system (Verifier ⇄ Debugger), capped,
   and it feeds back the actual failing case — input, expected, got.

**Verified** end to end on **133 Clone Graph**, chosen because its `Node*` type
is outside `fetch_problem.py`'s type table and so produces real TODOs:

| Step | Result |
|:--|:--|
| Fetch 133 | 2 TODOs: `// TODO: parse Node* node`, `// TODO: print result` |
| **DriverRepair** | wrote `buildGraph()` + `graphToString()`, compiles, 1 attempt |
| **Solver** | BFS + `unordered_map` clone — **3/3, 1 attempt** |
| **Debugger** | with `mp[cur]->neighbors.push_back(...)` disabled → 2/3 failing; diagnosed and fixed → **3/3, 1 attempt** |

Note the debugger's input: case 1 failed with `expected [[2,4],[1,3],[2,4],[1,3]]`
got `[[]]` — the clone had the right nodes and no edges. It identified the
missing neighbour link rather than rewriting the approach.

---

## Architecture

### Principle: two tiers, split by whether a model is needed

`Agent.requires_llm` is the field the whole design turns on. It splits the
roster into agents that always work — offline, free, no key — and agents that
need a configured provider. The master loop reads it to degrade gracefully
instead of failing when no provider is set up.

```
┌──────────────────────────────────────────────────────────────────────┐
│                   MASTER AGENT — runs until you stop it              │
│      REPL  ·  file watcher  ·  session state  ·  dispatch table      │
└───────────────────────────────┬──────────────────────────────────────┘
                                │  owns one Context (the blackboard)
        ┌───────────────────────┴────────────────────────┐
        │                                                │
   ═════╪══ TIER 1: no model ══════╗          ╔══════════╪══ TIER 2: model ══
        │                          ║          ║          │
   ┌────▼─────┐  ┌───────────┐  ┌──▼───────┐  ║  ┌───────▼──────┐  ┌────────┐
   │ Fetcher  │  │ Statement │  │ Verifier │  ║  │ DriverRepair │  │ Solver │
   └────┬─────┘  └─────┬─────┘  └────┬─────┘  ║  └──────┬───────┘  └───┬────┘
        │              │             │        ║         │              │
   ┌────▼─────┐  ┌─────▼─────┐  ┌────▼─────┐  ║  ┌──────▼───────┐  ┌───▼────┐
   │ Archiver │  │  Tracker  │  │  Scorer  │  ║  │   Debugger   │  │ Scorer │
   │          │  │           │  │(measured)│  ║  │              │  │(review)│
   └──────────┘  └───────────┘  └──────────┘  ║  └──────────────┘  └────────┘
                                              ║  ┌──────────────┐  ┌────────┐
        always available, offline, free       ║  │  Classifier  │  │ Notes  │
                                              ║  └──────────────┘  └────────┘
                                              ╚══ needs a Provider ══════════
```

### The blackboard

Agents never talk to each other. The master owns one `Context` per problem,
passes it down an explicit ordered pipeline, and each agent enriches it in
place. Ordering stays explicit, every run is reproducible, and there is no
model call spent on agents negotiating — the failure mode of chat-style
multi-agent designs.

```python
Context(pid, paths, problem, report, score, topic, history)
         │     │      │        │       │      │
         │     │      │        │       │      └─ Classifier → tracker topic
         │     │      │        │       └──────── Scorer     → score card
         │     │      │        └──────────────── Verifier   → TestReport
         │     │      └───────────────────────── Fetcher/Statement → metadata
         │     └──────────────────────────────── ProblemPaths (all file paths)
         └────────────────────────────────────── problem id
```

### Pipelines

```
new <id>    Fetcher ──► Statement                      (scaffold + question file)
run [id]    Verifier                                    (compile · run · diff)
watch       ┌─► poll mtime ─► debounce ─► Verifier ─┐   (until Ctrl-C)
            └───────────────────────────────────────┘
score       Verifier ─► Scorer ◄─ reference solution     [Phase 3]
solve <id>  Fetcher ─► DriverRepair ─► Solver ─► ⟲(Verifier ⇄ Debugger) [Phase 4]
archive     Classifier ─► Archiver ─► Tracker ─► Committer               [Phase 5]
```

The only cycle in the system is `Verifier ⇄ Debugger`, and it is retry-capped.

### Providers — free first

| Provider | Cost | Needs | Notes |
|:--|:--|:--|:--|
| **groq** | free | `GROQ_API_KEY` | fastest free tier; per-minute limits. **In use.** |
| **gemini** | free | `GEMINI_API_KEY` | generous daily limits |
| **cerebras** | free | `CEREBRAS_API_KEY` | free tier |
| **openrouter** | free | `OPENROUTER_API_KEY` | `:free` model ids |
| **ollama** | free | nothing | fully local and offline; needs a small model |
| **anthropic** | **paid** | `ANTHROPIC_API_KEY` | last resort, opt-in only |

Agents ask for a *tier* (`fast` / `smart`), never a model id, so switching
provider changes one config line. `provider` in the REPL shows what is usable;
`provider models` asks the active endpoint what it actually serves.

### Layout

```
lcagent/
├── __main__.py            entry: python -m lcagent
├── core/
│   ├── paths.py           repo root, data root, ProblemPaths
│   ├── compiler.py        g++ discovery, compile, PCH cache
│   ├── runner.py          execute with timeout
│   ├── testcase.py        verify() → TestReport
│   ├── leetcode.py        GraphQL + cache
│   ├── state.py           Context (blackboard)
│   └── ui.py              colour, Windows-safe
├── config.toml            provider, models, rubric weights
├── providers/
│   ├── base.py            Provider contract, NullProvider
│   ├── openai_compat.py   groq / gemini / cerebras / openrouter
│   ├── ollama_p.py        local, no key
│   └── anthropic_p.py     paid, opt-in
├── agents/
│   ├── base.py            Agent contract
│   ├── master.py          the loop
│   ├── codegen.py         generate → verify → retry, shared
│   ├── fetcher.py  statement.py  verifier.py  scorer.py  improve.py
│   ├── driver_repair.py  solver.py  debugger.py
│   └── (phases 5-6: classifier, archiver, tracker, notes, committer)
├── data/                  ← agent by-products only
│   ├── cache/             LeetCode responses (gitignored)
│   ├── scores/            score cards
│   ├── replaced/          solutions rescued before a problem swap
│   ├── logs/              session logs (gitignored)
│   └── session.json       resume state (gitignored)
└── README.md
```

### Cross-platform contract

| Concern | How it is handled |
|:--|:--|
| No bash on Windows | `run.sh` logic ported to Python; `.sh` scripts left for manual use |
| Compiler location | `shutil.which`, then MSYS2 / TDM-GCC / WinLibs paths, then `CXX` |
| `bits/stdc++.h` | MinGW-w64 required; MSVC explicitly unsupported |
| Executable suffix | `paths.EXE_SUFFIX` |
| Paths with spaces | `pathlib` throughout; no string concatenation |
| Process timeout | `subprocess(timeout=)`, never `signal.alarm` |
| ANSI colour | Opt-in `SetConsoleMode` on Windows; auto-off when piped |
| Interpreter name | `sys.executable`, never a literal `python3` |
| Line endings | `lc.bat` written CRLF, `lc` written LF |

### Requirements traceability

| Your requirement | Where it lands |
|:--|:--|
| 1. Text file with question, constraints, test cases + results | `agents/statement.py` → `<id>_problem.txt` at the repo root, written at fetch time ✅ |
| 2. Score my submission, suggest a better solution | `agents/scorer.py` ✅ (measured half works with no key; verdict needs a free key) |
| 3. One master agent looping until stopped | `agents/master.py` — REPL + watcher ✅ |
| 4. Runs from the command prompt | `python -m lcagent`, `lc.bat`, `lc` ✅ |
| 5. Windows and Linux | Cross-platform contract above ✅ |
| *(added)* Must cost nothing to run | Free-first provider order; deterministic agents need no model at all ✅ |
