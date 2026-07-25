// Link: https://leetcode.com/problems/optimal-partition-of-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the input string s, as we iterate through each character of the string once.
// SC: O(1), as we are using a constant amount of extra space for variables
//  Approach:
//    1. We initialize a variable mask to 0, which will be used to keep track of the characters we have seen in the current partition using bit manipulation.
//    2. We initialize a variable count to 1, which will be used to count the number of partitions we have made.
//    3. We iterate through each character c in the input string s using a for loop. For each character, we calculate its corresponding bit position using the expression (c - 'a') and create a bitmask for that character using the expression (1 << (c - 'a')).
//    4. We check if the character has already been seen in the current partition by performing a bitwise AND operation between the mask and the bitmask for the character. If the result is non-zero, it means the character has already been seen, and we need to start a new partition. In this case, we increment the count variable and reset the mask to 0.
//    5. We update the mask by performing a bitwise OR operation between the current mask and the bitmask for the character, effectively marking the character as seen in the current partition.
//    6. After iterating through all characters in the string, we return the value of count, which represents the minimum number of partitions needed such that each letter appears in at most one part.
class Solution
{
public:
    int partitionString(string s)
    {
        int mask = 0, count = 1;
        for (char c : s)
        {
            int bit = 1 << (c - 'a');
            if (mask & bit)
            { // repeat: start a new partition
                count++;
                mask = 0;
            }
            mask |= bit;
        }
        return count;
    }
};
