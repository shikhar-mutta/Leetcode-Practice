// Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    //  Approach:
    //  1. Create a vector nums of size n+1 to keep track of the banned numbers. Initialize all elements to 0.
    //  2. Iterate through the ban vector and mark the banned numbers in the nums vector by setting the corresponding indices to 1.
    //  3. Initialize two variables: s1 to keep track of the sum of chosen numbers and ans to count the number of chosen numbers.
    //  4. Iterate through the range from 1 to n:
    //     a. If the current number is not banned (nums[i] == 0), check if adding it to the sum s1 would exceed m.
    //     b. If it does not exceed m, increment ans and add the current number to s1.
    //     c. If it exceeds m, break the loop as we cannot choose any more numbers without exceeding m.
    //  5. Return the count of chosen numbers (ans).
    int maxCount(vector<int> &ban, int n, int m)
    {
        int s1 = 0, ans = 0;
        vector<int> nums(n + 1);
        for (int i = 0; i < ban.size(); i++)
        {
            if (ban[i] <= n)
            {
                nums[ban[i]] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (nums[i] == 0)
            {
                if (s1 + i <= m)
                {
                    ans++;
                    s1 += i;
                }
                else
                    break;
            }
        }
        return ans;
    }
};
