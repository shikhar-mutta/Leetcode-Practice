// Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: sliding window over the max element's count. For each right
// end j, shrink from the left while the window from i..j has at least k
// occurrences of the array's max; every left boundary from the current i
// out to 0 keeps that property once satisfied, but instead we count, for
// each valid i (window [i..j] has >=k maxes), all n-j subarrays that start
// at i and end anywhere from j to n-1, then advance i past that element.
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxE = *max_element(nums.begin(), nums.end());
        long long result = 0;
        int countMax = 0;

        while (j < n) {
            if (nums[j] == maxE) {
                countMax++;
            }

            while (countMax >= k) {
                result += n - j;

                if (nums[i] == maxE) {
                    countMax--;
                }
                i++;
            }
            j++;
        }

        return result;
    }
};
