// Link: https://leetcode.com/problems/design-compressed-string-iterator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per op SC: O(n)
// Approach: parse compressed string into (char,count) pairs; maintain current pair index and remaining count for next().
class StringIterator {
    vector<pair<char,int>> runs;
    int idx = 0;
    int rem = 0;
public:
    StringIterator(string compressedString) {
        int i = 0, n = compressedString.size();
        while (i < n) {
            char c = compressedString[i++];
            int cnt = 0;
            while (i < n && isdigit(compressedString[i])) { cnt = cnt*10 + (compressedString[i]-'0'); i++; }
            runs.push_back({c, cnt});
        }
        if (!runs.empty()) rem = runs[0].second;
    }

    char next() {
        if (!hasNext()) return ' ';
        char c = runs[idx].first;
        rem--;
        if (rem == 0) {
            idx++;
            if (idx < (int)runs.size()) rem = runs[idx].second;
        }
        return c;
    }

    bool hasNext() {
        return idx < (int)runs.size();
    }
};
