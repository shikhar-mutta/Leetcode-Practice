// Link: https://leetcode.com/problems/fraction-addition-and-subtraction/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the input string expression. We iterate through the string once to parse the fractions and perform the addition/subtraction.
    // SC: O(1), we use a constant amount of extra space for variables to store the numerator, denominator, and intermediate results.
    // Approach:
    //  1. We initialize the numerator and denominator of the result fraction to 0 and 1, respectively.
    //  2. We iterate through the input string expression, parsing each fraction and updating the result fraction accordingly.
    //  3. For each fraction, we extract the numerator and denominator, taking care of the sign.
    //  4. We update the result fraction using the formula: num = num * denominator + numerator * den, and den = den * denominator.
    //  5. We simplify the result fraction by dividing both the numerator and denominator by their greatest common divisor (GCD).
    //  6. Finally, we return the result fraction in the form "numerator/denominator".
    string fractionAddition(string expression)
    {
        long long num = 0, den = 1;
        int i = 0, n = expression.size();
        while (i < n)
        {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-')
            {
                if (expression[i] == '-')
                    sign = -1;
                i++;
            }
            long long numerator = 0;
            while (i < n && isdigit(expression[i]))
            {
                numerator = numerator * 10 + (expression[i] - '0');
                i++;
            }
            numerator *= sign;
            i++; // skip '/'
            long long denominator = 0;
            while (i < n && isdigit(expression[i]))
            {
                denominator = denominator * 10 + (expression[i] - '0');
                i++;
            }
            num = num * denominator + numerator * den;
            den *= denominator;
            long long g = __gcd(abs(num), den);
            if (g > 0)
            {
                num /= g;
                den /= g;
            }
        }
        if (num == 0)
            den = 1;
        return to_string(num) + "/" + to_string(den);
    }
};
