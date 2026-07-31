// Link: https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the size of the input array
// SC: O(n) where n is the size of the input array
// Approach: We can use dynamic programming to solve this problem. We can keep track of the minimum number of trips needed to deliver the boxes. We can use a sliding window approach to keep track of the boxes that can be delivered in one trip. We can also keep track of the number of segments needed to deliver the boxes. We can then update the minimum number of trips needed to deliver the boxes. The final answer will be the minimum number of trips needed to deliver all the boxes.
class Solution
{
public:
    int boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes,
                      int maxWeight)
    {
        int need = 0;
        // we calculate need using number of segments
        // i.e. portA, portA, portA, portB, portB, portB, portC
        // this is need = 3;
        // dp[j] minimum # of trips the ship needs to make to deliver j boxes
        // (0,..., j-1)
        vector<int> dp(boxes.size() + 1, 300000);
        int i = 0;
        int j = 0;
        int lastj = -1;
        dp[0] = 0;
        // [1,2] [3,3] [3,1] [3,1] [2,4]
        // i = 0 greedily fill things in  [3,1] [2,4] lastj = 4, need = 2
        // dp[3] = 3, dp[1] = 2 dp[4] = 4 dp[1] = 1
        // dp[5] = 3 + 3  dp[4] = 3+2
        while (i < boxes.size())
        {
            while (j < boxes.size() && maxBoxes > 0 &&
                   maxWeight >= boxes[j][1])
            {
                maxBoxes--;
                maxWeight = maxWeight - boxes[j][1];
                // let's calculate need and lastj
                if (j == 0 || boxes[j][0] != boxes[j - 1][0])
                {
                    need++;
                    lastj = j;
                }
                j++;
            }
            // [i, j)
            dp[j] = min(dp[j], dp[i] + need + 1);
            dp[lastj] = min(dp[lastj], dp[i] + need);
            // shrink i
            maxBoxes++;
            maxWeight = maxWeight + boxes[i][1];
            if (i == boxes.size() - 1 || boxes[i][0] != boxes[i + 1][0])
            {
                need--;
            }
            i++;
        }
        return dp[boxes.size()];
    }
};
