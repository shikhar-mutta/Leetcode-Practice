// Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge) mp[k[0]] = k[1];

        string res;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') j++;
                string key = s.substr(i + 1, j - i - 1);
                if (mp.count(key)) res += mp[key];
                else res += "?";
                i = j + 1;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};
