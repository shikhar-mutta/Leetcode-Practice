// Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/description/

#include <bits/stdc++.h>
using namespace std;

array<vector<int>, 5> freq3445;
int n3445;

class Solution {
public:
    static int maxD_ab(int a, int b, int k) {
        int cnt = INT_MIN;
        const int INF = 1e8;
        int minFreq[2][2] = {{INF, INF}, {INF, INF}};
        int freq_a = 0, freq_b = 0, prev_a = 0, prev_b = 0;
        for (int l = 0, r = k - 1; r < n3445; r++) {
            freq_a = freq3445[a][r + 1], freq_b = freq3445[b][r + 1];
            while (r - l + 1 >= k && freq_b - prev_b >= 2) {
                minFreq[prev_a & 1][prev_b & 1] =
                    min(minFreq[prev_a & 1][prev_b & 1], prev_a - prev_b);
                prev_a = freq3445[a][l + 1];
                prev_b = freq3445[b][l + 1];
                l++;
            }
            cnt = max(cnt,
                      freq_a - freq_b - minFreq[1 - (freq_a & 1)][freq_b & 1]);
        }
        return cnt;
    }

    int maxDifference(string s, int k) {
        n3445 = s.size();
        freq3445.fill(vector<int>(n3445 + 1, 0));
        for (int i = 0; i < n3445; i++) {
            for (int d = 0; d <= 4; d++)
                freq3445[d][i + 1] = freq3445[d][i];
            freq3445[s[i] - '0'][i + 1]++;
        }

        int ans = INT_MIN;
        for (int a = 0; a <= 4; a++) {
            if (freq3445[a][n3445] == 0) continue;
            for (int b = 0; b <= 4; b++) {
                if (a == b || freq3445[b][n3445] == 0) continue;
                ans = max(ans, maxD_ab(a, b, k));
            }
        }

        return ans;
    }
};
