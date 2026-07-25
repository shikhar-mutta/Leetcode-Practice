// Link: https://leetcode.com/problems/distribute-candies-among-children-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(limit^2) (n, limit are small per constraints)
// SC: O(1)
// Approach: brute force over the first two children's candy counts a, b
// (each capped at min(n, limit)); the third child's count c is forced to
// n-a-b, and the triple is valid iff c is in [0, limit].
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for (int a = 0; a <= min(n, limit); ++a) {
            for (int b = 0; b <= min(n - a, limit); ++b) {
                int c = n - a - b;
                if (c >= 0 && c <= limit)
                    ++count;
            }
        }
        return count;
    }
};
