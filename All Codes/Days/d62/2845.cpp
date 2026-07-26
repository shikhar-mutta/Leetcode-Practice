// Link: https://leetcode.com/problems/count-of-interesting-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(modulo)
// Approach: let cur = running count (mod modulo) of elements so far with
// nums[i]%modulo==k. A subarray is interesting iff (its count of such
// elements) % modulo == k, i.e. prefixCount[r] - prefixCount[l-1] ≡ k (mod
// modulo), i.e. prefixCount[l-1] ≡ cur - k (mod modulo). freq[] tracks how
// many prior prefixes hit each residue; add freq[(cur-k) mod modulo] for
// each new prefix, then record cur's own residue.
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        int freq[100001] = {};
        long long ans = 0;
        freq[0] = 1;
        int cur = 0;
        for (int i : nums) {
            cur += (i % modulo == k);
            if (cur < k) {
                freq[cur]++;
                continue;
            }
            ans += freq[(cur - k) % modulo];
            freq[cur % modulo]++;
        }
        return ans;
    }
};
