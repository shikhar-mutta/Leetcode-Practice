// Link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int sum = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            right--;
            sum += piles[right];
            right--;
            left++;
        }
        return sum;
    }
};
