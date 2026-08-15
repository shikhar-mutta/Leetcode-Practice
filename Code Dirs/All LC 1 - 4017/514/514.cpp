// Link: https://leetcode.com/problems/freedom-trail/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(key.size() * ring.size()^2)  SC: O(ring.size())
// Approach: DP over (key index, ring position); for each occurrence of the
// current key char in the ring, take the min rotation distance from every
// previous position, +1 for the button press
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[ring[i]].push_back(i);

        vector<int> dp(n, 0);
        vector<int> cur = {0}; // start positions (ring index 0)

        for (char k : key) {
            vector<int> next;
            vector<int> ndp(n, INT_MAX);
            for (int np : pos[k]) {
                int best = INT_MAX;
                for (int cp : cur) {
                    int dist = abs(np - cp);
                    dist = min(dist, n - dist);
                    best = min(best, dp[cp] + dist + 1);
                }
                ndp[np] = best;
                next.push_back(np);
            }
            dp = ndp;
            cur = next;
        }

        int result = INT_MAX;
        for (int p : cur) result = min(result, dp[p]);
        return result;
    }
};
