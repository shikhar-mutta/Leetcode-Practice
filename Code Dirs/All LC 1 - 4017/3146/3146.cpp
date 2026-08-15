// Link: https://leetcode.com/problems/permutation-difference-between-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> posS(26), posT(26);
        for (int i = 0; i < (int)s.size(); i++) posS[s[i]-'a'] = i;
        for (int i = 0; i < (int)t.size(); i++) posT[t[i]-'a'] = i;
        int total = 0;
        for (int c = 0; c < 26; c++) {
            if (find(s.begin(), s.end(), 'a'+c) != s.end())
                total += abs(posS[c] - posT[c]);
        }
        return total;
    }
};
