// Link: https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: count existing "LCT" subsequences directly (for each 'C',
// multiply count of 'L' before it by count of 'T' after it). Inserting
// one extra letter can only add MORE "LCT"s by inserting at the position
// giving the best "LC" count (if we insert a T), best "CT" count (insert
// an L), or best L*R split (insert a C in the middle of the best gap) —
// take the max of these three and add to the base count.
class Solution {
    long long calc(const string& s, char a, char b) {
        long long cnt = 0, cntA = 0;
        for (char c : s) {
            if (c == b) cnt += cntA;
            if (c == a) cntA++;
        }
        return cnt;
    }
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        int totalT = 0;
        for (char c : s) if (c == 'T') totalT++;

        long long l = 0, r = totalT, ans = 0, mx = 0;
        for (char c : s) {
            if (c == 'T') r--;
            if (c == 'C') ans += l * r;
            if (c == 'L') l++;
            mx = max(mx, l * r);
        }
        mx = max({mx, calc(s, 'L', 'C'), calc(s, 'C', 'T')});
        return ans + mx;
    }
};
