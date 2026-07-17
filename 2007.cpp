// Link: https://leetcode.com/problems/find-original-array-from-doubled-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the size of the input array and m is the maximum value in the input array.
    // SC: O(m) where m is the maximum value in the input array.
    // Approach:
    // 1. Count the frequency of each number in the input array using a frequency array.
    // 2. Handle the special case of 0 separately, since 2 * 0 = 0. If the frequency of 0 is odd, return an empty array.
    // 3. Iterate through the frequency array, and for each number, check if its double exists in the frequency array. If it does, add the number to the result array and decrement the frequency of its double. If it doesn't, return an empty array.
    // 4. Return the result array.
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        if (n % 2 != 0)
            return {};

        // Find the maximum value to size our frequency array
        int max_val = 0;
        for (int num : changed)
        {
            max_val = max(max_val, num);
        }

        // Pure array instead of unordered_map (massive speedup)
        vector<int> freq(max_val + 1, 0);
        for (int num : changed)
        {
            freq[num]++;
        }

        // Pre-allocate exact memory needed
        vector<int> ans;
        ans.reserve(n / 2);

        // Handle 0 separately (since 2 * 0 = 0)
        if (freq[0] % 2 != 0)
            return {};
        for (int k = 0; k < freq[0] / 2; ++k)
        {
            ans.push_back(0);
        }

        // Iterate through naturally sorted indices
        for (int i = 1; i <= max_val; ++i)
        {
            if (freq[i] == 0)
                continue;

            // If the double is out of bounds or we don't have enough doubles, it's invalid
            if (2 * i > max_val || freq[2 * i] < freq[i])
                return {};

            // Consume the original and its doubles
            for (int k = 0; k < freq[i]; ++k)
            {
                ans.push_back(i);
            }
            freq[2 * i] -= freq[i];
        }

        return ans;
    }
};