// Link: https://leetcode.com/problems/largest-palindrome-product/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^n)  SC: O(1)
//  Approach: Let the palindrome be of the form left + right, where right is the reverse of left. Then the palindrome is equal to left * 10^n + right. Let the two factors be x and y. Then we have x * y = left * 10^n + right. Let z = x + y. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right and x + y = z. Then we have x * y = left * 10^n + right.
class Solution
{
public:
    int flip(int n)
    {
        auto str = to_string(n);
        std::reverse(str.begin(), str.end());
        return atoi(str.c_str());
    }
    bool isInteger(double v)
    {
        double tmp;
        return std::modf(v, &tmp) == 0.0;
    }
    int largestPalindrome(int n)
    {
        if (n == 1)
            return 9;
        const long max = pow(10, n);
        for (int z = 2; z < max - 1; z++)
        {
            const long left = max - z;
            const long right = flip(left);
            const double sqrt_term = z * z - 4 * right;

            if (sqrt_term < 0.0)
            {
                continue;
            }

            const double root1 = 0.5 * (z + sqrt(sqrt_term));
            const double root2 = 0.5 * (z - sqrt(sqrt_term));

            if (isInteger(root1) || isInteger(root2))
            {
                return (max * left + right) % 1337;
            }
        }
        return -1;
    }
};