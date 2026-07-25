// Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m + n), where m is the size of the input array nums1 and n is the size of the input array nums2.
// SC: O(1), as we are using a constant amount of extra space for variables
//  Approach:
//   1. We initialize two variables m and n to store the sizes of the input arrays nums1 and nums2, respectively.
//   2. We initialize a variable res to 0, which will be used to store the final result.
//   3. We check if the size of nums2 is odd. If it is, we iterate through each element of nums1 and XOR it with res. This is because each element of nums1 will appear n times in the pairings, and if n is odd, the XOR of an odd number of identical elements is the element itself.
//   4. We check if the size of nums1 is odd. If it is, we iterate through each element of nums2 and XOR it with res. This is because each element of nums2 will appear m times in the pairings, and if m is odd, the XOR of an odd number of identical elements is the element itself.
//   5. Finally, we return the value of res, which represents the bitwise XOR of all pairings between the elements of nums1 and nums2.
class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int res = 0;
        if (n % 2)
            for (int x : nums1)
                res ^= x; // each nums1 element appears n times
        if (m % 2)
            for (int x : nums2)
                res ^= x; // each nums2 element appears m times
        return res;
    }
};