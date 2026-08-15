// Link: https://leetcode.com/problems/adding-two-negabinary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(max(n, m)) where n is the length of arr1 and m is the length of arr2
    // SC: O(max(n, m)) where n is the length of arr1 and m is the length of arr2
    // Approach:
    //  1. We will use a while loop to iterate through the two arrays from the end to the beginning.
    //  2. We will keep track of the carry and the current digit to be added to the result.
    //  3. We will use the formula digit = ((total % 2) + 2) % 2 to get the current digit and carry = (digit - total) / 2 to get the carry.
    //  4. We will push the current digit to the result vector and decrement the indices of the two arrays.
    //  5. Finally, we will reverse the result vector and return it.
    vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> res;
        int i = arr1.size() - 1, j = arr2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry != 0)
        {
            int x = i >= 0 ? arr1[i] : 0;
            int y = j >= 0 ? arr2[j] : 0;
            int total = x + y + carry;
            int digit = ((total % 2) + 2) % 2;
            carry = (digit - total) / 2;
            res.push_back(digit);
            i--;
            j--;
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
