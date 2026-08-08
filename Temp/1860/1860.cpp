// Link: https://leetcode.com/problems/incremental-memory-leak/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        long long m1 = memory1, m2 = memory2;
        int t = 1;
        while (true) {
            if (m1 >= m2) {
                if (m1 < t) break;
                m1 -= t;
            } else {
                if (m2 < t) break;
                m2 -= t;
            }
            t++;
        }
        return {t, (int)m1, (int)m2};
    }
};
