// Link: https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N) where N is the number of elements in the array. The function nth_element runs in linear time on average, and we call it twice (once to find the median and once to partition the array based on strength).
// SC: O(1) for the in-place partitioning. The space complexity is constant, as we perform the partitioning in-place without using any additional data structures.
// Approach:
// 1. We first find the median of the array using nth_element, which rearranges the elements in such a way that the median is placed at its correct position in the sorted order.
// 2. We then use nth_element again to partition the array based on the strength of the elements relative to the median. The strength is defined as the absolute difference from the median, and in case of ties, we prefer the larger value.
class Solution
{
public:
    vector<int> getStrongest(vector<int> &arr, int k)
    {
        nth_element(arr.begin(), arr.begin() + (arr.size() - 1 >> 1), arr.end());
        int m = arr[arr.size() - 1 >> 1];
        nth_element(arr.begin(), arr.begin() + k, arr.end(), [&m](const int &a, const int &b)
                    {
            int x = abs(a - m), y = abs(b - m);
            if(x != y){
                return x > y;
            }
            return a > b; });
        arr.resize(k);
        return arr;
    }
};
