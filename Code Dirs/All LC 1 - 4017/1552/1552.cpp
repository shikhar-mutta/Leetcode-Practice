// Link: https://leetcode.com/problems/magnetic-force-between-two-balls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1, last = position[0];
        for (int i = 1; i < (int)position.size(); i++) {
            if (position[i] - last >= dist) { count++; last = position[i]; }
        }
        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1, hi = position.back() - position.front();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (canPlace(position, m, mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
