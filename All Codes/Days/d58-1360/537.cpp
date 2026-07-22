// Link: https://leetcode.com/problems/complex-number-multiplication/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    // Approach:
    //  1. Parse the input strings to extract the real and imaginary parts of the complex numbers.
    //  2. Use the formula for multiplying complex numbers: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    //  3. Return the result as a string in the format "real+imagi".
    string complexNumberMultiply(string num1, string num2)
    {
        auto parse = [](const string &s)
        {
            int plus = s.find('+');
            int real = stoi(s.substr(0, plus));
            int imag = stoi(s.substr(plus + 1, s.size() - plus - 2));
            return make_pair(real, imag);
        };
        auto [a1, b1] = parse(num1);
        auto [a2, b2] = parse(num2);
        int real = a1 * a2 - b1 * b2;
        int imag = a1 * b2 + a2 * b1;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};
