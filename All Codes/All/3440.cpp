// Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n + 1);
        gaps[0] = startTime[0] - 0;
        for (int i = 1; i < n; i++) gaps[i] = startTime[i] - endTime[i-1];
        gaps[n] = eventTime - endTime[n-1];

        vector<int> prefMax(n + 1), sufMax(n + 1);
        prefMax[0] = gaps[0];
        for (int i = 1; i <= n; i++) prefMax[i] = max(prefMax[i-1], gaps[i]);
        sufMax[n] = gaps[n];
        for (int i = n - 1; i >= 0; i--) sufMax[i] = max(sufMax[i+1], gaps[i]);

        int ans = 0;
        for (int g : gaps) ans = max(ans, g);

        for (int i = 0; i < n; i++) {
            int dur = endTime[i] - startTime[i];
            long long merged = (long long)gaps[i] + dur + gaps[i+1];
            int otherMax = 0;
            if (i - 1 >= 0) otherMax = max(otherMax, prefMax[i-1]);
            if (i + 2 <= n) otherMax = max(otherMax, sufMax[i+2]);
            long long candidate = (otherMax >= dur) ? merged : merged - dur;
            ans = max(ans, (int)candidate);
        }

        return ans;
    }
};
