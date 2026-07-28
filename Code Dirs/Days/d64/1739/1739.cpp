// Link: https://leetcode.com/problems/building-boxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        long long H = 0, total = 0;
        while (total + (H+1)*(H+2)/2 <= n) {
            H++;
            total += H*(H+1)/2;
        }
        long long ground = H*(H+1)/2;
        long long remaining = n - total;
        long long y = 0;
        while (y*(y+1)/2 < remaining) y++;
        ground += y;
        return (int)ground;
    }
};
