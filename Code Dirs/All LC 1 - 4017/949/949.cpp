// Link: https://leetcode.com/problems/largest-time-for-given-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int best = -1;
        do {
            int h = arr[0] * 10 + arr[1];
            int m = arr[2] * 10 + arr[3];
            if (h < 24 && m < 60) {
                int total = h * 60 + m;
                best = max(best, total);
            }
        } while (next_permutation(arr.begin(), arr.end()));

        if (best == -1) return "";
        char buf[6];
        snprintf(buf, sizeof(buf), "%02d:%02d", best / 60, best % 60);
        return string(buf);
    }
};
