// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Sort the current and previous string and compare them.
    // TC: o(nlogn) SC: o(n)
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (i == 0)
                ans.push_back(words[i]);
            else
            {
                string prev = ans.back();
                string curr = words[i];
                sort(prev.begin(), prev.end());
                sort(curr.begin(), curr.end());
                if (prev != curr)
                    ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
