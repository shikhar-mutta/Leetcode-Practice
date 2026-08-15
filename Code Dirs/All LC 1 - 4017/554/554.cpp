// Link: https://leetcode.com/problems/brick-wall/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total bricks)  SC: O(total bricks)
// Approach: count internal edge positions (running sum excluding the last
// brick) across all rows; the position with the most edges minimizes cuts
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> edgeCount;
        for (auto& row : wall) {
            int sum = 0;
            for (int i = 0; i < (int)row.size() - 1; i++) {
                sum += row[i];
                edgeCount[sum]++;
            }
        }
        int maxEdges = 0;
        for (auto& [pos, cnt] : edgeCount) maxEdges = max(maxEdges, cnt);
        return wall.size() - maxEdges;
    }
};
