// Link: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii/description/

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
        vector<int> fail(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i-1];
            while (j > 0 && pattern[i] != pattern[j]) j = fail[j-1];
            if (pattern[i] == pattern[j]) j++;
            fail[i] = j;
        }
        int cnt = 0, j = 0;
        for (int i = 0; i < (int)cmp.size(); i++) {
            while (j > 0 && cmp[i] != pattern[j]) j = fail[j-1];
            if (cmp[i] == pattern[j]) j++;
            if (j == m) { cnt++; j = fail[j-1]; }
        }
        return cnt;
    }
};
