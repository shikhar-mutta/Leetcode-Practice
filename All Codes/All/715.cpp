// Link: https://leetcode.com/problems/range-module/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(n)
// Approach: Use a map to store the ranges. For addRange, merge overlapping ranges. For queryRange, check if the range is covered by any existing range. For removeRange, split and remove overlapping ranges.
class RangeModule
{
    map<int, int> r; // ranges {left->right}
public:
    RangeModule() {}

    void addRange(int left, int right)
    {
        auto it = r.upper_bound(left);
        if (it != r.begin() && prev(it)->second >= left)
            left = prev(it)->first;
        auto it1 = r.lower_bound(left);
        for (; it1 != r.end() && (it1->first <= right);)
        {
            right = max(right, it1->second);
            r.erase(it1++);
        }
        r.insert({left, right});
    }

    bool queryRange(int left, int right)
    {
        auto it = r.upper_bound(left);
        if (it != r.begin())
        {
            if (prev(it)->second >= right)
                return true;
        }
        return false;
    }

    void removeRange(int left, int right)
    {
        auto it = r.lower_bound(left);
        int right1 = right;
        if (it != r.begin() && prev(it)->second > left)
        {
            right1 = max(right1, prev(it)->second);
            prev(it)->second = left;
        }
        for (; it != r.end() && (it->first <= right1);)
        {
            right1 = max(right1, it->second);
            r.erase(it++);
        }
        if (right1 > right)
            r.insert({right, right1});
    }
};
