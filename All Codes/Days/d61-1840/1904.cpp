// Link: https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach:
//   1. Convert the login and logout times to minutes since midnight.
//   2. If the logout time is earlier than the login time, it means the player played across midnight, so we add 24 hours (in minutes) to the logout time.
//  3. Calculate the start and end round indices by dividing the login and logout times by 15 (the duration of a round) and rounding up for the start time and down for the end time.
//  4. The number of full rounds played is the difference between the end and start round indices, ensuring it is not negative.
//  5. Return the number of full rounds played.
class Solution
{
public:
    int numberOfRounds(string loginTime, string logoutTime)
    {
        int in = toMinutes(loginTime), out = toMinutes(logoutTime);
        if (out < in)
            out += 24 * 60;         // crossed midnight
        int start = (in + 14) / 15; // round up to round index
        int end = out / 15;         // round down
        return max(0, end - start) r;
    }

private:
    int toMinutes(const string &t)
    {
        return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
    }
};