// Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq(nums.begin(), nums.end());
        long long score = 0;
        for (int i = 0; i < k; i++) {
            long long top = pq.top(); pq.pop();
            score += top;
            pq.push((top + 2) / 3);
        }
        return score;
    }
};
