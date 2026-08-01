// Link: https://leetcode.com/problems/minimum-operations-to-achieve-at-least-k-peaks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))  SC: O(n)
//  Approach: We can use a greedy approach to solve this problem. We can use a priority queue to keep track of the minimum cost to make a peak at each index. We can iterate through the array and for each index, we can calculate the cost to make a peak at that index.
class Node
{
public:
    int cost;
    int L;
    int R;
    bool dead;
};

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k > n / 2)
            return -1;
        if (k == 0)
            return 0;
        vector<pair<int, int>> initial_heap;
        vector<Node> nodes(n);
        for (int i = 0; i < n; i++)
        {
            int left_ind = (i == 0) ? n - 1 : i - 1;
            int right_ind = (i == n - 1) ? 0 : i + 1;
            nodes[i].cost =
                max(0, max(nums[left_ind], nums[right_ind]) + 1 - nums[i]);
            nodes[i].L = left_ind;
            nodes[i].R = right_ind;
            nodes[i].dead = false;
            initial_heap.push_back({nodes[i].cost, i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq(
            initial_heap.begin(), initial_heap.end());

        int ans = 0;
        while (k > 0 && !pq.empty())
        {
            auto [cost, u] = pq.top();
            pq.pop();
            if (nodes[u].dead)
                continue;
            ans += cost;
            k--;
            int l = nodes[u].L;
            int r = nodes[u].R;
            nodes[l].dead = true;
            nodes[r].dead = true;
            nodes[u].cost = nodes[l].cost + nodes[r].cost - nodes[u].cost;
            pq.push({nodes[u].cost, u});
            nodes[u].L = nodes[l].L;
            nodes[u].R = nodes[r].R;
            nodes[nodes[l].L].R = u;
            nodes[nodes[r].R].L = u;
        }

        return ans;
    }
};
