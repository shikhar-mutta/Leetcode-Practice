// Link: https://leetcode.com/problems/minimum-operations-to-convert-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m), SC: O(1)
//   Approach:
//   1. We can use BFS to find the minimum number of operations to convert the start number to the goal number.
//   2. We can use a queue to store the current number and the number of operations taken to reach that number.
//   3. We can use a vector to keep track of the visited numbers to avoid cycles.
//   4. We can perform the three operations (addition, subtraction, and XOR) on the current number and check if the result is equal to the goal number. If it is, we return the number of operations taken to reach that number. If it is not, we add the result to the queue and mark it as visited.
//   5. We repeat this process until we find the goal number or the queue is empty, in which case we return -1.
class Solution
{
public:
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        if (start == goal)
            return 0;

        queue<int> q;
        vector<int> vis(1001, 0);
        q.push(start);
        vis[start] = 1;

        int step = 0;
        while (!q.empty())
        {
            int sz = q.size();
            step++;

            while (sz--)
            {
                int x = q.front();
                q.pop();

                for (int num : nums)
                {
                    int a = x + num;
                    int b = x - num;
                    int c = x ^ num;

                    if (a == goal || b == goal || c == goal)
                        return step;

                    if (0 <= a && a <= 1000 && !vis[a])
                    {
                        vis[a] = 1;
                        q.push(a);
                    }
                    if (0 <= b && b <= 1000 && !vis[b])
                    {
                        vis[b] = 1;
                        q.push(b);
                    }
                    if (0 <= c && c <= 1000 && !vis[c])
                    {
                        vis[c] = 1;
                        q.push(c);
                    }
                }
            }
        }
        return -1;
    }
};
