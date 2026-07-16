// Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of elements in the array. We use the nth_element algorithm which has an average time complexity of O(n).
    // SC: O(1) as we are using constant extra space.
    // Approach:
    //   1. We use the nth_element algorithm to partially sort the array such that the k-th largest element is in its final sorted position.
    //   2. We define a custom comparator to compare the strings based on their lengths and lexicographical order.
    //   3. Finally, we return the k-th largest element from the array.
    string kthLargestNumber(vector<string> &a, int k)
    {
        return nth_element(a.begin(), a.begin() + k - 1, a.end(), [](const string &a, const string &b)
                           {
            int m=a.size(),n=b.size();
            return m!=n?m>n:a>b; }),
               a[k - 1];
    }
};