// Link: https://leetcode.com/problems/maximum-containers-on-a-ship/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: the ship has n*n slots, each holding a container of weight w;
// the answer is capped both by the number of slots and by how many
// weight-w containers fit under maxWeight.
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        long long slots = (long long)n * n;
        long long byWeight = maxWeight / w;
        return (int)min(slots, byWeight);
    }
};
