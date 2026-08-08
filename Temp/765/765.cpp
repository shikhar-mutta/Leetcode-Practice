// Link: https://leetcode.com/problems/couples-holding-hands/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: track position of each person; for each pair of adjacent seats, if the partner isn't seated next, swap it into place (using position map), counting swaps.
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[row[i]] = i;
        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int partner = row[i] ^ 1;
            if (row[i+1] != partner) {
                int j = pos[partner];
                swap(row[i+1], row[j]);
                pos[row[j]] = j;
                pos[row[i+1]] = i+1;
                swaps++;
            }
        }
        return swaps;
    }
};
