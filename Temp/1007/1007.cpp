// Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int res = tryValue(tops[0], tops, bottoms);
        if (res != -1) return res;
        res = tryValue(bottoms[0], tops, bottoms);
        return res;
    }

private:
    int tryValue(int val, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotTop = 0, rotBottom = 0;
        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val) return -1;
            if (tops[i] != val) rotTop++;
            else if (bottoms[i] != val) rotBottom++;
        }
        return min(rotTop, rotBottom);
    }
};
