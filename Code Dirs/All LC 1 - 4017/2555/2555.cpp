// Link: https://leetcode.com/problems/maximize-win-from-two-segments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        if (n == 0) return 0;
        vector<int> dp(n, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) left++;
            int cnt = right - left + 1;
            int bestSoFar = (right > 0) ? dp[right-1] : 0;
            bestSoFar = max(bestSoFar, cnt);
            dp[right] = bestSoFar;
            int prevBest = (left > 0) ? dp[left-1] : 0;
            ans = max(ans, cnt + prevBest);
        }
        return ans;
    }
};
