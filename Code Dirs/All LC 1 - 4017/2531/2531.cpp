// Link: https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (char c : word1) cnt1[c-'a']++;
        for (char c : word2) cnt2[c-'a']++;

        int distinct1 = 0, distinct2 = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] > 0) distinct1++;
            if (cnt2[i] > 0) distinct2++;
        }

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] == 0) continue;
            for (int j = 0; j < 26; j++) {
                if (cnt2[j] == 0) continue;

                int newDistinct1 = distinct1;
                int newDistinct2 = distinct2;
                if (i != j) {
                    if (cnt1[i] == 1) newDistinct1--;
                    if (cnt1[j] == 0) newDistinct1++;
                    if (cnt2[j] == 1) newDistinct2--;
                    if (cnt2[i] == 0) newDistinct2++;
                }

                if (newDistinct1 == newDistinct2) return true;
            }
        }
        return false;
    }
};
