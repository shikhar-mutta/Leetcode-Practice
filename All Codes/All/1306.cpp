// Link: https://leetcode.com/problems/jump-game-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n) where n is the size of the array
    // Approach:
    //   1. We can use a breadth-first search (BFS) approach to solve this problem. We can use a queue to keep track of the indices that we can reach from the starting index. We can also use a boolean array to keep track of the indices that we have already visited to avoid cycles.
    //   2. We can start by adding the starting index to the queue and marking it as visited. We can then repeatedly dequeue an index from the queue and check if the value at that index is 0. If it is, we can return true. Otherwise, we can add the indices that we can reach from the current index (i.e., i + arr[i] and i - arr[i]) to the queue if they are within bounds and have not been visited yet. We can continue this process until the queue is empty.
    //   3. If we have exhausted all possible indices and have not found a 0, we can return false.
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<bool> seen(n, false);
        queue<int> q;
        q.push(start);
        seen[start] = true;
        while (!q.empty())
        {
            int i = q.front();
            q.pop();
            if (arr[i] == 0)
                return true;
            for (int nxt : {i + arr[i], i - arr[i]})
            {
                if (nxt >= 0 && nxt < n && !seen[nxt])
                {
                    seen[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        return false;
    }
};