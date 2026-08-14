// Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canPartition(string &s, int pos, int target) {
        if (pos == (int)s.size()) return target == 0;
        int sum = 0;
        for (int i = pos; i < (int)s.size(); i++) {
            sum = sum * 10 + (s[i] - '0');
            if (sum > target) break;
            if (canPartition(s, i + 1, target - sum)) return true;
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            string s = to_string(sq);
            if (canPartition(s, 0, i)) total += sq;
        }
        return total;
    }
};
