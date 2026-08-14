// Link: https://leetcode.com/problems/find-the-maximum-divisibility-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int best = divisors[0], bestCount = -1;
        for (int d : divisors) {
            int count = 0;
            for (int x : nums) if (x % d == 0) count++;
            if (count > bestCount || (count == bestCount && d < best)) {
                bestCount = count;
                best = d;
            }
        }
        return best;
    }
};
