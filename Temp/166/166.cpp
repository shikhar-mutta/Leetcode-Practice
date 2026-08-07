// Link: https://leetcode.com/problems/fraction-to-recurring-decimal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(denominator) worst case  SC: O(denominator)
// Approach: long division; track remainder-position map to detect a repeating cycle and wrap it in parens
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) != (denominator < 0)) res += "-";
        long long num = abs((long long)numerator), den = abs((long long)denominator);
        res += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return res;
        res += ".";
        unordered_map<long long,int> seen;
        string frac;
        while (rem != 0) {
            if (seen.count(rem)) {
                frac.insert(seen[rem], "(");
                frac += ")";
                break;
            }
            seen[rem] = frac.size();
            rem *= 10;
            frac += to_string(rem / den);
            rem %= den;
        }
        return res + frac;
    }
};
