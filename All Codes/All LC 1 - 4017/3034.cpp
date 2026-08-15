// Link: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(n)
// Approach: Encode nums as a trend array s[i] in {-1,0,1} comparing each
// adjacent pair, then brute-force count positions where a length-m window
// of s matches pattern exactly.
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int> s(n - 1);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i])
                s[i] = 1;
            else if (nums[i + 1] < nums[i])
                s[i] = -1;
            else
                s[i] = 0;
        }

        int count = 0;
        for (int i = 0; i + m <= (int)s.size(); i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (s[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                count++;
        }
        return count;
    }
};
