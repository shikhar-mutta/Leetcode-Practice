// Link: https://leetcode.com/problems/multiply-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n1*n2) where n1 and n2 are the lengths of num1 and num2 respectively
    // SC: O(n1+n2) where n1 and n2 are the lengths of num1 and num2 respectively
    // Approach:
    //  1. We will use the grade school multiplication algorithm to multiply the two numbers
    //  2. We will create a result vector of size n1+n2 to store the intermediate results
    //  3. We will iterate through the digits of num1 and num2 from right to left and multiply them, adding the result to the appropriate position in the result vector
    //  4. We will then convert the result vector to a string and return it

    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--)
        {
            int d1 = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; j--)
            {
                int d2 = num2[j] - '0';
                int sum = result[i + j + 1] + d1 * d2;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string s;
        for (int v : result)
        {
            if (!(s.empty() && v == 0))
                s += (char)('0' + v);
        }
        return s;
    }
};
