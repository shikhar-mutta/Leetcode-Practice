// Link: https://leetcode.com/problems/perform-string-shifts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size();
        long long net = 0;
        for (auto& sh : shift) {
            if (sh[0] == 0) net += sh[1];
            else net -= sh[1];
        }
        net = ((net % n) + n) % n;
        return s.substr(net) + s.substr(0, net);
    }
};
