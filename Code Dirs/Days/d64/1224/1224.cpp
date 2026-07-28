// Link: https://leetcode.com/problems/maximum-equal-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: scan left to right maintaining count[value] and
// freqOfFreq[c] = how many distinct values currently have count c, plus
// the running maxFreq. A prefix of length L is valid (one removal makes
// all counts equal) if: (1) maxFreq==1 (everything distinct), or
// (2) exactly one value has the max frequency and all others share
// count maxFreq-1 (remove one occurrence of the max), or (3) removing
// one entire value that appears exactly once leaves everyone else at
// the same maxFreq.
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int> count;
        unordered_map<int,int> freqOfFreq;
        int maxFreq = 0, res = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int num = nums[i];
            if (count[num] > 0) freqOfFreq[count[num]]--;
            count[num]++;
            freqOfFreq[count[num]]++;
            maxFreq = max(maxFreq, count[num]);
            int length = i + 1;

            if (maxFreq == 1) {
                res = length;
            } else if (freqOfFreq[maxFreq] * maxFreq == length - 1) {
                res = length;
            } else if (freqOfFreq[maxFreq] == 1 &&
                       freqOfFreq[maxFreq - 1] * (maxFreq - 1) == length - maxFreq) {
                res = length;
            }
        }
        return res;
    }
};
