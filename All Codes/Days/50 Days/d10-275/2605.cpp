// Link: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        // TC: O(n), SC: O(1)
        int minNum = 10; // Initialize to a value greater than any digit
        for (int num1 : nums1)
        {
            for (int num2 : nums2)
            {
                if (num1 == num2)
                {
                    minNum = min(minNum, num1);
                }
            }
        }
        if (minNum != 10)
        {
            return minNum; // Found a common digit
        }
        // If no common digit, find the smallest digits from both arrays
        int minDigit1 = *min_element(nums1.begin(), nums1.end());
        int minDigit2 = *min_element(nums2.begin(), nums2.end());
        return min(minDigit1, minDigit2) * 10 + max(minDigit1, minDigit2);
    }
};
