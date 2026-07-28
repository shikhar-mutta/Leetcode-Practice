// Link: https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(1) extra
// Approach: sort intervals by end ascending (ties by start descending),
// then greedily pick points from the right end of each interval.
// Track the last two chosen points p1<p2; if the interval starts after
// both, add its two rightmost points (e-1, e); if it starts after only
// p1, add one point (e); otherwise it's already satisfied.
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        int p1 = -1, p2 = -1, ans = 0;
        for (auto& iv : intervals) {
            int s = iv[0], e = iv[1];
            if (s > p2) {
                ans += 2;
                p1 = e - 1;
                p2 = e;
            } else if (s > p1) {
                ans += 1;
                p1 = p2;
                p2 = e;
            }
        }
        return ans;
    }
};
