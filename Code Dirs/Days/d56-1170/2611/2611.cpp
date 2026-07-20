// Link: https://leetcode.com/problems/mice-and-cheese/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    //  Approach:
    //  1. Calculate the difference between reward1 and reward2 for each cheese.
    //  2. Use nth_element to find the k largest differences.
    //  3. The total reward is the sum of all reward2 plus the sum of the k largest differences.
    //  4. Return the total reward.
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        // diffs[i] := reward1[i] - reward2[i].
        vector<int> diffs;

        for (int i = 0; i < reward1.size(); ++i)
            diffs.push_back(reward1[i] - reward2[i]);

        nth_element(diffs.begin(), diffs.begin() + k, diffs.end(), greater<>());
        return accumulate(reward2.begin(), reward2.end(), 0) +
               accumulate(diffs.begin(), diffs.begin() + k, 0);
    }
};