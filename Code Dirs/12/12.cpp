// Link: https://leetcode.com/problems/integer-to-roman/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n)), SC: O(1)
    string getRom(int n)
    {
        string ans = "";
        if (n < 10)
        {
            if (n < 5)
            {
                if (n == 4)
                    ans = "IV";
                else
                    ans = string(n, 'I');
            }
            else
            {
                if (n == 9)
                    ans = "IX";
                else
                    ans = 'V' + string(n - 5, 'I');
            }
        }
        else if (n < 100)
        {
            if (n < 50)
            {
                if (n == 40)
                    ans = "XL";
                else
                    ans = string(n / 10, 'X');
            }
            else
            {
                if (n == 90)
                    ans = "XC";
                else
                    ans = 'L' + string(n / 10 - 5, 'X');
            }
        }
        else if (n < 1000)
        {
            if (n < 500)
            {
                if (n == 400)
                    ans = "CD";
                else
                    ans = string(n / 100, 'C');
            }
            else
            {
                if (n == 900)
                    ans = "CM";
                else
                    ans = 'D' + string(n / 100 - 5, 'C');
            }
        }
        else
        {
            n = n / 1000;
            ans = string(n, 'M');
        }

        return ans;
    }
    string intToRoman(int num)
    {
        string ans = "";
        int cnt = 0;
        while (num > 0)
        {
            if (num % 10 > 0)
            {
                ans = getRom((num % 10) * pow(10, cnt)) + ans;
            }
            num /= 10, cnt++;
        }
        return ans;
    }
};
