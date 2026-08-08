// Link: https://leetcode.com/problems/jewels-and-stones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(j+s) SC: O(j)
// Approach: put jewel chars in a set, count matching stones.
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jset(jewels.begin(), jewels.end());
        int count = 0;
        for (char c : stones) if (jset.count(c)) count++;
        return count;
    }
};
