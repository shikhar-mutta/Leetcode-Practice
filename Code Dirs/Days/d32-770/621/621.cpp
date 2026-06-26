// Link: https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int freq[26] = {0};
        for (char c : tasks)
            freq[c - 'A']++;

        int maxFreq = *max_element(freq, freq + 26);
        int maxCount = count(freq, freq + 26, maxFreq);

        int slots = (maxFreq - 1) * (n + 1) + maxCount;

        return max(slots, (int)tasks.size());
    }
};
