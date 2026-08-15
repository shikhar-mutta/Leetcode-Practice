// Link: https://leetcode.com/problems/find-the-k-or-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n * 32) = O(n)
    int findKOr(vector<int> &nums, int k)
    {
        vector<int> prefix(32, 0);
        for (int num : nums) // Find the set bit count for each bit position
            for (int i = 0; i < 32; i++)
            {
                if (num % 2 == 1)
                    prefix[i]++;
                else if (num == 0)
                    break;
                num /= 2;
            }

        int result = 0; // Get result by oring bits which have set bit count >= k
        for (int i = 0; i < 32; i++)
            if (prefix[i] >= k)
                result |= (1 << i);

        return result;
    }
};
