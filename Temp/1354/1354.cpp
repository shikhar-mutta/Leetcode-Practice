// Link: https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;

        priority_queue<long long> pq(target.begin(), target.end());
        long long sum = 0;
        for (int x : target) sum += x;

        while (pq.top() > 1) {
            long long mx = pq.top(); pq.pop();
            long long rest = sum - mx;
            if (rest == 1) return true;

            long long newVal = mx % rest;
            if (newVal == 0) newVal = rest;
            if (newVal >= mx) return false;

            sum = rest + newVal;
            pq.push(newVal);
        }
        return true;
    }
};
