// Link: https://leetcode.com/problems/minimum-levels-to-gain-more-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Each level scores +1 (possible) or -1 (impossible). Compute the
// total score, then scan prefix sums for Alice's levels 0..i; the first
// prefix where aliceScore > (totalScore - aliceScore) is the minimum count
// of levels Alice must take.
class Solution {
public:
    int minimumLevels(std::vector<int>& possible) {
        int n = possible.size();

        // Compute total score for all levels combined
        int totalScore = 0;
        for (int p : possible) {
            totalScore += (p == 1) ? 1 : -1;
        }

        int aliceScore = 0;

        // Alice plays levels 0 to i (where Bob gets at least 1 level, so i < n
        // - 1)
        for (int i = 0; i < n - 1; ++i) {
            aliceScore += (possible[i] == 1) ? 1 : -1;
            int bobScore = totalScore - aliceScore;

            if (aliceScore > bobScore) {
                return i + 1; // Number of levels Alice plays
            }
        }

        return -1;
    }
};
