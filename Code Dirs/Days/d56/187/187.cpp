// Link: https://leetcode.com/problems/repeated-dna-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N) SC: O(N)
// Approach:
// 1. We can use a sliding window of size 10 to iterate through the string and keep track of the sequences we have seen so far using a hash set.
// 2. For each sequence, we check if it has been seen before. If it has, we add it to the result vector. If it hasn't, we add it to the hash set.
// 3. We can use a bitmask to represent the sequences instead of using a string to save space and time. Each character can be represented by 2 bits, so a sequence of length 10 can be represented by 20 bits. We can use a bitmask of size 20 to represent the sequences and use a hash set to keep track of the sequences we have seen so far.
class Solution
{
private:
    int encode(char c)
    {
        if (c == 'A')
            return 0;
        if (c == 'C')
            return 1;
        if (c == 'G')
            return 2;
        return 3;
    }

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        array<int8_t, (1 << 20) - 1> seen{};
        const int mask = (1 << 20) - 1;
        int window = 0;
        vector<string> result;
        for (int i = 0; i < s.size(); i++)
        {
            window = (window << 2) | (encode(s[i]));
            window = window & mask;
            if (i < 9)
                continue;

            if (seen[window] == 1)
            {
                result.push_back(move(s.substr(i - 9, 10)));
                seen[window] = 2;
            }
            else if (seen[window] == 0)
                seen[window] = 1;
        }
        return result;
    }
};