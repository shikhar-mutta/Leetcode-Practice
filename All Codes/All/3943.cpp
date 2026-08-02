// Link: https://leetcode.com/problems/number-of-pairs-after-increment/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * n)  SC: O(n)
// Approach: We can use a hash map to store the count of each number in nums2. For each query, we can check if the query is of type 1 or type 2. If it is of type 1, we can iterate through nums1 and check if the target - num + totalOffset exists in the hash map. If it does, we can add the count to the answer. If it is of type 2, we can update the nums2 array and the hash map accordingly. We can also merge consecutive type-1 queries with the same [l, r] to optimize the solution.
class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        vector<long long> nums(nums2.begin(), nums2.end());
        unordered_map<long long, long long> num2Cnt;
        for (auto num : nums)
            num2Cnt[num]++;

        long long totalOffset = 0;
        int n2 = nums.size();
        int n2half = n2 / 2;
        vector<int> ans;
        ans.reserve(queries.size());

        int Q = queries.size();
        for (int i = 0; i < Q; i++)
        {
            auto &query = queries[i];
            if (query.size() == 2)
            {
                int target = query[1];
                int cnt = 0;
                for (auto num : nums1)
                    cnt += num2Cnt[target - num + totalOffset];
                ans.push_back(cnt);
            }
            else
            {
                int startIdx = query[1];
                int endIdx = query[2] + 1;
                long long offset = query[3];

                // merge consecutive type-1 queries with same [l, r]
                while (i + 1 < Q && queries[i + 1].size() != 2 && queries[i + 1][1] == startIdx && queries[i + 1][2] == endIdx - 1)
                {
                    offset += queries[i + 1][3];
                    i++;
                }

                if (endIdx - startIdx > n2half)
                {
                    totalOffset -= offset;
                    for (int j = 0; j < startIdx; j++)
                    {
                        num2Cnt[nums[j]]--;
                        nums[j] -= offset;
                        num2Cnt[nums[j]]++;
                    }
                    for (int j = endIdx; j < n2; j++)
                    {
                        num2Cnt[nums[j]]--;
                        nums[j] -= offset;
                        num2Cnt[nums[j]]++;
                    }
                }
                else
                {
                    for (int j = startIdx; j < endIdx; j++)
                    {
                        num2Cnt[nums[j]]--;
                        nums[j] += offset;
                        num2Cnt[nums[j]]++;
                    }
                }
            }
        }
        return ans;
    }
};
