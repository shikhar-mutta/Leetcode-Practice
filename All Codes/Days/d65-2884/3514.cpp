// Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXV = 2048;
        vector<int> distinctVals(nums.begin(), nums.end());
        sort(distinctVals.begin(), distinctVals.end());
        distinctVals.erase(unique(distinctVals.begin(), distinctVals.end()), distinctVals.end());

        vector<bool> pairXor(MAXV, false);
        for (int a : distinctVals)
            for (int b : distinctVals)
                pairXor[a ^ b] = true;

        vector<bool> tripleXor(MAXV, false);
        for (int p = 0; p < MAXV; p++) {
            if (!pairXor[p]) continue;
            for (int c : distinctVals) tripleXor[p ^ c] = true;
        }

        int count = 0;
        for (int v = 0; v < MAXV; v++) if (tripleXor[v]) count++;
        return count;
    }
};
