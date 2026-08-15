// Link: https://leetcode.com/problems/powerful-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        for (long long i = 1; i < bound; i *= x) {
            for (long long j = 1; i + j <= bound; j *= y) {
                res.insert((int)(i + j));
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(res.begin(), res.end());
    }
};
