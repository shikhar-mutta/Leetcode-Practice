// Link: https://leetcode.com/problems/shopping-offers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(offers^items) small SC: O(recursion depth)
// Approach: recursive DFS with memoization on needs vector; baseline is buying items individually at price; try applying each special offer (if it doesn't exceed any need) and recurse on the reduced needs.
class Solution {
    map<vector<int>, int> memo;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (memo.count(needs)) return memo[needs];
        int n = price.size();
        int best = 0;
        for (int i = 0; i < n; i++) best += price[i] * needs[i];
        for (auto& offer : special) {
            bool valid = true;
            vector<int> next(needs);
            for (int i = 0; i < n; i++) {
                if (offer[i] > next[i]) { valid = false; break; }
                next[i] -= offer[i];
            }
            if (!valid) continue;
            int cost = offer[n] + shoppingOffers(price, special, next);
            best = min(best, cost);
        }
        memo[needs] = best;
        return best;
    }
};
