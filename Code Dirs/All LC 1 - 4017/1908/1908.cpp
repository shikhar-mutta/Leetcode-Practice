// Link: https://leetcode.com/problems/game-of-nim/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int x = 0;
        for (int p : piles) x ^= p;
        return x != 0;
    }
};
