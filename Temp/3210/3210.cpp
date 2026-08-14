// Link: https://leetcode.com/problems/find-the-encrypted-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.size();
        string res(n, ' ');
        for (int i = 0; i < n; i++) res[i] = s[(i + k) % n];
        return res;
    }
};
