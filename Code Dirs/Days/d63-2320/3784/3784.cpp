// Link: https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: keeping all characters equal to some letter c costs the sum
// of deletion costs of every other letter. Sum cost per letter (26
// buckets), then the answer is total sum minus the largest bucket (keep
// the letter that's cheapest to preserve).
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long perChar[26] = {}, total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            perChar[s[i]-'a'] += cost[i];
            total += cost[i];
        }
        long long best = *max_element(perChar, perChar + 26);
        return total - best;
    }
};
