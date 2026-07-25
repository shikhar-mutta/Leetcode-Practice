// Link: https://leetcode.com/problems/minimum-operations-to-halve-array-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//   Approach:
//   1. We can use a max heap to keep track of the largest element in the array.
//   2. We can keep halving the largest element and adding it back to the heap until the sum of the array is less than or equal to half of the original sum.
//   3. We can keep track of the number of operations we have performed and return that as the answer.
class Solution
{
public:
    int halveArray(vector<int> &nums)
    {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double changedSum = sum;
        priority_queue<double> pq;
        for (auto num : nums)
            pq.push((double)num);
        int ops = 0;
        while (changedSum > sum / 2)
        {
            double num = pq.top();
            pq.pop();
            num = num / 2;
            changedSum -= num;
            pq.push(num);
            ops++;
        }
        return ops;
    }
};
