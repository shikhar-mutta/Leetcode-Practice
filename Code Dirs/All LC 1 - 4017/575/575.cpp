// Link: https://leetcode.com/problems/distribute-candies/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: Count unique candy types with a set; answer is min(n/2, unique count).
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniq(candyType.begin(), candyType.end());
        return min((int)candyType.size() / 2, (int)uniq.size());
    }
};
