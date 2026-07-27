// Link: https://leetcode.com/problems/split-and-merge-array-transformation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^6) states * O(n^2) transitions, tiny since n<=6 SC: same
// Approach: BFS over full array states (n<=6 keeps the state space
// small). From each state, try every (l,r) subarray removal and every
// reinsertion position into the remainder, generating all reachable
// next states; standard shortest-path BFS to the target.
class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (nums1 == nums2) return 0;

        queue<vector<int>> q;
        set<vector<int>> visited;
        q.push(nums1);
        visited.insert(nums1);
        int steps = 0;

        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                vector<int> cur = q.front(); q.pop();
                for (int l = 0; l < n; l++) {
                    for (int r = l; r < n; r++) {
                        vector<int> sub(cur.begin() + l, cur.begin() + r + 1);
                        vector<int> remain;
                        for (int i = 0; i < n; i++) if (i < l || i > r) remain.push_back(cur[i]);
                        for (int pos = 0; pos <= (int)remain.size(); pos++) {
                            vector<int> nxt(remain.begin(), remain.begin() + pos);
                            nxt.insert(nxt.end(), sub.begin(), sub.end());
                            nxt.insert(nxt.end(), remain.begin() + pos, remain.end());
                            if (nxt == nums2) return steps;
                            if (!visited.count(nxt)) { visited.insert(nxt); q.push(nxt); }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
