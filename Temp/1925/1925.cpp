// Link: https://leetcode.com/problems/count-square-sum-triples/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int c2 = a*a + b*b;
                int c = (int)sqrt((double)c2);
                for (int cc = c - 1; cc <= c + 1; cc++) {
                    if (cc >= 1 && cc <= n && cc*cc == c2) count++;
                }
            }
        }
        return count;
    }
};
