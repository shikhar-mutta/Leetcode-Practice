// Link: https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the input string hamsters.
// SC: O(1), as we are using a constant amount of extra space.
//  Approach:
//   1. We will iterate through the input string hamsters and for each index i, we will check if the character at that index is 'H' (hamster).
//  2. If it is, we will check if the previous character is 'B' (bucket). If it is, we will continue to the next index as the hamster is already fed.
//  3. If the previous character is not 'B', we will check if the next character is '.' (empty space). If it is, we will place a bucket at that index and increment the count of buckets.
//  4. If the next character is not '.', we will check if the previous character is '.' (empty space). If it is, we will place a bucket at that index and increment the count of buckets.
//  5. If neither the previous nor the next character is '.', we will return -1 as it is not possible to feed the hamster.
//  6. Finally, we will return the count of buckets needed to feed all the hamsters.
class Solution
{
public:
    int minimumBuckets(string hamsters)
    {
        int n = hamsters.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (hamsters[i] == 'H')
            {
                if (i > 0 && hamsters[i - 1] == 'B')
                {
                    continue;
                }
                else if (i + 1 < n && hamsters[i + 1] == '.')
                {
                    hamsters[i + 1] = 'B';
                    count++;
                }
                else if (i > 0 && hamsters[i - 1] == '.')
                {
                    hamsters[i - 1] = 'B';
                    count++;
                }
                else
                {
                    return -1;
                }
            }
        }
        return count;
    }
};
