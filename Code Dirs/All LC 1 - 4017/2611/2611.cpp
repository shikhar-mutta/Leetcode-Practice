// Link: https://leetcode.com/problems/mice-and-cheese/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int total = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            total += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }
        sort(diff.rbegin(), diff.rend());
        for (int i = 0; i < k; i++) total += diff[i];
        return total;
    }
};
