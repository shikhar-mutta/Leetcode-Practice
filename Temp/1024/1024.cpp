// Link: https://leetcode.com/problems/video-stitching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> maxReach(time + 1, 0);
        for (auto& c : clips) {
            if (c[0] <= time) maxReach[c[0]] = max(maxReach[c[0]], c[1]);
        }
        int count = 0, curEnd = 0, nextEnd = 0;
        for (int i = 0; i < time; i++) {
            nextEnd = max(nextEnd, maxReach[i]);
            if (i == curEnd) {
                if (nextEnd <= i) return -1;
                count++;
                curEnd = nextEnd;
            }
        }
        return count;
    }
};
