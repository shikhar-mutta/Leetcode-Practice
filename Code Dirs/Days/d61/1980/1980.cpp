// Link: https://leetcode.com/problems/find-unique-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of strings in the input vector
    // SC: O(n) where n is the length of the strings in the input vector
    // Approach:
    //  1. We will use the fact that the input vector contains n strings of length n, and we need to find a unique binary string of length n that is not present in the input vector.
    //  2. We can construct a unique binary string by taking the i-th character from the i-th string in the input vector and flipping it (i.e., if it is '0', we make it '1', and if it is '1', we make it '0').
    //  3. This guarantees that the constructed string will differ from each string in the input vector at least at one position, making it unique.
    string findDifferentBinaryString(vector<string> &nums)
    {
        string res;
        for (int i = 0; i < nums.size(); ++i)
            res += (nums[i][i] == '0') ? '1' : '0';
        return res;
    }
};