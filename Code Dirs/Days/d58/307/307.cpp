// Link: https://leetcode.com/problems/range-sum-query-mutable/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(logn) for update and sumRange
// SC: O(n)
//  Approach:
// 1. We can use Fenwick Tree to solve this problem.
class NumArray
{
public:
    vector<int> tree;
    vector<int> arr;
    int n;
    void treeadd(int ind, int val)
    {
        while (ind < n + 1)
        {
            tree[ind] += val;
            ind += ind & (-ind);
        }
    }
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        tree.assign(n + 1, 0);
        arr = nums;

        for (int i = 0; i < nums.size(); i++)
        {
            treeadd(i + 1, nums[i]);
        }
    }

    int query(int ind)
    {
        int sum = 0;
        while (ind > 0)
        {
            sum += tree[ind];
            ind -= ind & (-ind);
        }
        return sum;
    }
    void update(int index, int val)
    {
        treeadd(index + 1, val - arr[index]);
        arr[index] = val;
    }

    int sumRange(int left, int right)
    {
        int l = query(left);
        int r = query(right + 1);
        return r - l;
    }
};
