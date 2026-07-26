// Link: https://leetcode.com/problems/number-of-common-factors/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(g)) where g = gcd(a, b)
// SC: O(1)
// Approach: any common divisor of a and b must divide gcd(a, b), and
// conversely every divisor of gcd(a, b) divides both a and b. So count
// the divisors of g = gcd(a, b) by trial division up to sqrt(g), counting
// each divisor pair (d, g/d) once (or once total when d == g/d).
class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int count = 0;
        for (int d = 1; (long long)d * d <= g; ++d) {
            if (g % d == 0) {
                count +=
                    (d == g / d) ? 1 : 2; // count both divisors of the pair
            }
        }
        return count;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
};
