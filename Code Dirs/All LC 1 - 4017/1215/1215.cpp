// Link: https://leetcode.com/problems/stepping-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        if (low == 0) res.push_back(0);
        queue<long long> q;
        for (int d = 1; d <= 9; d++) q.push(d);
        while (!q.empty()) {
            long long num = q.front(); q.pop();
            if (num > high) continue;
            if (num >= low) res.push_back((int)num);
            int last = num % 10;
            if (last > 0) q.push(num * 10 + (last - 1));
            if (last < 9) q.push(num * 10 + (last + 1));
        }
        sort(res.begin(), res.end());
        return res;
    }
};
