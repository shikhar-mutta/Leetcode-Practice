// Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        int k = 1;
        while (k * (k + 1) / 2 < n) k++;
        return k;
    }
};
