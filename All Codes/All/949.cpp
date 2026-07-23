// Link: https://leetcode.com/problems/largest-time-for-given-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), since we are only checking 24 permutations of the digits.
    // SC: O(1), since we are only using a constant amount of extra space
    // Approach:
    // 1. We will sort the array of digits in ascending order.
    // 2. We will generate all the permutations of the digits and check if they form a valid time.
    // 3. We will keep track of the best valid time found so far and return it in the end.
    // 4. If no valid time is found, we will return an empty string.
    // 5. Finally, we will format the best time found in "HH:MM" format and return it as a string.
    string largestTimeFromDigits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int best = -1;
        do
        {
            int h = arr[0] * 10 + arr[1];
            int m = arr[2] * 10 + arr[3];
            if (h < 24 && m < 60)
                best = max(best, h * 60 + m);
        } while (next_permutation(arr.begin(), arr.end()));

        if (best == -1)
            return "";
        char buf[16];
        snprintf(buf, sizeof(buf), "%02d:%02d", best / 60, best % 60);
        return string(buf);
    }
};
