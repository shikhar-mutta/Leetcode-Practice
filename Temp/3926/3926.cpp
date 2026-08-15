// Link: https://leetcode.com/problems/count-valid-word-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(totalChunkLen + totalQueryLen) SC: O(same)
//  Approach: concatenate chunks, then scan once building words: a
//  hyphen only belongs to the current word if both its neighbors exist
//  and are letters (a "joiner hyphen"); any other character (space, or a
//  non-joiner hyphen) ends the current word. Count words in a hashmap
//  and answer each query via lookup.
class Solution
{
public:
    vector<int> countWordOccurrences(vector<string> &chunks, vector<string> &queries)
    {
        string s;
        unordered_map<string, int> mp;
        for (int i = 0; i < chunks.size(); i++)
        {
            string temp = chunks[i];
            s += (temp);
        }
        for (int i = 0; i < s.length(); i++)
        {
            int j = i;
            string temp;
            while (j < s.length() && s[j] != ' ')
            {
                bool ch = false;
                while (s[j] == '-' && !(j - 1 >= 0 && j + 1 < s.length() && s[j - 1] >= 'a' && s[j - 1] <= 'z' && s[j + 1] >= 'a' && s[j + 1] <= 'z'))
                {
                    ch = true;
                    j++;
                }
                if (ch)
                {
                    mp[temp]++;
                    j = j - 1;
                    temp = "";
                }
                else
                    temp.push_back(s[j]);
                j++;
            }
            mp[temp]++;
            i = j;
        }
        int q = queries.size();
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++)
        {
            ans[i] = mp[queries[i]];
        }
        return ans;
    }
};