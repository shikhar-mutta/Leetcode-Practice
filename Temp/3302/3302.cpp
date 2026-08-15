// Link: https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size(), m = word2.size();

        vector<int> matchExact(n1 + 1, 0);
        {
            int j = m;
            matchExact[n1] = m - j;
            for (int i = n1 - 1; i >= 0; i--) {
                if (j > 0 && word1[i] == word2[j-1]) j--;
                matchExact[i] = m - j;
            }
        }

        vector<int> matchOne(n1 + 1, 0);
        {
            int jNo = m, jWith = m;
            matchOne[n1] = m - jWith;
            for (int i = n1 - 1; i >= 0; i--) {
                int newJNo = jNo;
                if (jNo > 0 && word1[i] == word2[jNo-1]) newJNo = jNo - 1;

                int candA = jWith;
                if (jWith > 0 && word1[i] == word2[jWith-1]) candA = jWith - 1;
                int candB = (jNo > 0) ? (jNo - 1) : jWith;
                int newJWith = min(candA, candB);

                jNo = newJNo;
                jWith = newJWith;
                matchOne[i] = m - jWith;
            }
        }

        vector<int> result;
        int wordPtr = 0;
        bool mismatchUsed = false;
        for (int i = 0; i < n1 && wordPtr < m; i++) {
            int needed = m - wordPtr - 1;
            if (word1[i] == word2[wordPtr]) {
                int avail = mismatchUsed ? matchExact[i+1] : matchOne[i+1];
                if (avail >= needed) {
                    result.push_back(i);
                    wordPtr++;
                }
            } else if (!mismatchUsed) {
                int avail = matchExact[i+1];
                if (avail >= needed) {
                    result.push_back(i);
                    wordPtr++;
                    mismatchUsed = true;
                }
            }
        }

        if (wordPtr < m) return {};
        return result;
    }
};
