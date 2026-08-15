// Link: https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26*len) SC: O(26)
// Approach: count task frequencies; the answer is max(len, (maxFreq-1)*(n+1) + numTasksWithMaxFreq), the formula for idle-slot scheduling.
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (char c : tasks) cnt[c-'A']++;
        int maxFreq = *max_element(cnt, cnt+26);
        int numMax = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] == maxFreq) numMax++;
        int formula = (maxFreq-1)*(n+1) + numMax;
        return max((int)tasks.size(), formula);
    }
};
