// Link: https://leetcode.com/problems/minimum-moves-to-pick-k-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
// Approach: Find the indices of all 1s in the array. Then, for each window of size k, find the median index and calculate the cost to move all 1s in that window to the median index. The cost is calculated as the sum of absolute differences between each index and the median index. Finally, add the cost of maxChanges to the total cost and return the minimum cost found across all windows.
class Solution
{
public:
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int n = nums.size();
        bool noOnes = false;
        for (auto i : nums)
        {
            if (i == 1)
            {
                noOnes = 1;
                break;
            }
        }
        if (!noOnes)
            return k * 2;
        if (k == 1)
            return 0;

        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] == 1 && nums[i + 1] == 1 && nums[i - 1] == 1)
            {
                if (k == 2)
                {
                    return 1;
                }
                int rem = k - 3;
                if (maxChanges >= rem)
                {
                    return 2 + rem * 2;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == 1 && nums[i - 1] == 1)
            {
                if (k == 2)
                    return 1;
                int rem = k - 2;
                int ans = 1;
                if (maxChanges >= rem)
                {
                    return ans + rem * 2;
                }
            }
        }
        if (maxChanges >= k - 1)
        {
            return 2 * (k - 1);
        }
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                arr.push_back(i);
        }
        vector<long long> pref(arr.size(), 0);
        pref[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            pref[i] += (pref[i - 1] + arr[i]);
        }
        k = k - maxChanges;
        int i = 0, j = k - 1;
        long long ans = 1e18;
        while (j < arr.size())
        {
            // for(int q = i ; q <= j; q++){
            //     cout<<pref[q]<<" ";
            // }
            // cout<<endl;
            int median = (i + j) / 2;
            long long leftsum = pref[median] - pref[i] + arr[i];
            long long rightsum = pref[j] - pref[median];
            long long leftcount = median - i + 1;
            long long rightcount = j - median;
            long long cost = abs(leftsum - 1LL * arr[median] * leftcount) +
                             abs(rightsum - 1LL * arr[median] * rightcount);
            ans = min(ans, cost + 2 * maxChanges);

            i++;
            j++;
        }
        return ans;
    }
};
