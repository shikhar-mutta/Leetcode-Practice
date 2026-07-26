// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits(num))
// SC: O(digits(num))
// Approach: to maximize, remap the first non-9 digit (its every
// occurrence) to 9 — the earliest such digit gives the biggest gain,
// and if all digits are already 9 no remap helps. To minimize, remap
// every occurrence of the leading digit to 0, since that digit has the
// most significant weight. The answer is the difference of the two.
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // maximum: change first non-9 digit to 9
        string hi = s;
        char toReplace = 0;
        for (char c : s) {
            if (c != '9') {
                toReplace = c;
                break;
            }
        }
        if (toReplace)
            for (char& c : hi)
                if (c == toReplace)
                    c = '9';

        // minimum: change first digit to 0
        string lo = s;
        char first = s[0];
        for (char& c : lo)
            if (c == first)
                c = '0';

        return stoi(hi) - stoi(lo);
    }
};
