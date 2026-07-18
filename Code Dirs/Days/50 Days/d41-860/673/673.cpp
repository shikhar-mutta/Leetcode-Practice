// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn). SC: O(n)
// Approach: Fenwick Tree (Binary Indexed Tree)
class Solution
{
public:
    struct Node
    {
        int len = 0, cnt = 0;
    };
    class Bit
    {
    public:
        int n;
        vector<Node> bit;
        Bit(int sizeOfBit)
        {
            n = sizeOfBit;
            bit.resize(n + 1);
            for (int i = 0; i <= n; ++i)
            {
                Node node;
                bit[i] = node;
            }
        }

        Node Merge(Node a, Node b)
        {
            if (a.len == 0 || a.len < b.len)
                return b;
            if (b.len == 0 || b.len < a.len)
                return a;
            Node res;
            res.len = a.len;
            res.cnt = a.cnt + b.cnt;
            return res;
        }

        void Update(int idx, Node node)
        {
            while (idx <= n)
            {
                bit[idx] = Merge(bit[idx], node);
                idx += (idx & (-idx));
            }
        }

        Node Query(int idx)
        {
            Node node;
            while (idx > 0)
            {
                node = Merge(node, bit[idx]);
                idx -= (idx & (-idx));
            }
            return node;
        }
    };
    int findNumberOfLIS(vector<int> &nums)
    {
        // sorting part
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());

        // index map part
        unordered_map<int, int> mp;
        int j = 1;
        for (auto x : arr)
            mp[x] = j++;

        Bit bit(nums.size());

        Node res;
        for (auto x : nums)
        {
            int idx = mp[x];
            Node cur = bit.Query(idx - 1);
            if (cur.len == 0 && cur.cnt == 0)
                cur.len = cur.cnt = 1;
            else
                cur.len += 1;
            res = bit.Merge(res, cur);
            bit.Update(idx, cur);
        }

        return res.cnt;
    }
};