// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        long long total = 3LL << (n - 1);
        if (k > total) return "";
        k--;

        string res;
        long long block = 1LL << (n - 1);
        int first = k / block;
        res += char('a' + first);
        k %= block;

        for (int i = 1; i < n; i++) {
            block /= 2;
            vector<char> options;
            for (char c = 'a'; c <= 'c'; c++) if (c != res.back()) options.push_back(c);
            int idx = k / block;
            res += options[idx];
            k %= block;
        }
        return res;
    }
};
