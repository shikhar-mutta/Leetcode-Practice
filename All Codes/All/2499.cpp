// Link: https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
//  Approach: We can use a frequency array to count the occurrences of each number in nums1 and nums2. We can also keep track of the total cost and the maximum frequency of any number. If the maximum frequency is less than or equal to half of the total count, we can return the total cost. Otherwise, we need to find the minimum cost to make the arrays unequal by changing some elements in nums1 or nums2. We can iterate through the arrays and check if we can change an element to a different number that is not equal to the maximum frequency number. If we can change an element, we add the index to the total cost and decrement the required count. If we cannot find enough elements to change, we return -1.
class Solution
{
public:
    long long minimumTotalCost(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> freq(nums1.size() + 1, 0);
        long long totalCost = 0;
        int count = 0, maxFreq = 0, value;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[i])
            {
                totalCost += i;
                freq[nums1[i]]++;
                count++;
                if (maxFreq < freq[nums1[i]])
                {
                    maxFreq = freq[nums1[i]];
                    value = nums1[i];
                }
            }
        }

        if (count == 0 || 2 * maxFreq <= count)
        {
            return totalCost;
        }

        int req = 2 * maxFreq - count;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] == nums2[i])
                continue;
            if (nums1[i] == value || nums2[i] == value)
                continue;
            totalCost += i;
            req--;
            if (req == 0)
            {
                return totalCost;
            }
        }

        return -1;
    }
};