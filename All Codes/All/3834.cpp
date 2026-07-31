// Link: https://leetcode.com/problems/merge-adjacent-equal-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack-based cascading merge — push each value, and while the
// top two stack elements are equal, pop both and push their double
// (repeating since a new merge can cascade further).
class Solution
{
public:
    vector<long long> mergeAdjacent(vector<int> &nums)
    {
        vector<long long> ans;

        for (const auto &num : nums)
        {
            long long sum = num;
            while (!ans.empty() && sum == ans.back())
            {
                sum += ans.back();
                ans.pop_back();
            }
            ans.push_back(sum);
        }

        return ans;
    }
};