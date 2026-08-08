// Link: https://leetcode.com/problems/reducing-dishes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int total = 0, sum = 0;
        for (int x : satisfaction) {
            sum += x;
            if (sum <= 0) break;
            total += sum;
        }
        return total;
    }
};
