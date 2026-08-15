// Link: https://leetcode.com/problems/fraction-addition-and-subtraction/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(max)) SC: O(n)
// Approach: parse signed num/den pairs via regex, accumulate as a running fraction with common-denominator addition, reduce by gcd at the end.
class Solution {
public:
    string fractionAddition(string expression) {
        long long num = 0, den = 1;
        int i = 0, n = expression.size();
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }
            long long a = 0;
            while (i < n && isdigit(expression[i])) { a = a*10 + (expression[i]-'0'); i++; }
            i++; // skip '/'
            long long b = 0;
            while (i < n && isdigit(expression[i])) { b = b*10 + (expression[i]-'0'); i++; }
            a *= sign;
            num = num*b + a*den;
            den = den*b;
            long long g = __gcd(abs(num), den);
            if (g > 0) { num /= g; den /= g; }
        }
        if (den < 0) { den = -den; num = -num; }
        return to_string(num) + "/" + to_string(den);
    }
};
