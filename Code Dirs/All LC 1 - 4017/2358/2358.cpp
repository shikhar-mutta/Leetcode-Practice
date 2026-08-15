// Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int k = 0;
        while ((long long)(k + 1) * (k + 2) / 2 <= n) k++;
        return k;
    }
};
