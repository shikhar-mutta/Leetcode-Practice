// Link: https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of elements in the array, SC: O(n) where n is the number of elements in the array
//   Approach: We can use a two-pass approach to find the sum of imbalance numbers of all subarrays. In the first pass, we will iterate through the array from right to left and store the right edge of each element in a vector. In the second pass, we will iterate through the array from left to right and calculate the left edge of each element. We will then use the left and right edges to calculate the number of subarrays that contain the current element and add it to the count. Finally, we will return the count minus the total number of subarrays which is N * (N + 1) / 2.
class Solution
{
public:
    int sumImbalanceNumbers(vector<int> &nums)
    {
        const int N = nums.size();

        // last index of each value as we seen during the iteration.
        vector<int> last_index(N + 2, N);
        vector<int> right_edge(N);
        for (int i = N - 1; i >= 0; --i)
        {
            int num = nums[i];
            right_edge[i] = std::min(last_index[num], last_index[num + 1]);
            last_index[num] = i;
        }

        int count = 0;

        std::fill(last_index.begin(), last_index.end(), -1);
        for (int i = 0; i < N; ++i)
        {
            int num = nums[i];
            int left_edge = last_index[num + 1];
            count += (i - left_edge) * (right_edge[i] - i);
            last_index[num] = i;
        }

        return count - N * (N + 1) / 2;
    }
};