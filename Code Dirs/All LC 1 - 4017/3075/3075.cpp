// Link: https://leetcode.com/problems/maximize-happiness-of-selected-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long total = 0;
        for (int i = 0; i < k; i++) {
            total += max(0, happiness[i] - i);
        }
        return total;
    }
};
