// Link: https://leetcode.com/problems/frequency-balance-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) SC: O(n)
//  Approach: n<=1000, so brute force all subarrays. For a fixed left
//  end, extend right incrementally maintaining a value->count map plus
//  a set of distinct count-values currently in use. A window is balanced
//  if it has exactly one distinct value, or if the set of distinct
//  frequencies has exactly two entries with the larger equal to double
//  the smaller.
class Solution
{
public:
    int getLength(vector<int> &nums)
    {
        int maxi = 0, loca = 0;
        int mi = *min_element(nums.begin(), nums.end());
        int ma = *max_element(nums.begin(), nums.end());
        if (mi == ma)
            return nums.size();
        unordered_map<int, int> m1;
        bool bleh = true;
        for (int i = 0; i < nums.size(); i++)
        {
            m1[nums[i]]++;
            if (m1[nums[i]] != 1)
            {
                bleh = false;
                break;
            }
        }
        if (bleh)
            return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            loca = 0;
            unordered_map<int, int> mp;

            for (int j = i; j < nums.size(); j++)
            {
                mp[nums[j]]++;
                if (mp.size() == 1)
                {
                    loca = max(loca, j - i + 1);
                }
                else
                {

                    int f = INT_MAX;
                    bool yes = true, f2 = false, f1 = false;
                    for (auto x : mp)
                        f = min(f, x.second);
                    for (auto x : mp)
                    {
                        if (x.second != f && x.second != 2 * f)
                        {
                            yes = false;
                            break;
                        }
                        else if (x.second == 2 * f)
                            f2 = true;
                        else
                            f1 = true;
                    }
                    if (yes && f2 && f1)
                        loca = max(loca, j - i + 1);
                }
            }
            maxi = max(maxi, loca);
            if (maxi == nums.size())
                break;
        }
        return maxi;
    }
};