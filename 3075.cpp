// Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(1)
//  Approach:
//   1. Sort the happiness array in ascending order.
//   2. Initialize a variable sum to store the total happiness sum.
//   3. Iterate through the last k elements of the sorted happiness array (the k largest elements):
//      a. For each element, calculate the maximum happiness value by subtracting the index (i) from the happiness value and taking the maximum with 0.
//      b. Add the calculated maximum happiness value to the sum.
//   4. Return the total happiness sum after processing the k largest elements.
class Solution
{
public:
    static long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        const int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        long long sum = 0;
        for (int i = 0; i < k; i++)
        {
            long long x = max(0, happiness[n - 1 - i] - i);
            //    cout<<x<<endl;
            sum += x;
        }
        return sum;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
