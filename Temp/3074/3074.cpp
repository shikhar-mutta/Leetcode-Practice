// Link: https://leetcode.com/problems/apple-redistribution-into-boxes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for (int x : apple) total += x;
        sort(capacity.rbegin(), capacity.rend());
        int cnt = 0;
        for (int c : capacity) {
            if (total <= 0) break;
            total -= c;
            cnt++;
        }
        return cnt;
    }
};
