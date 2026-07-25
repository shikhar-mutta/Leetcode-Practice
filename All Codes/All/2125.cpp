// Link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), where n is the number of rows and m is the number of columns in the bank.
// SC: O(n), where n is the number of rows in the bank, as we are storing the count of devices in each row in a separate vector.
//  Approach:
//   1. We first count the number of devices in each row and store it in a vector.
//   2. Then we iterate through the vector and for each row with devices, we multiply the number of devices in that row with the number of devices in the previous row with devices
//   3. We keep a running total of the number of beams and return it at the end.
//   4. This works because each device in a row can connect to each device in the previous row with devices, forming a beam.
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {

        vector<int> rowDevices;
        for (auto &s : bank)
        {
            auto count = 0;
            for (auto c : s)
            {
                if (c == '1')
                {
                    ++count;
                }
            }
            rowDevices.push_back(count);
        }

        auto totalDevices = 0;
        auto prev = 0;
        for (auto curr : rowDevices)
        {
            if (curr != 0)
            {
                totalDevices += curr * prev;
                prev = curr;
            }
        }

        return totalDevices;
    }
};
