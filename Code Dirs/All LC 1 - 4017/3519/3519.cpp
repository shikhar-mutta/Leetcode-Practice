// Link: https://leetcode.com/problems/count-numbers-with-non-decreasing-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    string dec(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }
        s[i]--;
        if (s[0] == '0') return s.substr(1);
        return s;
    }
    vector<int> convertBase(string s, int b) {
        vector<int> num;
        for (char c : s) {
            int carry = c - '0';
            for (int i = 0; i < (int)num.size(); i++) {
                int val = num[i] * 10 + carry;
                num[i] = val % b;
                carry = val / b;
            }
            while (carry) {
                num.push_back(carry % b);
                carry /= b;
            }
        }
        reverse(num.begin(), num.end());
        if (num.empty()) num.push_back(0);
        return num;
    }
    int dp[350][11][2];
    int solve(vector<int>& digits, int idx, int prev, int tight, int b) {
        if (idx == (int)digits.size()) return 1;
        if (dp[idx][prev][tight] != -1) {
            return dp[idx][prev][tight];
        }
        int limit = tight ? digits[idx] : b - 1;
        long long ans = 0;
        for (int d = prev; d <= limit; d++) {
            int newTight = tight && (d == limit);
            ans = (ans + solve(digits, idx + 1, d, newTight, b)) % mod;
        }
        return dp[idx][prev][tight] = ans;
    }

    int countUpto(string s, int b) {
        vector<int> digits = convertBase(s, b);
        memset(dp, -1, sizeof(dp));
        return solve(digits, 0, 0, 1, b);
    }
    int countNumbers(string l, string r, int b) {
        int right = countUpto(r, b);
        int left = countUpto(dec(l), b);
        return (right - left + mod) % mod;
    }
};
