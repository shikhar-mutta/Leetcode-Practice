// Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array.
    // SC: O(1) as we are using constant space.
    //  Approach:
    //   1. We will create a count array of size 60 to store the count of remainders when the song durations are divided by 60.
    //   2. We will iterate through the input array and for each song duration, we will calculate its remainder when divided by 60.
    //   3. We will calculate the complement of the remainder, which is (60 - remainder) % 60, and add the count of that complement to the result.
    //   4. We will increment the count of the current remainder in the count array.
    //   5. Finally, we will return the result.
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> count(60, 0);
        int result = 0;
        for (int t : time)
        {
            int r = t % 60;
            int complement = (60 - r) % 60;
            result += count[complement];
            count[r]++;
        }
        return result;
    }
};
