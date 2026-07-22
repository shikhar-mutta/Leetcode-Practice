// Link: https://leetcode.com/problems/additive-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^3)
    // SC: O(n)
    // Approach:
    // 1. We can use backtracking to solve this problem.
    bool isAdditiveNumber(string num)
    {
        int n = num.size();
        for (int i = 1; i < n; i++)
        {
            if (i > 1 && num[0] == '0')
                break;
            string num1 = num.substr(0, i);
            for (int j = i + 1; j < n; j++)
            {
                if (j - i > 1 && num[i] == '0')
                    break;
                string num2 = num.substr(i, j - i);
                if (check(num1, num2, num.substr(j)))
                    return true;
            }
        }
        return false;
    }

private:
    bool check(string num1, string num2, string rest)
    {
        if (rest.empty())
            return true;
        string sum = addStrings(num1, num2);
        if (rest.size() < sum.size() || rest.substr(0, sum.size()) != sum)
            return false;
        return check(num2, sum, rest.substr(sum.size()));
    }

    string addStrings(const string &a, const string &b)
    {
        string res;
        int i = (int)a.size() - 1, j = (int)b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int x = i >= 0 ? a[i--] - '0' : 0;
            int y = j >= 0 ? b[j--] - '0' : 0;
            int s = x + y + carry;
            carry = s / 10;
            res.push_back('0' + s % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
