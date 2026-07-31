// Link: https://leetcode.com/problems/maximum-strong-pair-xor-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums))), SC: O(n * log(max(nums)))
//  Approach: We can use a binary trie to find the maximum strong pair XOR. We can iterate through the nums array and for each number, we can insert it into the trie and then query the trie to find the maximum XOR with the current number. We can also maintain a left pointer to ensure that we only consider numbers that are less than or equal to twice the current number. We can return the maximum XOR found during the iteration.
class Solution
{
public:
    static const int BITS = 20;
    struct Node
    {
        int child[2] = {-1, -1};
        int count = 0;
    };
    vector<Node> trie;

    void insert(int x, int delta)
    {
        int cur = 0;
        for (int b = BITS; b >= 0; b--)
        {
            int bit = (x >> b) & 1;
            if (trie[cur].child[bit] == -1)
            {
                trie[cur].child[bit] = trie.size();
                trie.push_back(Node());
            }
            cur = trie[cur].child[bit];
            trie[cur].count += delta;
        }
    }
    int query(int x)
    {
        int cur = 0, res = 0;
        for (int b = BITS; b >= 0; b--)
        {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (trie[cur].child[want] != -1 &&
                trie[trie[cur].child[want]].count > 0)
            {
                res |= (1 << b);
                cur = trie[cur].child[want];
            }
            else
            {
                cur = trie[cur].child[bit];
            }
        }
        return res;
    }

    int maximumStrongPairXor(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        trie.assign(1, Node());
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            insert(nums[right], 1);
            while (nums[right] > 2 * nums[left])
            {
                insert(nums[left], -1);
                left++;
            }
            ans = max(ans, query(nums[right]));
        }
        return ans;
    }
};
