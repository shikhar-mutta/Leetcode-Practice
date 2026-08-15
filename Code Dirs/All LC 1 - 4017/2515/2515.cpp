// Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                best = min(best, dist);
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};
