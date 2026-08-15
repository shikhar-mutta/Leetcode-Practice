// Link: https://leetcode.com/problems/shifting-letters-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for (auto& sh : shifts) {
            int dir = sh[2] == 1 ? 1 : -1;
            diff[sh[0]] += dir;
            diff[sh[1] + 1] -= dir;
        }
        int cur = 0;
        string res = s;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            int shift = ((cur % 26) + 26) % 26;
            res[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return res;
    }
};
