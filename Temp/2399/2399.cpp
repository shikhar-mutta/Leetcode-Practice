// Link: https://leetcode.com/problems/check-distances-between-same-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> firstIdx(26, -1);
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (firstIdx[c] == -1) firstIdx[c] = i;
            else if (i - firstIdx[c] - 1 != distance[c]) return false;
        }
        return true;
    }
};
