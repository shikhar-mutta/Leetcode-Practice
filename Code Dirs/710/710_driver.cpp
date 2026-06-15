#include <bits/stdc++.h>
using namespace std;
#include "710.cpp"

// Random Pick with Blacklist: pick() is randomized, so exact output can't be
// diffed. Instead we replay the constructor args, hammer pick() many times,
// and verify the contract: every result is in [0,n), never blacklisted, every
// whitelisted value is reachable, and the distribution is roughly uniform.

int main() {
    string countLine; getline(cin, countLine);         // ignore op-count line
    string opsLine;   getline(cin, opsLine);            // ["Solution","pick",...]
    string argsLine;  getline(cin, argsLine);           // [[7,[2,3,5]],[],...]

    // Parse the first construction args: [[ n , [ b0,b1,... ] ], ...]
    // Pull every integer token out of the first inner "[...]" block.
    int n = -1;
    vector<int> blacklist;
    {
        size_t i = argsLine.find('[', argsLine.find('[') + 1);
        int depth = 0; string tok; vector<int> nums;
        for (; i < argsLine.size(); ++i) {
            char c = argsLine[i];
            if (c == '[') depth++;
            else if (c == ']') {
                if (!tok.empty()) { nums.push_back(stoi(tok)); tok.clear(); }
                depth--;
                if (depth == 0) break;          // closed [7,[...]]
            } else if (c == ',') {
                if (!tok.empty()) { nums.push_back(stoi(tok)); tok.clear(); }
            } else if (isdigit((unsigned char)c) || c == '-') tok += c;
        }
        n = nums[0];                            // nums = [n, b0, b1, ...]
        blacklist.assign(nums.begin() + 1, nums.end());
    }

    set<int> blackset(blacklist.begin(), blacklist.end());
    int m = n - (int)blackset.size();           // number of whitelisted values

    Solution sol(n, blacklist);

    const int TRIALS = 600000;
    map<int,long long> freq;
    bool badRange = false, hitBlack = false;
    for (int t = 0; t < TRIALS; ++t) {
        int x = sol.pick();
        if (x < 0 || x >= n)   badRange = true;
        if (blackset.count(x)) hitBlack = true;
        freq[x]++;
    }

    bool complete = ((int)freq.size() == m);    // every whitelisted value appeared

    bool uniform = true;                        // each share within 20% of ideal 1/m
    double ideal = (double)TRIALS / m;
    for (auto& kv : freq)
        if (fabs((double)kv.second - ideal) > 0.20 * ideal) uniform = false;

    if (!badRange && !hitBlack && complete && uniform)
        cout << "PASS\n";
    else
        cout << "FAIL"
             << (badRange  ? " out-of-range"       : "")
             << (hitBlack  ? " picked-blacklisted" : "")
             << (!complete ? " missing-values"     : "")
             << (!uniform  ? " not-uniform"        : "")
             << "\n";
    return 0;
}
