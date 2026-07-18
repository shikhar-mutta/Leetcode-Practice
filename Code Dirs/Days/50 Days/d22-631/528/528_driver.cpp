#include <bits/stdc++.h>
using namespace std;
#include "528.cpp"

// Random Pick with Weight: pickIndex() is randomized, so exact output can't be
// diffed. For each test case we parse the constructor's weight array, hammer
// pickIndex() many times, and verify the contract: every result is a valid
// index, every index is reachable, and index i is hit with frequency ~ w[i]/total.

// Extract the ints inside the first balanced "[...]" group after the outer '[',
// i.e. the constructor's argument list (the weight array).
static vector<int> parseWeights(const string& argsLine) {
    vector<int> w;
    size_t i = argsLine.find('[') + 1;   // step past the outer '['
    int depth = 0; string tok;
    for (; i < argsLine.size(); ++i) {
        char c = argsLine[i];
        if (c == '[') depth++;
        else if (c == ']') {
            if (!tok.empty()) { w.push_back(stoi(tok)); tok.clear(); }
            if (depth == 0) break;        // closed the constructor's arg list
            depth--;
        } else if (c == ',') {
            if (!tok.empty()) { w.push_back(stoi(tok)); tok.clear(); }
        } else if (isdigit((unsigned char)c) || c == '-') tok += c;
    }
    return w;
}

int main() {
    string countLine; getline(cin, countLine);
    int t = stoi(countLine);
    while (t--) {
        string opsLine;  getline(cin, opsLine);   // ["Solution","pickIndex",...]
        string argsLine; getline(cin, argsLine);  // [[[1,3]],[],...]

        vector<int> w = parseWeights(argsLine);
        int n = w.size();
        long long total = accumulate(w.begin(), w.end(), 0LL);

        Solution sol(w);

        const int TRIALS = 500000;
        vector<long long> freq(n, 0);
        bool badIdx = false;
        for (int k = 0; k < TRIALS; ++k) {
            int x = sol.pickIndex();
            if (x < 0 || x >= n) { badIdx = true; continue; }
            freq[x]++;
        }

        bool complete = true, proportional = true;
        for (int i = 0; i < n; ++i) {
            if (freq[i] == 0) complete = false;                 // every index reachable
            double expected = TRIALS * (double)w[i] / total;
            // within 10% of expected share, plus small absolute slack for tiny shares
            if (fabs((double)freq[i] - expected) > 0.10 * expected + 50)
                proportional = false;
        }

        if (!badIdx && complete && proportional)
            cout << "PASS\n";
        else
            cout << "FAIL"
                 << (badIdx        ? " bad-index"     : "")
                 << (!complete     ? " missing-index" : "")
                 << (!proportional ? " skewed"        : "")
                 << "\n";
    }
    return 0;
}
