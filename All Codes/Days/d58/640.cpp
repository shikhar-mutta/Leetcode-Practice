// Link: https://leetcode.com/problems/solve-the-equation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the equation string.
    // SC: O(1), constant space used for variables.
    // Approach: String parsing and algebraic manipulation.
    //  1. Split the equation into left and right sides based on the '=' character.
    //  2. For each side, parse the terms to calculate the total coefficient of 'x' and the total constant term.
    //  3. Rearrange the equation to isolate 'x' on one side and the constant on the other.
    //  4. Determine the solution based on the coefficients and constants. If the coefficient of 'x' is zero, check if the constant is also zero for infinite solutions, otherwise no solution. If the coefficient is non-zero, calculate the value of 'x' and return it in the required format.
    //  5. Return the solution as a string.
    void parseSide(const string &s, int &coef, int &constant)
    {
        int i = 0, n = s.size();
        while (i < n)
        {
            int sign = 1;
            if (s[i] == '+')
                i++;
            else if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            int num = 0;
            bool hasNum = false;
            while (i < n && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
                hasNum = true;
            }
            if (i < n && s[i] == 'x')
            {
                coef += sign * (hasNum ? num : 1);
                i++;
            }
            else
            {
                constant += sign * num;
            }
        }
    }

    string solveEquation(string equation)
    {
        int pos = equation.find('=');
        string left = equation.substr(0, pos);
        string right = equation.substr(pos + 1);

        int coefL = 0, constL = 0, coefR = 0, constR = 0;
        parseSide(left, coefL, constL);
        parseSide(right, coefR, constR);

        int coef = coefL - coefR;
        int constant = constR - constL;

        if (coef == 0)
        {
            return constant == 0 ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string(constant / coef);
    }
};
