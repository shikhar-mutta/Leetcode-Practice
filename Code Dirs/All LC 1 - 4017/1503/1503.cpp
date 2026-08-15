// Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int best = 0;
        for (int x : left) best = max(best, x);
        for (int x : right) best = max(best, n - x);
        return best;
    }
};
