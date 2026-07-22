// Link: https://leetcode.com/problems/next-greater-element-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of digits in the number
    // SC: O(n) where n is the number of digits in the number
    // Approach:
    //  1. Convert the number to a string to easily manipulate its digits.
    //  2. Find the first digit that is smaller than the digit next to it,
    //     starting from the rightmost side of the string. This digit is called the "pivot".
    //  3. If no such digit is found, it means the digits are in descending order, and we cannot form a greater number. Return -1 in this case.
    //  4. If a pivot is found, find the smallest digit on the right side of the pivot that is greater than the pivot digit. This digit is called the "successor".
    //  5. Swap the pivot and successor digits.
    //  6. Reverse the digits to the right of the pivot to get the smallest possible number that is greater than the original number.
    //  7. Convert the string back to an integer and check if it exceeds the maximum value for a 32-bit signed integer. If it does, return -1; otherwise, return the result.
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int i = (int)s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            i--;
        if (i < 0)
            return -1;
        int j = (int)s.size() - 1;
        while (s[j] <= s[i])
            j--;
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long long result = stoll(s);
        return result > INT_MAX ? -1 : (int)result;
    }
};
