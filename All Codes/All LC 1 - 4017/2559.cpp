// Link: https://leetcode.com/problems/count-vowel-strings-in-ranges/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q)
// SC: O(n)
// Approach: precompute a prefix count of words whose first and last
// letters are both vowels, then answer each range query in O(1) via
// prefix subtraction.
class Solution {
public:
    bool isV(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int>pre(words.size());
        int sum = 0;
        for(int i=0;i<words.size();i++)
        {
            if(isV(words[i][0]) && isV(words[i][words[i].length()-1]))
                sum++;
            pre[i] = sum;
        }
        for(auto & q:queries)
        {
            int cnt = 0;
            if(q[0]>0)
                cnt = pre[q[1]]-pre[q[0]-1];
            else
                cnt = pre[q[1]];
            ans.push_back(cnt);
        }
        return ans;
    }
};
