// Link: https://leetcode.com/problems/find-the-winner-of-an-array-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0], wins = 0;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] > cur) { cur = arr[i]; wins = 1; }
            else wins++;
            if (wins == k) return cur;
        }
        return cur;
    }
};
