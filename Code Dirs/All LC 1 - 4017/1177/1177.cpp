// Link: https://leetcode.com/problems/can-make-palindrome-from-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<array<int,26>> prefix(n + 1);
        prefix[0].fill(0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i];
            prefix[i+1][s[i]-'a']++;
        }

        vector<bool> res;
        for (auto& q : queries) {
            int left = q[0], right = q[1], k = q[2];
            int odd = 0;
            for (int c = 0; c < 26; c++) {
                if ((prefix[right+1][c] - prefix[left][c]) % 2 != 0) odd++;
            }
            res.push_back(odd / 2 <= k);
        }
        return res;
    }
};
