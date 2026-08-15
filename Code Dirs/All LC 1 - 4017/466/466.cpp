// Link: https://leetcode.com/problems/count-the-repetitions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1 * |s1| + |s2|)  SC: O(|s2|)
// Approach: process each copy of s1, tracking the pointer into s2 and how
// many full s2's completed; detect a cycle by (s2 pointer) repeating,
// then fast-forward using the cycle period
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len2 = s2.size();
        vector<int> s2CountAt(len2 + 1, -1);
        vector<int> s2PtrAt(len2 + 1, -1);

        int s2ptr = 0, s2count = 0;
        int s1count = 0;
        vector<long long> s2countAtS1(n1 + 1, 0);

        for (s1count = 1; s1count <= n1; s1count++) {
            for (char c : s1) {
                if (c == s2[s2ptr]) {
                    s2ptr++;
                    if (s2ptr == len2) { s2ptr = 0; s2count++; }
                }
            }
            s2countAtS1[s1count] = s2count;

            if (s2PtrAt[s2ptr] != -1) {
                int prevS1 = s2PtrAt[s2ptr];
                int prevS2Count = s2CountAt[s2ptr];
                int cycleLenS1 = s1count - prevS1;
                int cycleGainS2 = s2count - prevS2Count;

                int remainingS1 = n1 - s1count;
                int cycles = remainingS1 / cycleLenS1;
                long long total = s2count + (long long)cycles * cycleGainS2;
                int rem = remainingS1 % cycleLenS1;
                total += s2countAtS1[prevS1 + rem] - prevS2Count;

                return (int)(total / n2);
            }
            s2PtrAt[s2ptr] = s1count;
            s2CountAt[s2ptr] = s2count;
        }

        return s2count / n2;
    }
};
