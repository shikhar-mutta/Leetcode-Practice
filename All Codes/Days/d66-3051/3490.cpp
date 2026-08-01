// Link: https://leetcode.com/problems/count-beautiful-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n) * 10 * log(n)) SC: O(log(n) * 10 * log(n))
// Approach: We can use digit dynamic programming to solve this problem. We will define a recursive function that takes the current index of the digit we are processing, a tight constraint that indicates whether we are still bound by the original number, the current sum of digits, the current product of digits, and a flag to indicate if we have encountered a trailing zero. The base case will check if we have processed all digits and if the product is divisible by the sum. We will memoize the results to avoid redundant calculations. Finally, we will calculate the count of beautiful numbers in the range [l, r] by calculating the count for r and subtracting the count for l-1.

static unordered_map<string, int> dp;
class Solution
{
public:
    vector<int> getDigits(int n)
    {
        vector<int> res;
        while (n > 0)
        {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }

    int digitSum(int idx, int tight, int sum, string prod, int trailingZero,
                 vector<int> &digits)
    {
        if (idx < 0)
        {
            if (sum == 0)
                return 0;
            if (stoll(prod) % sum == 0)
                return 1;
            else
                return 0;
        }

        string key = to_string(idx) + "-" + to_string(tight) + "-" +
                     to_string(sum) + "-" + prod + "-" +
                     to_string(trailingZero);
        if (dp.count(key) && tight != -1)
            return dp[key];

        int ret{};

        // calculating range value
        int k = (tight) ? digits[idx] : 9;
        long long currProd = stoll(prod);

        for (int i = 0; i <= k; i++)
        {
            // calculating newTight value for next state
            int newTight = (digits[idx] == i) ? tight : 0;
            int newTrailingZero{}, newSum{sum + i};
            string newProd{to_string(currProd * i)};
            if (trailingZero == 1 && i == 0)
            {
                newTrailingZero = 1;
                newSum = 0;
                newProd = "0";
            }
            if (trailingZero == 1 && i != 0)
                newProd = to_string(i);

            ret += digitSum(idx - 1, newTight, newSum, newProd, newTrailingZero,
                            digits);
        }

        if (!tight)
            dp[key] = ret;
        return ret;
    }

    int beautifulNumbers(int l, int r)
    {
        vector<int> leftDigits = getDigits(l - 1);
        vector<int> rightDigits = getDigits(r);
        int leftCount =
            digitSum(leftDigits.size() - 1, 1, 0, "0", 1, leftDigits);
        int rightCount =
            digitSum(rightDigits.size() - 1, 1, 0, "0", 1, rightDigits);

        return rightCount - leftCount;
    }
};
