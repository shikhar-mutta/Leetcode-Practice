// Link: https://leetcode.com/problems/simplified-fractions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * log(min(i,j))) where n is the input number and i and j are the numerator and denominator of the fraction respectively.
    // SC: O(n^2) where n is the input number.
    // Approach:
    //  1. We iterate through all possible denominators from 2 to n.
    //  2. For each denominator, we iterate through all possible numerators from 1 to the denominator - 1.
    //  3. We check if the gcd of the numerator and denominator is 1, which means the fraction is in its simplest form.
    //  4. If the fraction is in its simplest form, we add it to the result vector as a string in the format "numerator/denominator".
    //  5. Finally, we return the result vector containing all the simplified fractions.
    vector<string> simplifiedFractions(int n)
    {
        vector<string> res;
        for (int j = 2; j <= n; j++)
        {
            for (int i = 1; i < j; i++)
            {

                if (gcd(i, j) == 1)
                {
                    res.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return res;
    }
};