// Link: https://leetcode.com/problems/lexicographically-maximum-mex-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: We can use a greedy approach to partition the array into chunks. We can compute the suffix MEX values for each index in the array. Then, we can iterate through the array from left to right and greedily partition the array into chunks. For each chunk, we can find the shortest prefix that contains all the numbers from 0 to M-1, where M is the suffix MEX value at the current index. We can use a vector to keep track of the last seen chunk for each number to ensure that we only count each number once per chunk. We can then add the MEX value of each chunk to the result vector and return it at the end.

class Solution
{
public:
    std::vector<int> maximumMEX(std::vector<int> &nums)
    {
        int n = nums.size();

        // Step 1: Compute suffix MEX values
        std::vector<int> suffix_mex(n);
        std::vector<bool> seen(n + 2, false);
        int cur_mex = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] >= 0 && nums[i] <= n + 1)
            {
                seen[nums[i]] = true;
            }
            while (seen[cur_mex])
            {
                cur_mex++;
            }
            suffix_mex[i] = cur_mex;
        }

        // Step 2: Greedily partition array from left to right
        std::vector<int> result;
        std::vector<int> last_seen_chunk(n + 2, -1);
        int chunk_id = 0;
        int i = 0;

        while (i < n)
        {
            int M = suffix_mex[i];

            if (M == 0)
            {
                // Take 1 element to produce 0 and maximize remaining length
                result.push_back(0);
                i++;
            }
            else
            {
                int needed = M;
                int j = i;

                // Find shortest prefix containing all 0 ... M-1
                while (j < n && needed > 0)
                {
                    int val = nums[j];
                    if (val >= 0 && val < M)
                    {
                        if (last_seen_chunk[val] != chunk_id)
                        {
                            last_seen_chunk[val] = chunk_id;
                            needed--;
                        }
                    }
                    j++;
                }

                result.push_back(M);
                chunk_id++;
                i = j; // Advance to start of next partition
            }
        }

        return result;
    }
};