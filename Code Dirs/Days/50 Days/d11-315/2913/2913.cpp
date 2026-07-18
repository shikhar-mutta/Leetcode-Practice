// Link: https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: sliding window
    // TC: O(n^2), SC: O(n)
    int sumCounts(vector<int> &nums)
    {
        bitset<101> seen;
        vector<int> counts(101, 0);
        int ans = 0, temp;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            seen.reset();
            counts.assign(101, 0);
            // window of size i
            for (int j = 0; j < i; j++)
            {
                if (!seen[nums[j]])
                    seen[nums[j]] = true;
                counts[nums[j]]++;
            }
            temp = seen.count();
            ans += temp * temp;
            // slide the window
            for (int j = i; j < n; j++)
            {
                counts[nums[j - i]]--;
                if (counts[nums[j - i]] == 0)
                    seen[nums[j - i]] = false;
                if (!seen[nums[j]])
                    seen[nums[j]] = true;
                counts[nums[j]]++;
                temp = seen.count();
                ans += temp * temp;
            }
        }
        return ans;
    }
};
