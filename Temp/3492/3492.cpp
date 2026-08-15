// Link: https://leetcode.com/problems/maximum-containers-on-a-ship/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        long long cap = (long long)n * n;
        long long byWeight = (long long)maxWeight / w;
        return (int)min(cap, byWeight);
    }
};
