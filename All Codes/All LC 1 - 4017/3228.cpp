// Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Track a running count of 1s seen so far (cnt1). Each time a
// "10" boundary occurs (current char is 0, previous was 1), every 1 seen so
// far can be moved past this point, contributing cnt1 operations.
class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0, n = s.size(), cnt1 = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                cnt1++;
            else if (s[i - 1] == '1')
                cnt += cnt1;
        }
        return cnt;
    }
};
