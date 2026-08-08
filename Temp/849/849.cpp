// Link: https://leetcode.com/problems/maximize-distance-to-closest-person/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prev = -1, best = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prev == -1) best = max(best, i);
                else best = max(best, (i - prev) / 2);
                prev = i;
            }
        }
        best = max(best, n - 1 - prev);
        return best;
    }
};
