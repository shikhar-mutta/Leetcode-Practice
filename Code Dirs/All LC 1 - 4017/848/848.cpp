// Link: https://leetcode.com/problems/shifting-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long total = 0;
        for (int x : shifts) total = (total + x) % 26;
        string res = s;
        for (int i = 0; i < (int)s.size(); i++) {
            res[i] = 'a' + (s[i] - 'a' + total) % 26;
            total = ((total - shifts[i]) % 26 + 26) % 26;
        }
        return res;
    }
};
