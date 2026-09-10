# lcagent — LeetCode Practice Multi-Agent System

A command-line **multi-agent system** for this practice repo. One master agent
runs in a loop and dispatches to 14 specialists that fetch problems from
LeetCode, render readable question files, repair drivers, write and debug
solutions, verify them against the real test cases, score them, suggest and
install better approaches, archive the result, update `LC Tracker.xlsx`, append
to your notes files, and commit.

**Runs on Windows and Linux.** **Free end to end** — no subscription, no paid
API. Ten of the fifteen agents are deterministic Python that need no model at
all; the other five run on a free tier (Groq, Gemini, Cerebras, OpenRouter) or a
fully local Ollama model.

```
                      ┌──────────────────────────┐
   you  ──────────────►      MasterAgent         ├──────────► menu / REPL
                      │  owns one Context        │
                      └────────────┬─────────────┘
                                   │  hands the Context down ordered pipelines
   ┌───────────────┬───────────────┼───────────────┬────────────────┐
   ▼               ▼               ▼               ▼                ▼
 PROBLEM         SOLVE          REVIEW          FINISH           SESSION
 fetcher       driver-repair    scorer         classifier        reporter
 statement     solver           improver       archiver          master
 verifier      debugger         notes          tracker
                                               committer
```

---

## Contents

| | |
|:--|:--|
| [1. Install and run](#1-install-and-run) | setup script, Windows + Linux, first session |
| [2. Requirements](#2-requirements) | what must be present, and what is optional |
| [3. The menu](#3-the-menu) | every command, key and alias |
| [4. Architecture](#4-architecture) | the two tiers, the blackboard, the pipelines |
| [5. The agents](#5-the-agents) | all fifteen, with inputs, outputs and failure modes |
| [6. Files and data](#6-files-and-data) | what is written where, and what is safe to delete |
| [7. Providers and cost](#7-providers-and-cost) | free tiers, limits, and how to add a key |
| [8. Cross-platform](#8-cross-platform) | what was designed for Windows, and what is untested |
| [9. Troubleshooting](#9-troubleshooting) | the errors you are most likely to hit |
| [10. Development log](#10-development-log) | phase by phase, with the reasoning |
| [11. Known gaps](#11-known-gaps) | what is not solved |

---

## 1. Install and run

### 1.1 One command

The setup script checks everything, installs what is missing, and tells you the
exact command for anything it cannot install itself. **It never changes anything
without asking**, and `--check` changes nothing at all.

**Windows** — double-click `setup.bat`, or from `cmd.exe` / PowerShell:

```bat
cd "path\to\Leetcode-Practice"
setup.bat                :: install what is missing, ask before each step
setup.bat --check        :: diagnose only, change nothing
setup.bat --yes          :: install everything, ask nothing
```

**Linux / macOS** — from any shell:

```bash
cd "path/to/Leetcode-Practice"
./setup.sh               # install what is missing, ask before each step
./setup.sh --check       # diagnose only, change nothing
./setup.sh --yes         # install everything, ask nothing
```

Already have Python? These are equivalent and work identically on both systems:

```bash
python -m lcagent setup       # same as setup.sh / setup.bat
python -m lcagent doctor      # same as --check
```

### 1.2 What setup actually does

| Step | Checks | Fixes automatically |
|:--|:--|:--|
| **1. Python** | 3.11+ (needed for `tomllib`) | no — prints the install command |
| **2. C++ compiler** | `g++` on PATH, MSYS2/MinGW/TDM paths, `$CXX`; then **compiles a real `<bits/stdc++.h>` program** | Linux: apt/dnf/pacman/zypper/apk · Windows: winget → MSYS2 → pacman · macOS: brew |
| **3. openpyxl** | importable | yes — `pip install`, falling back to `--break-system-packages` then `--user` |
| **4. Launchers** | `lc` and `lc.bat` exist with the **right line endings** | yes — rewrites them, `chmod +x` on POSIX |
| **5. Optional** | `git`, a model provider key, `ollama` | no — prints exactly how to set a key |

The compiler step deliberately does more than `which g++`: it compiles a program
that includes `<bits/stdc++.h>`, because that header is a libstdc++ extension.
A machine can have a perfectly good compiler and still be unable to build a
single solution in this repo — Apple clang and MSVC both fail that test.

Sample output:

```
  lcagent setup — Linux 7.0.0-31-generic (checking only, nothing will be changed)

1. Python
─────────
[  ok  ] Python 3.14.4
         /usr/bin/python3

2. C++ compiler
───────────────
[  ok  ] found g++
         /usr/bin/g++
         g++ (Ubuntu 15.2.0-16ubuntu1) 15.2.0
[  ok  ] <bits/stdc++.h> compiles

Summary
───────
[  ok  ] Python          3.14.4
[  ok  ] C++ compiler    g++ 15.2.0
[  ok  ] openpyxl        3.1.5
[  ok  ] Launchers       lc + lc.bat
[ warn ] Model provider  offline agents still work

  Ready. Start the system with:
     ./lc        or   python -m lcagent
```

### 1.3 Running it

Four equivalent ways to start the loop:

```bash
./lc                          # Linux / macOS
lc.bat                        # Windows
python -m lcagent             # either — works from the repo root
python lcagent/__main__.py    # either — no package import needed
```

One-shot mode takes the same commands, prints the same output, and returns a
**real exit code** (0 = tests passed, 1 = failed), so it scripts and works in CI:

```bash
python -m lcagent new 2859        # fetch and scaffold problem 2859
python -m lcagent run             # compile, run the tests, exit 0/1
python -m lcagent score 4         # grade problem 4
python -m lcagent report          # progress across the whole tracker
python -m lcagent finish --commit # classify, archive, track, commit
```

### 1.4 A first session, end to end

```
$ ./lc

  lcagent  LeetCode practice multi-agent system
  repo: /home/shikhar/Sem 2/Coding Practice/Leetcode-Practice

┌────────────────────────────────────────────────────────────┐
│ lcagent · no problem                                  groq │
└────────────────────────────────────────────────────────────┘
  PROBLEM
   1  New problem     fetch, scaffold, write the question file
   2  Show question   statement, constraints, test cases
   3  Repair driver   fill the driver's TODO scaffolding
  SOLVE
   4  Run tests       compile, run, per-case results
   5  Watch           auto test + score on every save
   6  Solve for me    write the solution from the statement
   7  Fix failures    debug until the failing cases pass
  REVIEW
   8  Score           grade + better-approach check
   9  Better code     verify the suggestion, then write it in
  FINISH
   f  Finish          classify, archive, update the tracker
   l  Notes           add the reusable trick to your notes
  SESSION
   s  Status          what is loaded, which files exist
   g  Progress        solved counts, thin topics, ⭐ queue
   a  Agents          the agent roster
   p  Providers       model backends, and which are usable
   h  Help            every command and alias
   0  Quit            save the session and exit

  choose or type a command > 1
         problem id > 2859

· fetching 2859 ...
✓ scaffolded 2859: solution, driver, input, expected
✓ wrote 2859_problem.txt
· statement: 2859_problem.txt
· edit 2859.cpp, then `run` (or `watch`)

  choose or type a command > 5          ← watch: retests on every save
· watching 2859.cpp — Ctrl-C to stop
Test 1: PASS  (output: 1)
Test 2: PASS  (output: 8)
Result: 2 / 2 passed  (4 ms)

  choose or type a command > 8          ← score
score — problem 2859
  94/100   grade A
  correctness  ██████████████████  50.0/50.0  2/2 test cases
  complexity   ██████████████████  25.0/25.0  O(n) time, O(1) space

  choose or type a command > f          ← finish
✓ topic: Bit_man
✓ archived 5 files to Code Dirs/ and All Codes/
✓ tracker I860 — marked solved, topic → Bit_man
     backup: lcagent/data/tracker_backups/LC Tracker 2026-09-11_014233.xlsx
```

Bare **Enter** redisplays the menu. The header shows the loaded problem and
whether a model provider is live. The session is saved to
`lcagent/data/session.json`, so restarting resumes on the same problem.

---

## 2. Requirements

| | Needed for | Version | Absent? |
|:--|:--|:--|:--|
| **Python** | everything | **3.11+** (`tomllib`) | hard stop |
| **g++ / MinGW-w64** | compiling and running tests | any with `<bits/stdc++.h>` | no testing, scoring, solving or archiving |
| **openpyxl** | `finish`, `report` | any | those two commands report how to install it; everything else works |
| **git** | `finish --commit` | any | only committing is unavailable |
| **A provider key** | 5 of 15 agents | free tier | the other 10 agents work normally |

**MSVC will not work.** The solutions in this repo `#include <bits/stdc++.h>`,
which is a libstdc++ extension. On Windows the requirement is MinGW-w64 (MSYS2,
WinLibs or TDM-GCC), not the Visual Studio toolchain.

---

## 3. The menu

Every key maps to an existing command, so typing `4` and typing `run` go down
exactly the same path — the menu is a front end, never a second implementation.

| Key | Command | Aliases | What it does |
|:--:|:--|:--|:--|
| `1` | `new <id>` | `n` | fetch, scaffold, write `<id>_problem.txt` |
| `2` | `show` | `problem` | print the statement, constraints and test cases |
| `3` | `repair` | `driver` | fill the driver's `// TODO` scaffolding, then retest |
| `4` | `run [id]` | `r`, `test`, `t` | compile, run, per-case results |
| `5` | `watch` | `w` | retest and score on every save, until Ctrl-C |
| `6` | `solve` | | write the solution from the statement |
| `7` | `fix` | `debug` | patch the solution until the failing cases pass |
| `8` | `score` | `sc`, `grade` | grade it, and say whether a better approach exists |
| `9` | `better` | `improve`, `b` | verify that better solution, then write it into `<id>.cpp` |
| `f` | `finish` | `archive` | classify, archive, update the tracker |
| `l` | `notes` | `note` | append a reusable technique to your notes files |
| `s` | `status` | `st` | what is loaded, which files exist |
| `g` | `report` | `progress`, `stats` | solved counts, thin topics, ⭐ queue, unsolved runs |
| `a` | `roster` | `agents` | the agent roster and which need a model |
| `p` | `provider` | `providers` | model backends, and which are usable |
| `h` | `help` | `?` | every command and alias |
| `0` | `quit` | `q`, `exit` | save the session and exit |

**Flags**

```
new <id> --live        fetch from LeetCode only, never fall back to the archive
         --offline     use the local archive only, no network
         --force       refetch even if files already exist
solve    --force       overwrite a solution that already has real work in it
finish   --commit      also commit as the next U<n>
         -m "msg"      use your own commit message
         --overwrite   replace an existing archive entry / tracker topic
notes    ds|formula|algo   restrict which notes file may be written
         --dry-run     show the entry without writing it
         --force       add it even if it looks like a duplicate
```
---

## 4. Architecture

### 4.1 The organising principle: two tiers

`Agent.requires_llm` is the single field the whole design turns on. It splits
the roster into agents that always work — offline, free, no key — and agents
that need a configured provider. The master reads it to degrade gracefully
instead of failing.

```
                        Agent (ABC)
                   name · role · requires_llm
                        run(ctx) → AgentResult
                              │
              ┌───────────────┴────────────────┐
              ▼                                ▼
     requires_llm = False               requires_llm = True
     ── 10 agents ──                    ── 5 agents ──
     fetcher    archiver                driver-repair
     statement  tracker                 solver
     verifier   committer               debugger
     scorer     reporter                improver
     classifier master                  notes
              │                                │
     always available              needs GROQ_API_KEY or similar
     no key, no network*           free tier is sufficient
```

\* except `fetcher`, which needs the network unless the problem is cached or in
the local archive.

This is why the system is genuinely usable with no key at all: fetching,
rendering the question, compiling, running tests, scoring, archiving, updating
the tracker, reporting progress and committing are **all** in the offline tier.

### 4.2 The blackboard

Agents never talk to each other. The master owns one `Context` per problem,
passes it down an explicit ordered pipeline, and each agent enriches it in
place. Ordering stays explicit, every run is reproducible, and no model call is
ever spent on agents negotiating with each other — the characteristic failure
of chat-style multi-agent designs.

```
                         ┌─────────────────────────┐
                         │        Context          │   ← the blackboard
                         ├─────────────────────────┤
   Fetcher    ─ writes → │ pid      problem id     │
   Statement  ─ writes → │ problem  LeetCode meta  │ → read by Scorer, Solver,
   (paths)              →│ paths    every filename │   Classifier, Notes
   Verifier   ─ writes → │ report   TestReport     │ → read by Scorer, Debugger,
   Scorer     ─ writes → │ score    score card     │   Archiver, Tracker
   Classifier ─ writes → │ topic    tracker topic  │ → read by Tracker
   every agent────────── │ history  audit trail    │ → shown by `status`
                         └─────────────────────────┘
```

Because every agent takes the same `Context` and returns the same
`AgentResult`, the master's dispatch does not care which agent it is calling,
and a new agent is one file plus one line in the roster.

```python
@dataclass
class AgentResult:
    agent: str          # who produced this
    ok: bool            # did the job succeed
    message: str        # one line, shown to the user
    data: dict          # structured detail for the caller
    artifacts: list     # files written, for the caller to report
```

### 4.3 Pipelines

Each command is one fixed, ordered pipeline. There is no planner and no
negotiation — the sequence is code, which is why every run is reproducible.

```
new <id>    Fetcher ──► Statement                      scaffold + question file
run [id]    Verifier                                    compile · run · diff
watch       ┌─► poll mtime ─► debounce ─► Verifier ─┐   until Ctrl-C
            └───────────────────────────────────────┘
repair      DriverRepair ──► Verifier                   fill the TODO scaffolding
solve       Fetcher ─► DriverRepair ─► Solver ─► ⟲(Verifier ⇄ Debugger)
score       Verifier ──► Scorer ◄── reference solution from the archive
better      Scorer ─► Improver ─► Verifier ─► install (only if it passes)
finish      Classifier ─► Archiver ─► Tracker ─► Committer
notes       Notes ─► duplicate check ─► backup ─► append
report      Reporter ◄── LC Tracker.xlsx  (read-only, one streaming pass)
```

**The only cycle in the entire system is `Verifier ⇄ Debugger`, and it is
retry-capped at 3.** Everything else is a straight line. That is a deliberate
constraint: a system whose control flow is acyclic can be reasoned about, and
its cost has an upper bound you can state.

### 4.4 The generate → verify → retry loop

The three model-backed code agents (`driver-repair`, `solver`, `debugger`)
share one mechanism in `agents/codegen.py`. A model proposes code; a
**deterministic** verifier compiles and runs it; on failure the exact error is
fed back into the next attempt.

```
   ┌──────────┐   code    ┌───────────┐   pass   ┌──────────┐
   │  model   ├──────────►│ compile + ├─────────►│ install  │
   │ proposes │           │ run tests │          │  it      │
   └────▲─────┘           └─────┬─────┘          └──────────┘
        │                       │ fail
        │  previous attempt +   │
        │  exact compiler /     ▼
        │  test failure    ┌──────────┐   3 attempts
        └──────────────────┤  retry   ├──────────────► give up, report why
                           └──────────┘
```

This is the most important reliability pattern in the system: **the judge is
deterministic**. The model is allowed to be wrong, because nothing it produces
is accepted until `g++` and the real test cases agree. That is what makes a
free, small model usable for code generation here.

### 4.5 Directory layout

```
lcagent/
├── __main__.py            entry: python -m lcagent [command | setup | doctor]
├── bootstrap.py           the setup script — checks and installs prerequisites
├── config.toml            provider order, model tiers, rubric weights
├── core/                  ── no agent logic, all reusable ──
│   ├── paths.py           repo-root discovery, data root, ProblemPaths
│   ├── compiler.py        g++ discovery (PATH → MinGW hints → $CXX), PCH cache
│   ├── runner.py          run a binary with a timeout, capture stdout/stderr
│   ├── testcase.py        verify() → TestReport, per-case diffing
│   ├── leetcode.py        GraphQL client + on-disk cache
│   ├── state.py           Context — the blackboard
│   ├── tracker_io.py      LC Tracker.xlsx read/write, backups, stats
│   ├── notes_io.py        append to the three notes files, in their own formats
│   └── ui.py              colour, Windows-safe, auto-off when piped
├── providers/             ── model backends, free first ──
│   ├── base.py            Provider contract, Completion, NullProvider
│   ├── openai_compat.py   groq / gemini / cerebras / openrouter
│   ├── ollama_p.py        local, no key
│   └── anthropic_p.py     paid, opt-in only
├── agents/                ── one file per agent ──
│   ├── base.py            Agent ABC + AgentResult
│   ├── master.py          the loop, the menu, dispatch, the watcher
│   ├── codegen.py         generate → verify → retry, shared by three agents
│   ├── fetcher.py  statement.py  verifier.py  scorer.py  improve.py
│   ├── driver_repair.py  solver.py  debugger.py
│   ├── classifier.py  archiver.py  tracker.py  committer.py
│   └── notes.py  reporter.py
├── data/                  ── agent by-products only, never your work ──
│   ├── cache/             LeetCode responses          (gitignored)
│   ├── problems/          rendered statements
│   ├── scores/            score cards
│   ├── improved/          candidate better solutions
│   ├── replaced/          solutions rescued before a swap
│   ├── tracker_backups/   pre-write copies of the sheet (gitignored)
│   ├── notes_backups/     pre-write copies of the notes (gitignored)
│   ├── logs/              session logs               (gitignored)
│   └── session.json       resume state               (gitignored)
└── README.md
```

The `core/` ⁄ `agents/` split is enforced: **nothing in `core/` imports an
agent**, so every primitive is testable on its own and an agent is only
orchestration plus a prompt.

---

## 5. The agents

Fifteen agents. `offline` needs no model provider at all; `model` needs one.

### 5.1 Offline tier — always available

| Agent | Role | Reads | Writes | Fails when |
|:--|:--|:--|:--|:--|
| **master** | owns the session loop, the menu and dispatch | `session.json` | `session.json` | never — it is the loop |
| **fetcher** | fetch a problem and scaffold its files | LeetCode API, cache, archive | `<id>.cpp`, `_driver.cpp`, `_input.txt`, `_expected.txt` | network down **and** not cached or archived |
| **statement** | render the question, constraints and test cases | `ctx.problem` | `<id>_problem.txt` at the **repo root** | the problem is premium (empty content) |
| **verifier** | compile the driver, run the cases, diff per case | the four scaffold files | `ctx.report` | no compiler; missing files |
| **scorer** | grade the solution, say if a better approach exists | code, `ctx.report`, archive reference | `ctx.score`, `data/scores/<id>_score.json` | never — degrades to the measured half with no model |
| **classifier** | pick the tracker topic from the sheet's own vocabulary | `LC Tracker.xlsx`, LeetCode tags | `ctx.topic` | no tags **and** no model |
| **archiver** | copy the solved problem into the two archives | the scaffold files | `Code Dirs/<id>/`, `All Codes/<id>.cpp` | tests are not passing |
| **tracker** | mark solved and record the topic | `LC Tracker.xlsx` | the sheet + a timestamped backup | `openpyxl` missing; file open in Excel |
| **committer** | stage and commit as the next `U<n>` | `git log` | a commit | not a git repo; nothing staged |
| **reporter** | progress: blocks, topics, ⭐ queue, unsolved runs | `LC Tracker.xlsx` (read-only) | nothing | `openpyxl` missing |

### 5.2 Model tier — needs a provider

| Agent | Role | Verified by | Retries | Refuses to |
|:--|:--|:--|:--|:--|
| **driver-repair** | fill the driver's `// TODO` scaffolding | compile (solution may be a stub) | 3 | — |
| **solver** | write the solution from the statement | compile + run the real tests | 3 | overwrite real work without `--force` |
| **debugger** | patch a failing solution using the exact failures | compile + run | 3 | — |
| **improver** | write and verify the better solution the scorer named | compile + run | 3 | install anything that does not pass |
| **notes** | append a genuinely new technique to your notes files | duplicate check + backup | 1 | write a near-duplicate without `--force` |

Every model-tier agent is gated by a **deterministic** check. Nothing a model
writes reaches your files until `g++` and the test cases agree — which is why a
free model is good enough here.

### 5.3 Adding an agent

Three steps, no framework:

```python
# 1. lcagent/agents/mine.py
from .base import Agent, AgentResult
from ..core.state import Context

class MyAgent(Agent):
    name = "mine"
    role = "One line — this shows up in the roster"
    requires_llm = False

    def run(self, ctx: Context, **kwargs) -> AgentResult:
        if not ctx.paths.solution.is_file():
            return self.fail("no solution to work on")
        return self.ok("did the thing", detail=42, artifacts=[ctx.paths.solution])

# 2. in master.py: import it, construct it in __init__, add cmd_mine
# 3. add a row to MENU and an entry to _ALIASES
```
---

## 6. Files and data

### 6.1 What lands where

```
Leetcode-Practice/
├── 2859.cpp                 ← your solution — the only file you edit
├── 2859_driver.cpp          ← generated: reads input, calls Solution, prints
├── 2859_input.txt           ← the example test cases
├── 2859_expected.txt        ← the expected outputs
├── 2859_problem.txt         ← the question, constraints and cases  ← at the ROOT
├── lc  lc.bat               ← launchers
├── setup.sh  setup.bat      ← environment setup
├── LC Tracker.xlsx          ← your sheet — only ever appended to, always backed up
├── All Codes/               ← your archive and notes — the system appends, never rewrites
└── lcagent/data/            ← everything the agents produce
```

Only **five files** ever sit at the repo root for a problem, and a new `new <id>`
clears the previous problem's files before scaffolding the next — matching the
`rename.sh` workflow this replaced. Anything not yet archived is rescued to
`lcagent/data/replaced/` first, never deleted.

### 6.2 Safe to delete

| Path | Regenerates? | Cost of deleting |
|:--|:--|:--|
| `lcagent/data/cache/` | yes, on next fetch | one API call per problem |
| `lcagent/data/logs/` | yes | nothing |
| `lcagent/data/session.json` | yes | you start with no problem loaded |
| `lcagent/data/problems/` | yes, `fetch` re-renders | nothing |
| `lcagent/data/scores/` | yes, `score` recomputes | `report`'s recent-scores list |
| `lcagent/data/*_backups/` | **no** | your undo history for the sheet and notes |
| `lcagent/data/replaced/` | **no** | rescued solutions that were never archived |

### 6.3 The write-safety rules

Three rules the system never breaks, because these files are months of your work:

1. **Every write to `LC Tracker.xlsx` or a notes file is preceded by a
   timestamped backup.** No exceptions, not even when the write turns out to be
   a no-op.
2. **Existing annotation is never destroyed.** A ⭐ is never overwritten with a
   ✅ — it is your mark and carries meaning the system does not know. An
   existing topic is kept unless `--overwrite` is passed.
3. **A failed fetch modifies nothing and deletes nothing.** The fetcher
   snapshots every file it is about to own, and on failure restores
   pre-existing files byte-for-byte while *keeping* the partial files from the
   failed attempt for inspection. It then reports exactly which is which.

---

## 7. Providers and cost

| Provider | Cost | Needs | Notes |
|:--|:--|:--|:--|
| **groq** | free | `GROQ_API_KEY` | fastest free tier; per-minute token limits. **In use.** |
| **gemini** | free | `GEMINI_API_KEY` | generous daily limits |
| **cerebras** | free | `CEREBRAS_API_KEY` | free tier |
| **openrouter** | free | `OPENROUTER_API_KEY` | `:free` model ids |
| **ollama** | free | nothing | fully local and offline; needs a small model pulled |
| **anthropic** | **paid** | `ANTHROPIC_API_KEY` | last in the order, opt-in only |

`provider = "auto"` walks that list and takes the first usable one, so a
machine with a free key never silently starts spending money. Agents ask for a
**tier** (`fast` / `smart`), never a model id, so switching provider is one line
in `config.toml`.

**Setting a key**

```bash
# Linux / macOS — then reopen the terminal
echo 'export GROQ_API_KEY="gsk_..."' >> ~/.bashrc

# Windows — then reopen cmd.exe
setx GROQ_API_KEY "gsk_..."
```

Get a free Groq key at <https://console.groq.com> — no card required.

**Measured free-tier limits** (Groq, `openai/gpt-oss-120b`): 8,000 tokens/minute
and 1,000 requests/day. A score costs about 1,322 tokens, so roughly **6 scores
per minute** and far more per day than a practice session needs.

```
p            which providers are usable, free ones first
provider models    ask the live endpoint what it actually serves
```

---

## 8. Cross-platform

> **Status: written for Windows, exercised only on Linux.** Every row below is
> a deliberate choice made to avoid a known Windows failure, and none of it has
> been executed on Windows — there is no Windows machine in this setup. Treat
> the table as *the traps that were designed around*, not as a test result.
> `setup.bat --check` is the fastest way to find out, and the most likely first
> failure is the compiler hunt in `core/compiler.py`.

| Concern | How it is handled |
|:--|:--|
| Third-party packages | exactly one, `openpyxl`, and only for the tracker |
| No bash on Windows | `run.sh` logic ported to Python; `.sh` scripts left for manual use |
| Compiler location | `shutil.which`, then MSYS2 / TDM-GCC / WinLibs paths, then `$CXX` |
| `bits/stdc++.h` | MinGW-w64 required; **MSVC explicitly unsupported** |
| Executable suffix | `paths.EXE_SUFFIX` |
| Paths with spaces | `pathlib` throughout; no string concatenation |
| Process timeout | `subprocess(timeout=)`, never `signal.alarm` |
| ANSI colour | opt-in `SetConsoleMode` on Windows; auto-off when piped |
| Interpreter name | `sys.executable`, never a literal `python3` |
| Line endings | `lc.bat` and `setup.bat` written CRLF, `lc` and `setup.sh` written LF |
| Build artefacts | compiled to a temp dir, never the repo root |

---

## 9. Troubleshooting

| Symptom | Cause | Fix |
|:--|:--|:--|
| `No C++ compiler found` | g++ not on PATH | `setup.sh` / `setup.bat`, or set `CXX=/path/to/g++` |
| `bits/stdc++.h: No such file` | clang or MSVC, not libstdc++ | install MinGW-w64 (Windows) or `brew install gcc` (macOS) |
| `reading LC Tracker.xlsx needs openpyxl` | the one dependency is missing | `python -m pip install openpyxl` |
| `could not write the tracker … is it open in Excel?` | the file is locked | close it in Excel/LibreOffice and retry |
| `needs a model provider` | no key set | set `GROQ_API_KEY` (§7), or use the 10 offline agents |
| Fetch fails with HTTP 403 | Cloudflare | already handled with a browser User-Agent; retry, or use `--offline` |
| A problem fetches with empty content | it is **premium** | 186 of ~3,400 are; set `LEETCODE_SESSION` to your own cookie |
| `Tags: —` in the question file | LeetCode returns no tags for very new problems | cosmetic; the classifier falls back to the model |
| `./lc: bad interpreter` | CRLF line endings on `lc` | `./setup.sh` rewrites it with LF |
| Tests pass but `finish` refuses | `ctx.report` is stale | run `4` again, then `f` |
| Menu boxes look broken | terminal is not UTF-8 | `chcp 65001` on Windows, or set `NO_COLOR=1` |

**Diagnose everything at once:** `python -m lcagent doctor`

---

## 10. Development log

Built in seven phases, each one landing a working subset. Every phase below
records what was built, the decisions taken, and the bugs found in testing —
including the ones that were embarrassing.

| Phase | Scope | Needs a model | Status |
|:--|:--|:--:|:--|
| **0** | `core/` — paths, compiler discovery, run, per-case diff | no | ✅ done |
| **1** | Statement agent → `<id>_problem.txt` | no | ✅ done |
| **2** | Fetcher + Verifier, Master loop (REPL + watcher) | no | ✅ done |
| **3** | Providers (free-first) + Scorer — rubric, benchmark, reference diff | partial | ✅ done |
| **3.5** | Improver — write, verify and install the better solution | yes | ✅ done |
| **4** | DriverRepair / Solver / Debugger | yes | ✅ done |
| **5** | Archiver + Tracker + Classifier + Committer | no | ✅ done |
| **6** | Notes agent + Reporter | partial | ✅ done |
| **&mdash;** | `bootstrap.py` + `setup.sh` / `setup.bat` | no | ✅ done |

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

### Phase 5 — Classifier, Archiver, Tracker, Committer (2026-09-11) ✅

Closing the loop: a solved problem gets classified, archived, recorded and
committed. One command — `finish`.

| File | Role |
|:--|:--|
| `core/tracker_io.py` | Read/write `LC Tracker.xlsx`, backups, stats |
| `agents/classifier.py` | Pick the topic from the sheet's own vocabulary |
| `agents/archiver.py` | Copy into `Code Dirs/` and `All Codes/` |
| `agents/tracker.py` | Mark solved + record the topic |
| `agents/committer.py` | Commit as the next `U<n>` |

**The sheet's layout**, established by inspection and verified against known
rows: five side-by-side blocks of 1000, starting at columns **A, E, I, M, Q**;
within a block the columns are *number, mark, mark, topic*; the row is
`id % 1000 + 1`. Checked against 2859 → row 860 block I-L, and 4 → row 5 block
A-D. The number column is a text label in block 1, a formula (`=A5 +1000`) in
blocks 2-4 and a plain integer in block 5 — it is never written to.

**Decisions**

1. **Every tracker write is preceded by a timestamped backup**, no exceptions.
   The sheet is months of work and the only record of what has been solved.
   Confirmed safe to round-trip first: the file has no charts, images,
   conditional formatting, merged cells or defined names, so openpyxl cannot
   silently drop anything.
2. **Existing annotation is never destroyed.** A ⭐ is never overwritten with
   ✅ — it is the user's own mark and carries meaning this system does not know
   — and an existing topic is kept unless `--overwrite` is passed.
3. **The classifier picks from the sheet's vocabulary**, not free text. There
   are already 95 distinct topics with a 59-item long tail of one-offs; a model
   inventing another spelling of "Binary Search" would make the column useless
   for reporting. It falls back to the LeetCode tag when no model is available.
4. **Archiving and tracking are gated on passing tests.** The archive doubles
   as the scorer's reference corpus, so a broken solution in it poisons future
   comparisons.
5. **Committing is opt-in.** `finish` shows the message it *would* use;
   `finish --commit` actually commits, `-m` overrides the message.

**Three bugs found and fixed during testing**

- **`ok()` kwarg collision.** `CommitterAgent` passed `message=msg` into
  `**data`, colliding with `Agent.ok(message, **data)` — a `TypeError` that only
  fired on the dry-run path. An audit of every `self.ok(...)` call found no
  others.
- **A quadratic tracker read.** `stats()` used `ws.cell(r, c)` on a
  `read_only=True` worksheet. Those stream rows, so random access rescans from
  the top every call — the first run hung past 120 s. Rewritten as one
  `iter_rows` pass: **190 ms**.
- **`_next_number` produced duplicates.** It scanned only the last 200 commits,
  but `U15`–`U17` exist further back, and the history reuses numbers heavily
  (21 commits titled `U11`, spread over a week). Taking the global maximum gave
  `U18`, which is arithmetically right and wrong for this convention; it now
  derives from the *most recent* U commit, giving `U15` after `U14`.

**A design gap fixed too:** the archiver refused any problem that was partly
archived. But the bulk import left entries with one side missing — `Code Dirs/448`
has no `All Codes/448.cpp`, and problem 4 was the reverse. A half-present
archive is a gap to fill, not a reason to refuse; it now reports "completed".

**Verified** on problem 4: classifier chose `Binary_Search` (matching what was
already in the sheet), archiver **completed** the partial entry with 5 files,
tracker reported `A5 — already up to date` and still took a backup. The write
path was then proven on a genuinely unmarked problem (3600): both marks set to
✅ and topic written, then restored byte-for-byte from the backup.

### Phase 6 — Notes and reporting (2026-09-11) ✅

The last phase, and the only one that writes into files the system did not
create. Two agents that answer "what did I learn?" and "where am I?".

| File | Role |
|:--|:--|
| `core/notes_io.py` | Append to the three notes files, each in its own format |
| `agents/notes.py` | Decide whether a problem taught anything worth keeping |
| `agents/reporter.py` | Progress across the tracker: blocks, topics, ⭐, gaps |

**The three notes formats**, taken from the files as they stand — no format was
invented, and each one is written back the way the file already does it:

| File | Entry | Separator | Where a new entry goes |
|:--|:--|:--|:--|
| `Notes/imp DS.txt` | `51. std::nth_element — ...` | `─` × 62 | appended at the end |
| `Math formula/formula.txt` | `[17] Digital Root (LC 258)` | `-` × 40 | **above** the trailing `=` × 40 footer |
| `Notes/algo_name.txt` | `16. Mo's algorithm - ...` | none | **after item 15**, above the loose notes below |

Two of the three are insertions, not appends — writing to the end of
`formula.txt` would land below its footer, and the end of `algo_name.txt` is
unrelated loose text, not the algorithm list.

**Decisions**

1. **`NONE` is the expected answer.** The three files hold 50, 16 and 15
   entries across ~935 solved problems — about one note per twenty problems.
   An agent that appends after every problem would bury the signal within a
   month, so the model is told most problems deserve nothing, and the prompt
   lists the techniques that are never worth an entry.
2. **Naming a file does not force an entry.** `notes ds` restricts *which*
   file may be written, not *whether* one is. The first version said "you MUST
   produce an entry" and the model duly invented one — for problem 4 it wrote
   up the naive merge-and-sort it had rejected, and then advised against using
   it. An invented note is worse than no note.
3. **Duplicates are blocked before the write**, on three checks: the problem is
   already cited, the title matches, or the titles share ≥60% of their
   meaningful words. `--force` overrides. Near-duplicates in a hand-curated
   file are worse than a missed entry, so the check errs toward refusing.
4. **The file is copied to `data/notes_backups/` before every write** — the
   same rule as the tracker, for the same reason.
5. **Prose is reflowed; code is never touched.** Indentation is the signal: a
   line the model indented is code and passes through byte-for-byte, anything
   at column 0 is prose and gets reflowed to the files' own 74-column style.
   The first version wrapped line by line and left orphan fragments
   ("temporary copy," alone on a line), because the model brings its own line
   breaks at whatever column it likes.
6. **The reporter never writes.** It reads the sheet once (~0.8 s) and reports
   only what the tracker already knows.
7. **Notes do not run automatically on `finish`.** The answer is usually
   `NONE`, and a wasted model call per finish adds up on a free tier. `finish`
   prints a one-line reminder instead.

**Three data problems found in the process**

- **A solved problem 0.** Row 1 of block A is labelled `0000` and carries
  ⭐ ✅, but LeetCode numbering starts at 1 — `stats()` was counting a problem
  that does not exist. Solved count corrected 936 → **935**.
- **⭐ was folded into solved.** `stats()` treated ⭐ and ✅ identically, so the
  revision queue could not be built at all. ⭐ now has its own set: **12
  problems** flagged.
- **Thin topics were all typos.** Ranking topics by fewest-solved surfaced
  `OUT`, `pushAll→push left`, `Binary_Search, In, Pre` — data-entry noise, not
  practice targets. Labels used only once are now excluded, which turns the
  list into real categories: `DFS (2)`, `Heap (3)`, `Trie (3)`, `Set (3)`.

**Titles without the network.** The ⭐ queue needs problem titles, but the
cache only holds what this system has fetched. Every archived solution carries
a `// Link:` line, and the slug in it reconstructs the title. That surfaced
another quirk: **105 archive files carry a `*` in the filename** (`1009*.cpp`,
`1157**ST.cpp`) — the user's own revisit marker — so an exact `<id>.cpp`
lookup misses them. The lookup globs `<id>*` and checks the digit boundary, so
asking for `448` cannot match `4480`. *(`*` is illegal in a Windows filename —
noted under Known gaps.)*

**Verified.** Reporter: 935 solved, per-block bars, 95 topics, all 12 ⭐
resolved to real titles offline, largest unsolved run 2615–2638. Notes: nine
branches exercised against a stub provider — `NONE`, fenced `NONE`, duplicate
refused, `--force` override, algo entry with no body, an invalid `FILE:` value
falling back to the named target, an unknown target rejected before any model
call, an empty reply, and `--dry-run` writing nothing. All three formats were
written to copies and diffed: byte-exact, and the real notes files were never
opened for writing.

---

## 11. Known gaps

Honest list of what is not solved, kept here rather than left implied:

1. **No stress-test generator.** The scorer's `efficiency` component measures
   against the example tests, which are tiny — an O(n²) brute force runs them
   instantly and scores full marks on that component. `complexity` still catches
   it by reading the code (brute force 5/25 vs optimal 25/25), so the grades come
   out right, but for the wrong reason on one axis. A generator producing
   worst-case inputs would fix that and would also let the improver claim
   "verified" against more than the examples. **This is the only gap worth
   building.**
2. **`Tags: —` on very recent problems.** LeetCode returns an empty `topicTags`
   for the newest ids, so the classifier falls back to the model with no tag
   hint. Harmless, but it shows in the statement file.
3. **105 archive filenames contain `*`** (`1009*.cpp`, `1157**ST.cpp`). That
   character is legal on Linux and **illegal on Windows**, so those files cannot
   be checked out there at all. They are your own revisit markers, so renaming
   them is your decision, not the system's.
4. **Never executed on Windows.** See §8. The code avoids every Windows trap
   that was identified, but "avoids the known traps" is not "verified".
5. **186 of ~3,400 problems are premium** and return empty content. They are
   reported as locked; the paywall is not worked around. Setting
   `LEETCODE_SESSION` to your own logged-in cookie is the supported route.

---

## Requirements traceability

| Requirement | Where it lands |
|:--|:--|
| 1. Text file with question, constraints, test cases + results | `agents/statement.py` → `<id>_problem.txt` at the repo root, written at fetch time ✅ |
| 2. Score my submission, suggest a better solution | `agents/scorer.py` + `agents/improve.py` ✅ |
| 3. One master agent looping until stopped | `agents/master.py` — REPL + watcher ✅ |
| 4. Runs from the command prompt | `python -m lcagent`, `lc.bat`, `lc` ✅ |
| 5. Windows and Linux | §8 — written for both, exercised only on Linux ⚠️ |
| *(added)* Must cost nothing to run | free-first provider order; 10 of 15 agents need no model ✅ |
| *(added)* All agent data in a separate folder | `lcagent/data/` ✅ |
| *(added)* Menu, like a switch-case | `MENU` in `agents/master.py` ✅ |
| *(added)* A failed fetch must not modify old files or delete partial ones | `agents/fetcher.py` — snapshot → verify → rollback ✅ |
| *(added)* A new fetch replaces the previous problem at the root | `_replace_previous()`, rescuing unarchived work ✅ |
| *(added)* "Better code" writes straight into the file | `agents/improve.py` — verified first, backed up, then installed ✅ |
| *(added)* A setup script that installs the prerequisites on both systems | `bootstrap.py` + `setup.sh` + `setup.bat` ✅ (Windows path untested) |
| *(added)* README with a phase-by-phase log and the architecture | this file ✅ |
