// Link: https://leetcode.com/problems/largest-number-after-mutating-substring/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n), SC: O(1)
//Approach:
//  1. We can iterate through the string and for each character, we can check if the mutated digit is greater than the current digit. If it is, we can mutate the digit and set a flag to indicate that we have started mutating. If the mutated digit is less than the current digit and we have already started mutating, we can break the loop. If the mutated digit is equal to the current digit, we can continue to the next character. Finally, we can return the mutated string.    
class Solution
{
public:
    std::string maximumNumber(std::string num, std::vector<int> &change)
    {
        bool started_mutating = false;

        for (int i = 0; i < num.length(); ++i)
        {
            int current_digit = num[i] - '0';
            int mutated_digit = change[current_digit];
            if (mutated_digit > current_digit)
            {
                num[i] = mutated_digit + '0';
                started_mutating = true;
            }
            else if (mutated_digit < current_digit)
            {
                if (started_mutating)
                {
                    break;
                }
            }
            else
            {
                continue;
            }
        }

        return num;
    }
};