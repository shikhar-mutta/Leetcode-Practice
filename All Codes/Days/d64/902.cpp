// Link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(len(n) * len(digits))  SC: O(1)
// Approach: count all numbers with fewer digits than n freely (each
// position has |digits| choices), then for numbers with the same digit
// count as n, walk position by position: for each position, count how
// many allowed digits are strictly less than n's digit (those complete
// freely for remaining positions); if n's digit itself is allowed,
// continue to the next position, else stop (no further matches at this
// length beyond what's counted). If the walk completes, n itself
// (fully matched by the digit set) counts too.
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int L = s.size(), D = digits.size();

        long long total = 0;
        long long pow_ = 1;
        for (int len = 1; len < L; len++) {
            pow_ *= D;
            total += pow_;
        }

        bool matchedFull = true;
        for (int i = 0; i < L; i++) {
            int cur = s[i] - '0';
            long long lessCount = 0;
            bool hasEqual = false;
            for (auto& d : digits) {
                int dv = d[0] - '0';
                if (dv < cur) lessCount++;
                else if (dv == cur) hasEqual = true;
            }
            long long remainingPow = 1;
            for (int k = 0; k < L - i - 1; k++) remainingPow *= D;
            total += lessCount * remainingPow;
            if (!hasEqual) { matchedFull = false; break; }
        }
        if (matchedFull) total += 1;
        return (int)total;
    }
};
