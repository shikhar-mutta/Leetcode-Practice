// Link: https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    string merge(string &x, string &y) {
        if (x.find(y) != string::npos) return x;
        if (y.find(x) != string::npos) return y;
        int maxOverlap = 0;
        int limit = min(x.size(), y.size());
        for (int len = limit; len >= 1; len--) {
            if (x.substr(x.size()-len) == y.substr(0, len)) { maxOverlap = len; break; }
        }
        return x + y.substr(maxOverlap);
    }

public:
    string minimumString(string a, string b, string c) {
        vector<string> perm = {a, b, c};
        sort(perm.begin(), perm.end());
        string best = "";
        do {
            string m1 = merge(perm[0], perm[1]);
            string result = merge(m1, perm[2]);
            if (best.empty() || result.size() < best.size() ||
                (result.size() == best.size() && result < best)) {
                best = result;
            }
        } while (next_permutation(perm.begin(), perm.end()));
        return best;
    }
};
