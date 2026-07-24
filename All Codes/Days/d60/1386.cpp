// Link: https://leetcode.com/problems/cinema-seat-allocation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TC: O(n), SC: O(1)
    // Approach:
    //  1. We create an unordered_map rowMasks to store the reserved seats for each row as a bitmask. Each bit in the mask represents whether a seat is reserved (1) or not (0).
    //  2. We iterate through the reservedSeats vector and update the rowMasks for each reserved seat by setting the corresponding bit in the mask.
    // 3. We then iterate through the rowMasks to check each row with reservations. For each row, we check if the left block (seats 2-5), right block (seats 6-9), and middle block (seats 4-7) are available for seating. We use bitwise operations to check the availability of these blocks.
    // 4. If both the left and right blocks are available, we can seat 2 groups in that row. If only one of the blocks is available, we can seat 1 group. If neither block is available, we cannot seat any groups in that row.
    // 5. Finally, we calculate the number of rows without any reservations (n - rowMasks.size()) and add 2 groups for each of those rows to the total count of groups. We return the total count of groups that can be seated in the cinema.
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, int> rowMasks;

        // Group reserved seats by row and represent as a bitmask
        for (const auto &seat : reservedSeats)
        {
            int row = seat[0];
            int col = seat[1];
            // Set the bit corresponding to the seat column (1-indexed)
            // We use bits 1-10 to represent seats 1-10
            rowMasks[row] |= (1 << col);
        }

        int maxGroups = 0;

        // Check rows with reservations
        for (const auto &entry : rowMasks)
        {
            int mask = entry.second;
            bool canLeft = !((mask >> 2) & 0b1111);   // Check seats 2,3,4,5
            bool canRight = !((mask >> 6) & 0b1111);  // Check seats 6,7,8,9
            bool canMiddle = !((mask >> 4) & 0b1111); // Check seats 4,5,6,7

            if (canLeft && canRight)
            {
                maxGroups += 2;
            }
            else if (canLeft || canRight || canMiddle)
            {
                maxGroups += 1;
            }
        }

        // Rows without any reservations can accommodate 2 groups each
        // Number of such rows = n - rowMasks.size()
        maxGroups += 2 * (n - rowMasks.size());

        return maxGroups;
    }
};