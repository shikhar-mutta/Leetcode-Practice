// Link: https://leetcode.com/problems/powerful-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(bound)/log(x) * log(bound)/log(y)), SC: O(n)
    // Approach: Brute Force
    // 1. We will iterate over all the powers of x and y and check if the sum of the two powers is less than or equal to the bound.
    // 2. If it is, we will add it to the result set.
    // 3. We will continue this process until we reach the bound for both x and y.
    // 4. Finally, we will return the result set as a vector.
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> result;
        for (long long i = 1; i <= bound; i *= x)
        {
            for (long long j = 1; i + j <= bound; j *= y)
            {
                result.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(result.begin(), result.end());
    }
};
