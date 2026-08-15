// Link: https://leetcode.com/problems/make-array-empty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) SC: O(n)
    // Approach:
    //  1. Create a vector of pairs to store the elements of the input array along with their original indices.
    //  2. Sort the vector of pairs based on the elements of the input array.
    //  3. Initialize a count variable to the size of the input array.
    //  4. Iterate through the sorted vector of pairs and check if the current element's original index is less than the previous element's original index. If it is, increment the count by the number of remaining elements in the input array.
    //  5. Return the count variable as the result.
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        int n = nums.size();
        long long count = n;
        vector<pair<int, int>> sorted_nums(n);
        for (int i = 0; i < n; ++i)
        {
            sorted_nums[i] = {nums[i], i};
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 1; i < n; ++i)
        {
            if (sorted_nums[i].second < sorted_nums[i - 1].second)
            {
                count += (n - i);
            }
        }
        return count;
    }
};
