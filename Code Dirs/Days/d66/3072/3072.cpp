// Link: https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: Use a Fenwick tree to count the number of elements not greater than the current element in the first array. If the count is greater than 0, add the current element to the first array and update the Fenwick tree. Otherwise, add the current element to the second array.
//  The Fenwick tree is used to keep track of the number of elements in the first array that are not greater than the current element. The first array is always kept sorted, so we can use binary search to find the position of the current element in the sorted array. The second array is also kept sorted, but we don't need to keep track of its elements in the Fenwick tree because we only need to know how many elements are in the first array that are not greater than the current element.
class Fenwick
{
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    void update(int i, int val)
    {
        while (i < tree.size())
        {
            tree[i] += val;
            i += i & -i; // i + lowbit(i)
        }
    }

    int pre(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += tree[i];
            i &= i - 1; // i - lowbit(i);
        }
        return s;
    }
};

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        auto sorted = nums;
        ranges::sort(sorted);
        // make front unique, move duplicated to back, then erase
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        // nums sorted with unique
        int m = sorted.size();

        // init, fenwick to count not greater
        Fenwick tr(m + 1);
        vector<int> a{nums[0]}, b{nums[1]};
        // add into fenwick tree
        tr.update(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1, 1);
        tr.update(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1,
                  -1);
        for (int i = 2; i < nums.size(); i++)
        {
            int k = nums[i];
            int v = ranges::lower_bound(sorted, k) - sorted.begin() + 1;
            int gc = a.size() - b.size() - tr.pre(v);
            if (gc > 0 || gc == 0 && a.size() <= b.size())
            {
                a.push_back(k);
                tr.update(v, 1);
            }
            else
            {
                b.push_back(k);
                tr.update(v, -1);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};
