// Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: since arr is a permutation of 0..n-1, track running max; a chunk can close whenever running max equals the current index.
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxSoFar = 0;
        for (int i = 0; i < (int)arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) chunks++;
        }
        return chunks;
    }
};
