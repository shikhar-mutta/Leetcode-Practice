// Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1 << k;
        if ((int)s.size() - k + 1 < need) return false;
        unordered_set<int> seen;
        for (int i = 0; i + k <= (int)s.size(); i++) {
            int val = stoi(s.substr(i, k), nullptr, 2);
            seen.insert(val);
        }
        return (int)seen.size() == need;
    }
};
