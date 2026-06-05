// Link: https://leetcode.com/problems/last-visited-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<int> &nums)
    {
        vector<int> ans, seen;
        int consec = 0; // number of consecutive -1s seen so far

        for (int x : nums)
            if (x != -1)
            {
                seen.push_back(x); // propend the current number to the seen list
                consec = 0;
            }
            else
            {
                consec++; // increment the count of consecutive -1s
                int idx = (int)seen.size() - consec;
                ans.push_back(idx >= 0 ? seen[idx] : -1);
            }

        return ans;
    }
};
