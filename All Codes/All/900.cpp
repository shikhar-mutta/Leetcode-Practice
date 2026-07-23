// Link: https://leetcode.com/problems/rle-iterator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for each call to next(), where n is the number of calls to next().
// SC: O(1), since we only use a fixed amount of extra space for the idx variable and the encoding vector, regardless of the number of calls to next().
// Approach:
//     1. We maintain an index idx to keep track of the current position in the encoding vector. The encoding vector contains pairs of values, where the first value represents the count of occurrences of a number, and the second value represents the number itself.
//     2. In the next(int n) function, we iterate through the encoding vector starting from the current index idx. For each pair of values, we check if the count (enc[idx]) is greater than or equal to n. If it is, we subtract n from the count and return the corresponding number (enc[idx + 1]).
//     3. If the count is less than n, we subtract the count from n and move to the next pair of values in the encoding vector by incrementing idx by 2. We repeat this process until we either find a count that is greater than or equal to n or reach the end of the encoding vector. If we reach the end without finding a suitable count, we return -1 to indicate that there are no more elements to return.
//     4. The overall time complexity for each call to next() is O(1) because we only process a fixed number of elements in the encoding vector, and the space complexity is also O(1) since we only use a constant amount of extra space for the idx variable and the encoding vector.
class RLEIterator
{
    vector<int> enc;
    int idx = 0;

public:
    RLEIterator(vector<int> &encoding) : enc(encoding) {}

    int next(int n)
    {
        while (idx < (int)enc.size())
        {
            if (enc[idx] >= n)
            {
                enc[idx] -= n;
                return enc[idx + 1];
            }
            n -= enc[idx];
            idx += 2;
        }
        return -1;
    }
};
