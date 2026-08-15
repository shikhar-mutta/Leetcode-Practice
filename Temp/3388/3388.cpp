// Link: https://leetcode.com/problems/count-beautiful-splits-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<short>> lcp(n, vector<short>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (nums[i] == nums[j]) {
                    int nxt = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] : 0;
                    lcp[i][j] = (short)min(1 + nxt, n);
                }
            }
        }

        long long count = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                bool a = (i <= j - i) && lcp[0][i] >= i;
                bool b = (j - i <= n - j) && lcp[i][j] >= (j - i);
                if (a || b) count++;
            }
        }
        return (int)count;
    }
};
