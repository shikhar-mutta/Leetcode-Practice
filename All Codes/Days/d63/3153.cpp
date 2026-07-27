// Link: https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * digits), SC: O(1)
// Approach: For each digit position, count how many numbers have each digit
// value 0-9; freq[d]*(n-freq[d]) counts ordered (mismatching, differing)
// pairs at that position, summed over all positions gives twice the total
// pairwise digit differences (each unordered pair counted from both sides),
// so divide by 2 at the end.
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {

        int digits = log10(nums[0]) + 1;
        int n = nums.size();

        long long ans = 0;

        int p = 1;

        for(int j = 0; j < digits; j++){

            vector<int> freq(10,0);

            for(int x : nums){
                int digit = (x / p) % 10;
                freq[digit]++;
            }

            for(int d = 0; d < 10; d++){
                ans += 1LL * freq[d] * (n - freq[d]);
            }

            p *= 10;
        }

        return ans / 2;
    }
};
