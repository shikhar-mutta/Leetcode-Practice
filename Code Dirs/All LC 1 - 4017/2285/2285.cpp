// Link: https://leetcode.com/problems/maximum-total-importance-of-roads/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (auto& r : roads) { degree[r[0]]++; degree[r[1]]++; }
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return degree[a] < degree[b]; });
        vector<long long> value(n);
        for (int i = 0; i < n; i++) value[idx[i]] = i + 1;
        long long total = 0;
        for (auto& r : roads) total += value[r[0]] + value[r[1]];
        return total;
    }
};
