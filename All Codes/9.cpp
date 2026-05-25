// Link : https://leetcode.com/problems/palindrome-number/description/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Best Approach 1: Reverse the number and compare with original number
        int rev = 0, temp = x;
        while (temp > 0)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return (rev == x) ? true : false;

        // Approach 2: Convert the number to string and check if it is a palindrome
        // string str = to_string(x);
        
        // bool neg = (str[0] == '-') ? true : false;

        // int i = neg ? 1 : 0, j = str.size() - 1;
        // while (i < j)
        // {
        //     if (str[i] != str[j])
        //         return false;
        //     i++;
        //     j--;
        // }
        // if (neg)
        //     return false;
        // return true;
    }
};