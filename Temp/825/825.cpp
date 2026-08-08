// Link: https://leetcode.com/problems/friends-of-appropriate-ages/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(120^2 + n) SC: O(120)
// Approach: bucket count by age (1-120); for each pair of ages (a,b) satisfying the request condition (b > 0.5a+7, b<=a, and not(a<100 and b>150) which is implied), add count[a]*count[b] (minus 1 if a==b for self-exclusion).
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int cnt[121] = {0};
        for (int a : ages) cnt[a]++;
        int total = 0;
        for (int a = 1; a <= 120; a++) {
            if (cnt[a] == 0) continue;
            for (int b = 1; b <= 120; b++) {
                if (cnt[b] == 0) continue;
                if (b <= 0.5*a + 7) continue;
                if (b > a) continue;
                if (a == b) total += cnt[a] * (cnt[a]-1);
                else total += cnt[a] * cnt[b];
            }
        }
        return total;
    }
};
