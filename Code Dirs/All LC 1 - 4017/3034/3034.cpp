// Link: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        vector<int> cmp(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] > nums[i]) cmp[i] = 1;
            else if (nums[i+1] < nums[i]) cmp[i] = -1;
            else cmp[i] = 0;
        }
        int m = pattern.size();
        int cnt = 0;
        for (int i = 0; i + m <= (int)cmp.size(); i++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (cmp[i+j] != pattern[j]) { ok = false; break; }
            }
            if (ok) cnt++;
        }
        return cnt;
    }
};
