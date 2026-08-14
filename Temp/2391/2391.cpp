// Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + travel[i-1];

        int total = 0;
        for (auto &g : garbage) total += g.size();

        for (char type : {'M', 'P', 'G'}) {
            int lastIdx = -1;
            for (int i = 0; i < n; i++)
                if (garbage[i].find(type) != string::npos) lastIdx = i;
            if (lastIdx > 0) total += prefix[lastIdx];
        }
        return total;
    }
};
