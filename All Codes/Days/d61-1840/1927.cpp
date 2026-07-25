// Link: https://leetcode.com/problems/sum-game/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n), SC: O(1)
//Approach:
//  1. We can iterate through the string and for each character, we can check if it is a digit or a question mark. If it is a digit, we can add it to the sum of the first half or the second half depending on its position. If it is a question mark, we can increment the count of question marks in the first half or the second half depending on its position. Finally, we can check if the total count of question marks is odd or if the difference between the sums of the first half and the second half is not equal to 9 times the difference between the counts of question marks in the first half and the second half divided by 2. If either of these conditions is true, Alice wins; otherwise, Bob wins.
class Solution
{
public:
    bool sumGame(string num)
    {
        int n = num.size(), half = n / 2;
        int s1 = 0, s2 = 0, q1 = 0, q2 = 0;
        for (int i = 0; i < half; ++i)
        {
            if (num[i] == '?')
                ++q1;
            else
                s1 += num[i] - '0';
        }
        for (int i = half; i < n; ++i)
        {
            if (num[i] == '?')
                ++q2;
            else
                s2 += num[i] - '0';
        }
        int totalQ = q1 + q2;
        if (totalQ % 2)
            return true; // odd count: Alice always wins
        return s1 - s2 != 9 * (q2 - q1) / 2;
    }
};
