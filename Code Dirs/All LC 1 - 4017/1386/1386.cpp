// Link: https://leetcode.com/problems/cinema-seat-allocation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (auto& r : reservedSeats) {
            int row = r[0], seat = r[1];
            if (seat >= 2 && seat <= 9) {
                rowMask[row] |= (1 << (seat - 2));
            }
        }

        int leftMask = 0b00001111;
        int midMask = 0b00111100;
        int rightMask = 0b11110000;

        int total = (long long)(n - rowMask.size()) * 2;
        for (auto& [row, mask] : rowMask) {
            if ((mask & leftMask) == 0 || (mask & rightMask) == 0) {
                if ((mask & leftMask) == 0 && (mask & rightMask) == 0) total += 2;
                else total += 1;
            } else if ((mask & midMask) == 0) {
                total += 1;
            }
        }
        return total;
    }
};
