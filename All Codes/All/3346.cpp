// Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + k) where n is the length of the string and k is the maximum element in the array
    // SC: O(n + k) for the hash vectors
    //  Approach:
    //  1. We can use a frequency array to count the frequency of each element in the nums array
    //  2. We can then use a prefix sum array to count the number of elements less than or equal to each element in the nums array
    //  3. We can then iterate through the nums array and for each element, we can calculate the number of elements that can be changed to that element using the prefix sum array and the frequency array
    //  4. We can then return the maximum frequency of any element after performing the operations
    //  5. Finally, we return the maximum frequency of any element after performing the operations
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxEl + k + 1);
        for (auto it : nums)
        {
            freq[it]++;
        }

        for (int i = 1; i < freq.size(); i++)
        {
            freq[i] = freq[i - 1] + freq[i];
        }

        int ans = 0;
        int low = 1;
        for (int i = 0; i <= maxEl; i++)
        {
            int L = max(0, i - k);
            int R = i + k;
            int ER = freq[R] - (L > 0 ? freq[L - 1] : 0);
            int target = freq[i] - (i > 0 ? freq[i - 1] : 0);
            int rem = ER - target;
            int need = min(rem, numOperations) + target;
            ans = max(ans, need);
        }
        return ans;
    }
};