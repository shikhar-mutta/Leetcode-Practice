// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach:
    //  1. Create a normalized array of size 2001 to count the frequency of each number in the input array.
    //  2. Create a vector n_creation of size 4 to keep track of the number of subsequences that can be created with lengths 1, 2, and 3.
    //  3. Iterate through the normalized array and update the n_creation vector based on the frequency of each number.
    //  4. If at any point the frequency of a number becomes negative, return false.
    //  5. Finally, check if there are any subsequences of length 1 or 2 left in the n_creation vector. If there are, return false; otherwise, return true.
    bool isPossible(vector<int> &nums)
    {
        vector<int> normalized = vector<int>(2000 + 1, 0);

        for (auto &n : nums)
            normalized[n + 1000] += 1;
        vector<int> n_creation = {0, 0, 0, 0};

        for (int i = 0; i < 2000 + 1; i++)
        {
            n_creation[3] = n_creation[3] + n_creation[2];
            normalized[i] = normalized[i] - n_creation[1];
            n_creation[2] = n_creation[1];
            normalized[i] = normalized[i] - n_creation[0];
            n_creation[1] = n_creation[0];
            n_creation[0] = normalized[i] - n_creation[3];
            n_creation[0] = max(n_creation[0], 0);
            n_creation[3] = min(n_creation[3], normalized[i]);

            if (normalized[i] < 0)
                return false;
        }
        return n_creation[0] == 0 && n_creation[1] == 0;
    }
};