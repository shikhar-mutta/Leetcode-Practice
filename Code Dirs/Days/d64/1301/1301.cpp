// Link: https://leetcode.com/problems/number-of-paths-with-max-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
//  Approach: DP from bottom-right to top-left, tracking (bestScore,
//  waysToAchieveIt) per cell. A cell's best comes from the best of its
//  three reachable neighbors (down, right, diag); if multiple neighbors
//  tie for best, sum their way-counts. 'S' and 'E' contribute 0 to the
//  sum; 'X' cells are unreachable.
class Solution
{
public:
    const int M = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int n = board.size();

        // Use -1 to denote unreachable cells
        vector<vector<int>> score(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        // Base case: Start at bottom-right
        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        // Iterate bottom-up, right-to-left
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                // Skip obstacles and the starting square
                if (board[i][j] == 'X')
                    continue;
                if (i == n - 1 && j == n - 1)
                    continue;

                int max_score = -1;
                int total_ways = 0;

                // The 3 directions we can come FROM (Right, Down, Diagonal)
                // Since we are building bottom-up, we look at i+1 and j+1
                int dx[] = {0, 1, 1};
                int dy[] = {1, 0, 1};

                for (int k = 0; k < 3; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (score[nx][ny] != -1)
                    {
                        if (score[nx][ny] > max_score)
                        {
                            max_score = score[nx][ny];
                            total_ways = ways[nx][ny];
                        }
                        else if (score[nx][ny] == max_score)
                        {
                            total_ways = (total_ways + ways[nx][ny]) % M;
                        }
                    }
                }

                // If we found a valid path from the bottom-right to this cell
                if (max_score != -1)
                {
                    int val = (i == 0 && j == 0) ? 0 : (board[i][j] - '0');
                    score[i][j] = max_score + val;
                    ways[i][j] = total_ways;
                }
            }
        }

        // If top-left is unreachable, score[0][0] will remain -1
        if (score[0][0] == -1)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};