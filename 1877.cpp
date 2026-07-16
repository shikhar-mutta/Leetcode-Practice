// Link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) + O(n) = O(n)
// SC: O(n) + O(n) = O(n)
//  Approach:
//  1. Create a frequency array to count the occurrences of each number in the input array nums, but limit the count to N (the maximum possible value in nums) since any number greater than N can be treated as N for the purpose of this problem.
//  2. Use two pointers, i and j, to iterate through the frequency array from the smallest and largest numbers in nums, respectively. For each pair of numbers (i, j), update the maximum pair sum maxPairSum to be the maximum of maxPairSum and i + j. This ensures that we are considering the largest possible pair sums while minimizing the maximum pair sum.
//  3. Finally, return the maximum pair sum maxPairSum, which represents the minimized maximum pair sum that can be achieved after pairing the elements of nums according to the problem's constraints.
constexpr int N = 100001;
int freq[N];
class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int i = N - 1, j = 1;
        for (const int num : nums)
        {
            freq[num]++;
            j = max(j, num);
            i = min(i, num);
        }
        int maxPairSum = 0;
        while (i < j)
        {
            if (freq[i] == 0)
                i++;
            else if (freq[j] == 0)
                j--;
            else
            {
                maxPairSum = max(maxPairSum, i + j);
                freq[i]--;
                freq[j]--;
            }
        }

        if (i == j && freq[i] != 0)
        {
            maxPairSum = max(maxPairSum, i * 2);
            freq[i] = 0;
        }

        return maxPairSum;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
