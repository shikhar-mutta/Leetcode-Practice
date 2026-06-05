// Link: https://leetcode.com/problems/number-of-beautiful-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2). SC: O(1).
    int countBeautifulPairs(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                while (nums[i] >= 10)
                    nums[i] /= 10;
                if (__gcd(nums[i], nums[j] % 10) == 1)
                    cnt++;
            }
        return cnt;
    }
};
