// Link: https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26^2)
// SC: O(1)
// Approach: brute force every candidate single-character swap (one
// letter i present in word1, one letter j present in word2). Simulate
// the effect on each word's distinct-letter count without mutating the
// strings: swapping identical letters (i == j) never changes either
// count, so it's only valid if the counts already match; otherwise
// removing letter i from word1 drops its distinct count only if it was
// the last occurrence, and gaining letter j raises it only if word1 had
// none before (symmetrically for word2). If any candidate swap makes
// the two resulting distinct counts equal, it's possible.
class Solution {
public:
    bool isItPossible(string word1, string word2) {

        vector<int> cnt1(26, 0), cnt2(26, 0);

        for (char c : word1)
            cnt1[c - 'a']++;

        for (char c : word2)
            cnt2[c - 'a']++;

        int distinct1 = 0, distinct2 = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt1[i])
                distinct1++;
            if (cnt2[i])
                distinct2++;
        }

        for (int i = 0; i < 26; i++) {

            if (cnt1[i] == 0)
                continue;

            for (int j = 0; j < 26; j++) {

                if (cnt2[j] == 0)
                    continue;

                if (i == j) {
                    if (distinct1 == distinct2)
                        return true;
                    continue;
                }

                int d1 = distinct1;
                int d2 = distinct2;

                if (cnt1[i] == 1)
                    d1--;
                if (cnt1[j] == 0)
                    d1++;

                if (cnt2[j] == 1)
                    d2--;
                if (cnt2[i] == 0)
                    d2++;

                if (d1 == d2)
                    return true;
            }
        }

        return false;
    }
};
