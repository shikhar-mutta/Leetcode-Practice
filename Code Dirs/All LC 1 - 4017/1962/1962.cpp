// Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int top = pq.top(); pq.pop();
            pq.push(top - top / 2);
        }
        int sum = 0;
        while (!pq.empty()) { sum += pq.top(); pq.pop(); }
        return sum;
    }
};
