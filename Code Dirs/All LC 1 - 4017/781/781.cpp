// Link: https://leetcode.com/problems/rabbits-in-forest/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: group counts of each answer value; for answer v, each group of (v+1) rabbits sharing that answer requires ceil(count/(v+1)) groups, each contributing (v+1) rabbits.
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> cnt;
        for (int a : answers) cnt[a]++;
        int total = 0;
        for (auto& [v, c] : cnt) {
            int groupSize = v+1;
            int groups = (c + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }
        return total;
    }
};
