// Link: https://leetcode.com/problems/minimum-processing-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());
        int ans = 0;
        for (int i = 0; i < (int)processorTime.size(); i++)
            ans = max(ans, processorTime[i] + tasks[i * 4]);
        return ans;
    }
};
