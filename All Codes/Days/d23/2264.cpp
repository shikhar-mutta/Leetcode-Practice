// Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string best = "";
        // check every window of 3; keep the largest run of equal digits
        for (int i = 0; i + 2 < (int)num.size(); i++)
            if (num[i] == num[i + 1] && num[i] == num[i + 2])
                best = max(best, num.substr(i, 3));
        return best;
    }
};
