// Link: https://leetcode.com/problems/string-compression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. Use two pointers, one for reading the characters and another for writing the compressed characters.
    //  2. Count the occurrences of each character and write the character followed by its count (if greater than 1) to the write pointer.
    //  3. Return the length of the compressed string.
    int compress(vector<char> &chars)
    {
        int write = 0, read = 0;
        int n = chars.size();
        while (read < n)
        {
            char c = chars[read];
            int count = 0;
            while (read < n && chars[read] == c)
            {
                read++;
                count++;
            }
            chars[write++] = c;
            if (count > 1)
            {
                string cnt = to_string(count);
                for (char digit : cnt)
                    chars[write++] = digit;
            }
        }
        return write;
    }
};
