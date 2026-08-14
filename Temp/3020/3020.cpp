// Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums) freq[x]++;

        int ans = 0;
        if (freq.count(1)) {
            int f = freq[1];
            ans = max(ans, f % 2 == 0 ? f - 1 : f);
        }

        for (auto& [v, c] : freq) {
            if (v == 1) continue;
            long long cur = v;
            int chainCount = 0;
            while (freq.count(cur) && freq[cur] >= 2 && freq.count(cur * cur)) {
                chainCount++;
                cur = cur * cur;
            }
            int length = 2 * chainCount;
            if (freq.count(cur) && freq[cur] >= 1) length++;
            ans = max(ans, length);
        }
        return ans;
    }
};
