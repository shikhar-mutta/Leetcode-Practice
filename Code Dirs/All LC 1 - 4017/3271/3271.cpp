// Link: https://leetcode.com/problems/hash-divided-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i += k) {
            long long sum = 0;
            for (int j = i; j < i + k; j++) sum += (s[j] - 'a');
            res += (char)('a' + (sum % 26));
        }
        return res;
    }
};
