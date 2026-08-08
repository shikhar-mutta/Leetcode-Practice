// Link: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int diff = tomatoSlices - 2 * cheeseSlices;
        if (diff % 2 != 0) return {};
        int j = diff / 2;
        int s = cheeseSlices - j;
        if (j < 0 || s < 0) return {};
        return {j, s};
    }
};
