// Link: https://leetcode.com/problems/grumpy-bookstore-owner/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int base = 0;
        for (int i = 0; i < n; i++) if (!grumpy[i]) base += customers[i];

        int windowGain = 0, bestGain = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i]) windowGain += customers[i];
            if (i >= minutes && grumpy[i - minutes]) windowGain -= customers[i - minutes];
            bestGain = max(bestGain, windowGain);
        }
        return base + bestGain;
    }
};
