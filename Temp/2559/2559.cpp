// Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            bool valid = isVowel(words[i].front()) && isVowel(words[i].back());
            prefix[i+1] = prefix[i] + (valid ? 1 : 0);
        }

        vector<int> ans;
        for (auto &q : queries) {
            ans.push_back(prefix[q[1]+1] - prefix[q[0]]);
        }
        return ans;
    }
};
