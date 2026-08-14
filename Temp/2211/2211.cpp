// Link: https://leetcode.com/problems/count-collisions-on-a-road/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0, r = n - 1;
        while (l < n && directions[l] == 'L') l++;
        while (r >= 0 && directions[r] == 'R') r--;
        int count = 0;
        for (int i = l; i <= r; i++) if (directions[i] != 'S') count++;
        return count;
    }
};
