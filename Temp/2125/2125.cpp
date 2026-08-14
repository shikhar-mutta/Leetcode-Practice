// Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        long long total = 0;
        for (auto& row : bank) {
            int cnt = count(row.begin(), row.end(), '1');
            if (cnt > 0) {
                total += (long long)prev * cnt;
                prev = cnt;
            }
        }
        return (int)total;
    }
};
