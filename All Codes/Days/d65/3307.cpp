// Link: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log k), SC: O(1)
// Approach: each operation doubles the string's length by appending a copy of the current
// string (unchanged for type 0, each char shifted +1 for type 1) — the first half is always
// untouched by that operation. Work backward from position k: find the minimal m with 2^m >= k,
// then repeatedly check whether k falls in the second half of the length-2^i string (i counting
// down from m-1); if so it originated from the mirrored first-half position, accumulating a
// shift for each type-1 operation involved, until reaching the original 'a' at position 0.
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long pos = k - 1;
        int m = 0;
        while ((1LL << m) < k) m++;

        int shift = 0;
        for (int i = m - 1; i >= 0; i--) {
            long long half = 1LL << i;
            if (pos >= half) {
                pos -= half;
                if (operations[i] == 1) shift++;
            }
        }
        return 'a' + (shift % 26);
    }
};
