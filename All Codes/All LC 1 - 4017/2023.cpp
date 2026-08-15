// Link: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of strings in nums and m is the length of the target string
// SC: O(n * m) where n is the number of strings in nums and m is the length of the target string
//  Approach:
//  1. Create a frequency map to store the count of each string in nums.
//  2. Iterate through each string in nums and check if it can be a prefix or suffix of the target string.
//  3. If it can be a prefix, check if the corresponding suffix exists in the frequency map and add its count to the answer.
//  4. If it can be a suffix, check if the corresponding prefix exists in the frequency map and add its count to the answer.
//  5. Update the frequency map with the current string.
class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        unordered_map<string, int> freq;
        int ans = 0;
        for (string val : nums)
        {
            if (val.size() > target.size())
                continue;

            bool matchEnd = true;
            for (int i = 0; i < val.size(); i++)
            {
                if (val[i] != target[target.size() - val.size() + i])
                {
                    matchEnd = false;
                    break;
                }
            }

            bool matchStart = true;
            for (int i = 0; i < val.size(); i++)
            {
                if (val[i] != target[i])
                {
                    matchStart = false;
                    break;
                }
            }

            if (matchEnd)
            {
                string start;

                for (int i = 0; i < (target.size() - val.size()); i++)
                {
                    start += target[i];
                }
                if (freq.contains(start))
                {
                    ans += freq[start];
                }
            }

            if (matchStart)
            {
                string end;
                for (int i = val.size(); i < target.size(); i++)
                {
                    end += target[i];
                }
                if (freq.contains(end))
                {
                    ans += freq[end];
                }
            }
            freq[val] += 1;
        }

        return ans;
    }
};