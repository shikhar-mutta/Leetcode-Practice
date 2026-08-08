// Link: https://leetcode.com/problems/orderly-queue/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string best = s;
        for (int i = 1; i < (int)s.size(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            best = min(best, rotated);
        }
        return best;
    }
};
