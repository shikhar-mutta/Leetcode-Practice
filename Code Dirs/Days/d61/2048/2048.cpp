// Link: https://leetcode.com/problems/next-greater-numerically-balanced-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m), SC: O(1)
//    Approach:
//    1. We can use the next permutation algorithm to generate all the permutations of the digits in the string.
//    2. We can use a helper function to check if the current permutation is a valid numerically balanced number.
//    3. We can keep track of the minimum numerically balanced number that is greater than the input number and return it at the end.
class Solution
{
public:
    bool nextPermutation(string &digits)
    {
        int n = digits.size();
        int i = n - 2;
        while (i >= 0 && digits[i] >= digits[i + 1])
        {
            i -= 1;
        }

        if (i < 0)
        {
            return false;
        }

        for (int j = n - 1; j > i; j--)
        {
            if (digits[j] > digits[i])
            {
                swap(digits[i], digits[j]);
                reverse(begin(digits) + i + 1, end(digits));
                break;
            }
        }

        return true;
    }
    long long minNum(string digits, int num)
    {
        string s = "";
        int ans = INT_MAX;
        for (auto i : digits)
        {
            s += string((i - '0'), i);
            if (s.size() > 7)
            {
                break;
            }
            string t = s;
            do
            {
                int curr = stoi(t);
                if (curr > ans)
                {
                    return ans;
                }
                if (curr > num)
                {
                    ans = min(ans, curr);
                }
            } while (nextPermutation(t));
        }

        return ans;
    }
    int nextBeautifulNumber(int n)
    {
        long long ans = INT_MAX;
        string digits = "123456";
        do
        {
            ans = min(ans, minNum(digits, n));
        } while (nextPermutation(digits));
        return ans;
    }
};