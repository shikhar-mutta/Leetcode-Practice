// Link: https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogn), SC: O(n)
    // Approach:
    //  1. Sort the indices of nums based on their values in ascending order.
    //  2. Initialize a variable total to store the sum of all elements in nums.
    //  3. Create a boolean vector marked to keep track of which elements have been marked
    //  4. Iterate through each query in queries:
    //     a. For each query, mark the element at the specified index and update the total sum accordingly.
    //     b. While there are still elements to mark (k > 0) and there are unmarked elements in nums, mark the next smallest unmarked element and update the total sum.
    //     c. Append the current total sum to the answer vector.
    //  5. Return the answer vector containing the sum of unmarked elements after each query.
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b)
             { return nums[a] != nums[b] ? nums[a] < nums[b] : a < b; });

        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        vector<bool> marked(n, false);
        int ptr = 0;

        vector<long long> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
        {
            int idx = q[0], k = q[1];
            if (!marked[idx])
            {
                marked[idx] = true;
                total -= nums[idx];
            }
            while (k > 0 && ptr < n)
            {
                int i = order[ptr++];
                if (marked[i])
                    continue;
                marked[i] = true;
                total -= nums[i];
                k--;
            }
            ans.push_back(total);
        }
        return ans;
    }
};
