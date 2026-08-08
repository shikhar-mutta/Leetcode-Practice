// Link: https://leetcode.com/problems/maximum-equal-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> cnt;
        unordered_map<int,int> freqCount;
        int maxFreq = 0, best = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i];
            if (cnt[x] > 0) freqCount[cnt[x]]--;
            cnt[x]++;
            freqCount[cnt[x]]++;
            maxFreq = max(maxFreq, cnt[x]);

            int len = i + 1;
            if (maxFreq == 1) {
                best = len;
            } else if (freqCount[maxFreq] == 1 && freqCount[maxFreq-1] * (maxFreq-1) + maxFreq == len) {
                best = len;
            } else if (freqCount[maxFreq] * maxFreq == len - 1) {
                best = len;
            }
        }
        return best;
    }
};
