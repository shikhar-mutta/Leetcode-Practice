// Link: https://leetcode.com/problems/maximize-fixed-points-after-deletions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: We can use a greedy approach to solve this problem. We can iterate through the array and for each element, we can check if it is a fixed point or not. If it is a fixed point, we can add it to the list of fixed points. If it is not a fixed point, we can check if we can delete it or not. If we can delete it, we can add it to the list of deletable elements. After iterating through the array, we can sort the list of deletable elements and then we can iterate through the list of fixed points and for each fixed point, we can check if we can delete any element from the list of deletable elements that is less than the fixed point. If we can delete an element, we can remove it from the list of deletable elements and increase the count of fixed points. Finally, we can return the count of fixed points.
class Solution
{
private:
    void insert(const int num, const int diff, vector<int> &lis)
    {
        int n = lis.size();
        int ind = -1;
        int s = 0, e = n - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (lis[mid] > num)
            {
                ind = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        if (ind == -1 && (n == 0 || lis[n - 1] < num))
        {
            lis.push_back(num);
        }
        else if (ind == 0 || (ind > 0 && lis[ind - 1] < num))
        {
            lis[ind] = num;
        }
    }

public:
    int maxFixedPoints(const vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> diff_num;
        for (int i = 0; i < n; i++)
        {
            if (i - nums[i] >= 0)
                diff_num.emplace_back(i - nums[i], nums[i]);
        }
        sort(diff_num.begin(), diff_num.end());
        vector<int> lis;
        for (int i = 0; i < diff_num.size(); i++)
        {
            auto &[diff, num] = diff_num[i];
            insert(num, diff, lis);
        }
        return lis.size();
    }
};
