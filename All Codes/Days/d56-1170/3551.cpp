// Link: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) = O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. Create a vector of pairs to store the digit sum, actual value, and original index of each element in the input array.
    //  2. Sort the vector based on the digit sum, actual value, and original index.
    //  3. Iterate through the sorted vector and count the number of swaps needed to place each element in its correct position.
    //  4. Return the count of swaps as the result.
    int minSwaps(vector<int> &a)
    {
        int n = a.size();

        // v[i] stores: {{digit_sum, actual_value}, original_index}
        vector<pair<pair<int, int>, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            int x = a[i];
            while (x > 0)
            {
                sum += x % 10;
                x /= 10;
            }
            v[i] = {{sum, a[i]}, i};
        }

        // Sorts by digit_sum first, then actual_value, then original_index
        sort(v.begin(), v.end());

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            // If the element at index 'i' does not belong here,
            // swap it directly with the slot of its original index.
            if (v[i].second != i)
            {
                swap(v[i], v[v[i].second]);
                cnt++;
                i--; // Decrement to re-evaluate the new element swapped into index 'i'
            }
        }

        return cnt;
    }
};