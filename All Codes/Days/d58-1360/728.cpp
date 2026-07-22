// Link: https://leetcode.com/problems/self-dividing-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * d) and SC: O(1)
    //  Approach:
    //  1. We iterate through all the numbers from left to right.
    //  2. For each number, we check if it is a self-dividing number by checking if it is divisible by each of its digits.
    //  3. If it is a self-dividing number, we add it to the result vector.
    //  4. Finally, we return the result vector.
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int n = left; n <= right; n++)
        {
            int x = n;
            bool ok = true;
            while (x > 0)
            {
                int d = x % 10;
                if (d == 0 || n % d != 0)
                {
                    ok = false;
                    break;
                }
                x /= 10;
            }
            if (ok)
                res.push_back(n);
        }
        return res;
    }
};
