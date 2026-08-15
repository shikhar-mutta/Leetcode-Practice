// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCnt = 0, oddCnt = 0;
        for (int x : nums) (x % 2 == 0 ? evenCnt : oddCnt)++;
        int best = max(evenCnt, oddCnt);

        int last = -1, alt = 0;
        for (int x : nums) {
            int p = x % 2;
            if (p != last) { alt++; last = p; }
        }
        best = max(best, alt);
        return best;
    }
};
