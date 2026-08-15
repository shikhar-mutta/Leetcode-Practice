// Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isqrt(int x) {
        int r = (int)sqrt((double)x);
        while ((long long)(r+1) * (r+1) <= x) r++;
        while ((long long)r * r > x) r--;
        return r;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++) {
            int top = pq.top(); pq.pop();
            pq.push(isqrt(top));
        }
        long long sum = 0;
        while (!pq.empty()) { sum += pq.top(); pq.pop(); }
        return sum;
    }
};
