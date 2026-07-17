// Link: https://leetcode.com/problems/count-almost-equal-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * d) where d is the number of digits in the numbers
    // SC: O(1)
    //  Approach:
    //  1. Iterate through all pairs of numbers in the array.
    //  2. For each pair, check if they are almost equal by comparing their digits
    //  3. If they are almost equal, increment the count of pairs.
    //  4. Return the count of pairs.
    int countPairs(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int x = max(nums[i], nums[j]);
                int y = min(nums[i], nums[j]);
                // cout << x << " " << y <<endl;
                int mismatch = -1;
                int tobe = -1;
                int count = 0;
                bool flag = true;
                while (y != 0)
                {
                    int d1 = x % 10;
                    int d2 = y % 10;
                    if (d1 != d2)
                    {
                        count++;
                        if (count > 2)
                        {
                            flag = false;
                            break;
                        }
                        if (mismatch == -1)
                        {
                            mismatch = d1;
                            tobe = d2;
                        }
                        else
                        {
                            if (d1 != tobe || d2 != mismatch)
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                    x /= 10;
                    y /= 10;
                }
                if (flag == false)
                    continue;
                if (x == 0 && count != 1)
                {
                    ans++;
                }
                else if (mismatch == -1 || mismatch != 0)
                    continue;
                else if (mismatch == 0)
                {
                    while (x != 0 && x % 10 == 0)
                    {
                        x /= 10;
                    }
                    if (x == tobe)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};