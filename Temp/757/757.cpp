// Link: https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(1)
// Approach: sort intervals by end ascending (start descending on tie). Greedily track the two largest chosen points (p1 < p2). For each interval, if p2 not in range add point 'end' and 'end-1' if p1 wasn't in range either; if only p2 in range add one more point at 'end'; shift p1/p2 accordingly.
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });
        int p1 = -1, p2 = -1;
        int count = 0;
        for (auto& iv : intervals) {
            int s = iv[0], e = iv[1];
            if (s <= p1) continue; // both points already inside
            if (s <= p2) {
                // p2 inside, need one more point
                p1 = p2;
                p2 = e;
                count++;
            } else {
                p1 = e - 1;
                p2 = e;
                count += 2;
            }
        }
        return count;
    }
};
