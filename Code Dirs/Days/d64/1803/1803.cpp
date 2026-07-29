// Link: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(maxNum))  SC: O(n * log(maxNum))
// Approach: Use a trie to store the binary representation of the numbers. For each number, we can find how many numbers in the trie have an XOR with it that is less than or equal to a given limit. We can do this by traversing the trie and counting the valid paths based on the bits of the number and the limit.
// The final answer will be the sum of these counts for all numbers in the input array.
struct trie
{
    int node[2];
    int cnt;
};

trie nodepool[300005];
int nodecount;

inline int createnode()
{
    nodepool[nodecount].node[0] = nodepool[nodecount].node[1] = -1;
    nodepool[nodecount].cnt = 0;

    return nodecount++;
}

void add(const int &n)
{
    int t = 0;
    for (int i = 16; i >= 0; i--)
    {
        if (nodepool[t].node[(n >> i) & 1] == -1)
            nodepool[t].node[(n >> i) & 1] = createnode();

        t = nodepool[t].node[(n >> i) & 1];
        nodepool[t].cnt++;
    }
}

int find(const int &n, const int &lim)
{
    int t = 0;
    int sol = 0;
    for (int i = 16; i >= 0; i--)
    {
        if (t == -1)
            break;
        // if limit is one
        int limbit = (lim >> i) & 1;
        int numbit = (n >> i) & 1;

        if (limbit)
        {
            if (nodepool[t].node[numbit] != -1)
                sol += nodepool[nodepool[t].node[numbit]].cnt;

            t = nodepool[t].node[numbit ^ 1];
        }
        else
            t = nodepool[t].node[numbit];
    }

    if (t != -1)
        sol += nodepool[t].cnt;
    return sol;
}

class Solution
{
public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        nodecount = 0;
        createnode();
        int sol = 0;
        for (const auto &it : nums)
        {
            sol += find(it, high) - find(it, low - 1);
            add(it);
        }

        return sol;
    }
};
