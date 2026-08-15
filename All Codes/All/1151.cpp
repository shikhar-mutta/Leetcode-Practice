// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int ones = accumulate(data.begin(), data.end(), 0);
        if (ones == 0) return 0;
        int curOnes = 0;
        for (int i = 0; i < ones; i++) curOnes += data[i];
        int maxOnes = curOnes;
        for (int i = ones; i < n; i++) {
            curOnes += data[i] - data[i - ones];
            maxOnes = max(maxOnes, curOnes);
        }
        return ones - maxOnes;
    }
};
