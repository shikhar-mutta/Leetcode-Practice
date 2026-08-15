// Link: https://leetcode.com/problems/rle-iterator/description/

#include <bits/stdc++.h>
using namespace std;

class RLEIterator {
    vector<int> enc;
    int idx = 0;
public:
    RLEIterator(vector<int>& encoding) : enc(encoding) {}

    int next(int n) {
        while (idx < (int)enc.size()) {
            if (n <= enc[idx]) {
                enc[idx] -= n;
                return enc[idx + 1];
            }
            n -= enc[idx];
            idx += 2;
        }
        return -1;
    }
};
