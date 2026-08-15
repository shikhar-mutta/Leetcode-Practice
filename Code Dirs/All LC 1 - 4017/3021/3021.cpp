// Link: https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long xOdd = (n + 1) / 2, xEven = n / 2;
        long long yOdd = (m + 1) / 2, yEven = m / 2;
        return xOdd * yEven + xEven * yOdd;
    }
};
