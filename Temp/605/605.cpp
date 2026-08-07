// Link: https://leetcode.com/problems/can-place-flowers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m) SC: O(1)
// Approach: greedily scan; plant at position i if it's empty and both neighbors (or boundary) are empty.
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i-1] == 0) &&
                (i == m-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};
