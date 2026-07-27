// Link: https://leetcode.com/problems/two-letter-card-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1) (10-letter alphabet)
// Approach: cards containing x split into: "xx" (Z, matches with any A
// or B card), "x?" with ?!=x (group A, keyed by the other letter), and
// "?x" with ?!=x (group B). Two A-cards are compatible iff their letters
// differ; same for B; a Z-card is compatible with ANY A or B card;
// A-cards are never compatible with B-cards. Maximizing same-group
// distinct-letter pairs first (ratio 1 pair per 2 cards, optimal) then
// using Z cards to mop up the leftover unmatched A/B cards is optimal —
// spending a Z card on a card that could've paired internally never
// helps. Distinct-letter max pairing count for a multiset of counts is
// min(total/2, total - maxCount).
class Solution {
    int maxDistinctPairs(vector<int>& counts, int& leftover) {
        int total = 0, mx = 0;
        for (int c : counts) { total += c; mx = max(mx, c); }
        int pairs = min(total / 2, total - mx);
        leftover = total - 2 * pairs;
        return pairs;
    }
public:
    int score(vector<string>& cards, char x) {
        vector<int> countA(26, 0), countB(26, 0);
        int z = 0;
        for (auto& c : cards) {
            bool has0 = (c[0] == x), has1 = (c[1] == x);
            if (has0 && has1) z++;
            else if (has0) countA[c[1] - 'a']++;
            else if (has1) countB[c[0] - 'a']++;
        }
        int leftoverA, leftoverB;
        int pairsA = maxDistinctPairs(countA, leftoverA);
        int pairsB = maxDistinctPairs(countB, leftoverB);
        int zUsed = min(z, leftoverA + leftoverB);
        return pairsA + pairsB + zUsed;
    }
};
