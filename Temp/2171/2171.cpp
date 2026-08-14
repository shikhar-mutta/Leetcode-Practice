// Link: https://leetcode.com/problems/removing-minimum-number-of-magic-beans/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        sort(beans.begin(), beans.end());
        long long total = accumulate(beans.begin(), beans.end(), 0LL);
        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long keep = (long long)beans[i] * (n - i);
            best = max(best, keep);
        }
        return total - best;
    }
};
