// Link: https://leetcode.com/problems/apply-operations-to-maximize-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = res * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return res;
    }

    int primeScore(int x) {
        int cnt = 0;
        for (int p = 2; (long long)p * p <= x; p++) {
            if (x % p == 0) {
                cnt++;
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) cnt++;
        return cnt;
    }

    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> score(n);
        for (int i = 0; i < n; i++) score[i] = primeScore(nums[i]);

        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[st.top()] < score[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[st.top()] <= score[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] > nums[b]; });

        long long ans = 1;
        for (int i : idx) {
            long long cnt = (long long)(i - left[i]) * (right[i] - i);
            long long ops = min((long long)k, cnt);
            ans = ans * power(nums[i], ops, MOD) % MOD;
            k -= ops;
            if (k == 0) break;
        }
        return (int)ans;
    }
};
