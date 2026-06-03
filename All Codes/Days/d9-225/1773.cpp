// Link: https://leetcode.com/problems/count-items-matching-a-rule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int count = 0;
        int index = 0;
        // Determine the index based on the ruleKey
        if (ruleKey == "type")
        {
            index = 0;
        }
        else if (ruleKey == "color")
        {
            index = 1;
        }
        else if (ruleKey == "name")
        {
            index = 2;
        }
        // Iterate through each item and count matches based on the determined index
        for (auto &item : items)
        {
            if (item[index] == ruleValue)
            {
                count++;
            }
        }
        return count;
    }
};
