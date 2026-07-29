// Link: https://leetcode.com/problems/count-prime-gap-balanced-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        const int MAXV = 50001;
        vector<bool> isPrime(MAXV, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long long)i * i < MAXV; i++)
            if (isPrime[i])
                for (int j = i * i; j < MAXV; j += i) isPrime[j] = false;

        deque<int> maxDq, minDq;
        vector<int> primePos;
        long long ans = 0;
        int L = 0;

        for (int r = 0; r < n; r++) {
            if (isPrime[nums[r]]) {
                while (!maxDq.empty() && nums[maxDq.back()] <= nums[r]) maxDq.pop_back();
                maxDq.push_back(r);
                while (!minDq.empty() && nums[minDq.back()] >= nums[r]) minDq.pop_back();
                minDq.push_back(r);

                while (!maxDq.empty() && !minDq.empty() &&
                       nums[maxDq.front()] - nums[minDq.front()] > k) {
                    if (maxDq.front() < minDq.front()) {
                        L = maxDq.front() + 1;
                        maxDq.pop_front();
                    } else {
                        L = minDq.front() + 1;
                        minDq.pop_front();
                    }
                    while (!maxDq.empty() && maxDq.front() < L) maxDq.pop_front();
                    while (!minDq.empty() && minDq.front() < L) minDq.pop_front();
                }

                primePos.push_back(r);
            }

            int m = primePos.size();
            if (m >= 2) {
                int secondLast = primePos[m-2];
                if (secondLast >= L) ans += (secondLast - L + 1);
            }
        }

        return (int)ans;
    }
};
