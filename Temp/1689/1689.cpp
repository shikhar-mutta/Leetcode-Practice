// Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        char best = '0';
        for (char c : n) best = max(best, c);
        return best - '0';
    }
};
