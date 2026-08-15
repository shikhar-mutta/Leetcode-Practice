// Link: https://leetcode.com/problems/solve-the-equation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: split on '=', parse each side accumulating coefficient of x and constant separately (tokenize by sign, detect trailing 'x'), then solve coefX * x + constX = 0 form after moving right side to left.
class Solution {
    pair<long long,long long> parseSide(const string& s) {
        long long coef = 0, cons = 0;
        int i = 0, n = s.size();
        while (i < n) {
            int sign = 1;
            if (s[i] == '+') i++;
            else if (s[i] == '-') { sign = -1; i++; }
            int start = i;
            while (i < n && isdigit(s[i])) i++;
            string numStr = s.substr(start, i-start);
            if (i < n && s[i] == 'x') {
                long long val = numStr.empty() ? 1 : stoll(numStr);
                coef += sign * val;
                i++;
            } else {
                long long val = stoll(numStr);
                cons += sign * val;
            }
        }
        return {coef, cons};
    }
public:
    string solveEquation(string equation) {
        int eq = equation.find('=');
        string left = equation.substr(0, eq), right = equation.substr(eq+1);
        auto [lc, lco] = parseSide(left);
        auto [rc, rco] = parseSide(right);
        long long coef = lc - rc;
        long long cons = rco - lco;
        if (coef == 0) {
            return cons == 0 ? "Infinite solutions" : "No solution";
        }
        return "x=" + to_string(cons / coef);
    }
};
