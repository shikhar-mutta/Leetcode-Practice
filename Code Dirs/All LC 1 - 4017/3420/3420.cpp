// Link: https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        vector<int> A = nums;
        reverse(A.begin(), A.end());
        long long K = k;
        long long res = 0;
        deque<int> q;
        for (int j = 0, i = 0; j < (int)A.size(); ++j) {
            while (!q.empty() && A[q.back()] < A[j]) {
                int r = q.back();
                q.pop_back();
                int l = q.empty() ? i - 1 : q.back();
                K -= 1LL * (r - l) * (A[j] - A[r]);
            }
            q.push_back(j);
            while (K < 0) {
                K += A[q.front()] - A[i];
                if (q.front() == i) {
                    q.pop_front();
                }
                ++i;
            }
            res += j - i + 1;
        }
        return res;
    }
};
