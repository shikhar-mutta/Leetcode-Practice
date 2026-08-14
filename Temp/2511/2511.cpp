// Link: https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size();
        int best = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (forts[i] == 1 || forts[i] == -1) {
                if (last != -1 && forts[last] != forts[i]) {
                    best = max(best, i - last - 1);
                }
                last = i;
            }
        }
        return best;
    }
};
