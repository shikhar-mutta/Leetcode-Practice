// Link: https://leetcode.com/problems/snakes-and-ladders/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), where n is the size of the board. We may need to visit each square on the board once in the worst case.
    // SC: O(n^2), where n is the size of the board. We use a distance array to keep track of the minimum number of moves to reach each square, which requires O(n^2) space.
    // Approach:
    //    1. We use a breadth-first search (BFS) approach to explore the board. We start from square 1 and explore all possible moves by rolling a die (1 to 6).
    //    2. For each square, we check if there is a snake or ladder that leads to a different square. If so, we move to that square instead of the current square.
    //    3. We keep track of the minimum number of moves to reach each square using a distance array. If we reach the last square, we return the number of moves taken to get there. If we exhaust all possibilities without reaching the last square, we return -1.
    //    4. The getValue function is used to convert a square number to its corresponding row and column on the board, taking into account the zigzag pattern of the board.
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        auto getValue = [&](int square)
        {
            int row = (square - 1) / n;
            int col = (square - 1) % n;
            if (row % 2 == 1)
                col = n - 1 - col;
            row = n - 1 - row;
            return board[row][col];
        };

        int total = n * n;
        vector<int> dist(total + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == total)
                return dist[cur];
            for (int next = cur + 1; next <= min(cur + 6, total); next++)
            {
                int dest = getValue(next);
                if (dest == -1)
                    dest = next;
                if (dist[dest] == -1)
                {
                    dist[dest] = dist[cur] + 1;
                    q.push(dest);
                }
            }
        }
        return -1;
    }
};
