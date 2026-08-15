// Link: https://leetcode.com/problems/candy/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: two passes — left-to-right enforce right-neighbor rule, right-to-left enforce left-neighbor rule,
// each child gets max of both passes' requirements
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i-1]) candies[i] = candies[i-1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i+1]) candies[i] = max(candies[i], candies[i+1] + 1);
        int total = 0;
        for (int c : candies) total += c;
        return total;
    }
};
