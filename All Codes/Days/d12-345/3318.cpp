// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time: O(n * x log k), Space: O(k)
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> ans;
        map<int, int> freq;

        // Function to calculate x-sum
        auto xsum = [&]()
        {
            vector<pair<int, int>> v(freq.begin(), freq.end()); // {num, freq}
            // Sort Vector by freq
            sort(v.begin(), v.end(), [](auto &a, auto &b)
                 { return a.second != b.second ? a.second > b.second : a.first > b.first; });
            int sum = 0, n = min(x, (int)v.size());
            // Calculate x-sum
            for (int i = 0; i < n; i++)
                sum += v[i].first * v[i].second;
            return sum;
        };

        // Init pipeline
        for (int i = 0; i < k; i++)
            freq[nums[i]]++;

        // Calculate x-sum for the first window
        ans.push_back(xsum());

        // Slide the window
        for (int i = k; i < n; i++)
        {
            if (--freq[nums[i - k]] == 0)
                freq.erase(nums[i - k]); // Remove from map if freq becomes 0
            freq[nums[i]]++;
            ans.push_back(xsum()); // Calculate x-sum for the current window
        }

        return ans;
    }
};
