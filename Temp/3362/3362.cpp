// Link: https://leetcode.com/problems/zero-array-transformation-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> order(q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][0] < queries[b][0];
        });

        priority_queue<int> pq; // max-heap of r values (available, l<=i)
        vector<int> diff(n + 1, 0);
        int cur = 0;
        int qi = 0;
        int kept = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            while (qi < q && queries[order[qi]][0] <= i) {
                pq.push(queries[order[qi]][1]);
                qi++;
            }
            while (cur < nums[i]) {
                if (pq.empty() || pq.top() < i) return -1;
                int r = pq.top(); pq.pop();
                cur++;
                diff[r + 1]--;
                kept++;
            }
        }

        return q - kept;
    }
};
