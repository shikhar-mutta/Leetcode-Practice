// Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the size of nums
// SC: O(1) as we are using a fixed size array of 50001
// Approach:
//  1. We will create a frequency array of size 50001 to store the frequency of each number in the input array nums.
//  2. We will also keep track of the minimum and maximum number in the input array
//  3. We will iterate from the maximum number to the minimum number and for each number, we will add its frequency to a sum variable and add the sum to a count variable. This count variable will give us the total number of operations required to make all the elements equal.
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int freq[50001] = {0};
        int minN = 50000, maxN = 0;
#pragma unroll
        for (int x : nums)
        {
            freq[x]++;
            minN = min(minN, x);
            maxN = max(maxN, x);
        }
        int count = 0, sum = 0;
#pragma unroll
        for (int x = maxN; x > minN; x--)
        {
            if (freq[x] > 0)
            {
                sum += freq[x];
                count += sum;
            }
        }
        return count;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();