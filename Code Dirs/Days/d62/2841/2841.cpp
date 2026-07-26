// Link: https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/

#include <bits/stdc++.h>
using namespace std;

#include <memory_resource>
std::pmr::unsynchronized_pool_resource pool;

// TC: O(n) amortized
// SC: O(k)
// Approach: fixed-size sliding window of length k, tracking element counts in
// a hash map (backed by a pmr pool allocator to cut per-window allocation
// overhead). Whenever the window has at least n distinct values, its current
// sum is a candidate; track the running max. Slide by adding the new element
// and removing the one that falls off the left.
class Solution {
public:
    long long maxSum(vector<int>& v, int n, int k) {
        pmr::unordered_map<int, int> m(&pool);

        int sIdx = 0;
        long long maxSum = 0, currSum = 0;
        for (int i=0; i<v.size(); i++) {
            currSum += (long long)v[i];
            m[v[i]]++;

            if (m.size() >= n)
                maxSum = (maxSum > currSum) ? maxSum : currSum;

            if (i - sIdx + 1 == k) {
                currSum -= (long long)v[sIdx];
                if (m[v[sIdx]] == 1)
                    m.erase(v[sIdx]);
                else
                    m[v[sIdx]]--;
                sIdx++;
            }
        }
        return maxSum;
    }
};
