// Link: https://leetcode.com/problems/split-with-minimum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn). SC: O(n).
    int splitNum(int num)
    {
        vector<int> digits;
        while (num)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
        sort(digits.begin(), digits.end());
        int num1 = 0, num2 = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            if (i % 2 == 0)
                num1 = num1 * 10 + digits[i];
            else
                num2 = num2 * 10 + digits[i];
        }
        return num1 + num2;
    }
};
