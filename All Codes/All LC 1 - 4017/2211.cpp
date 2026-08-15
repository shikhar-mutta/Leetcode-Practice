// Link: https://leetcode.com/problems/count-collisions-on-a-road/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: leading L's (nothing to their left to collide with) and
// trailing R's (nothing to their right) can never be involved in a
// collision, so trim them off both ends. Every car left in the remaining
// middle range must eventually collide (an R will hit something moving
// left or stopped ahead of it, an L will hit something to its left, and an
// S sits in the path of oncoming cars from both directions), so the answer
// is just the count of non-S cars in that trimmed range.
class Solution {
public:
    int countCollisions(string directions) {

        int n = directions.size();

        int left = 0;

        while (left < n && directions[left] == 'L')
            left++;

        int right = n - 1;

        while (right >= 0 && directions[right] == 'R')
            right--;

        int ans = 0;

        for (int i = left; i <= right; i++)
            if (directions[i] != 'S')
                ans++;

        return ans;
    }
};
