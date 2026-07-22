// Link: https://leetcode.com/problems/bulls-and-cows/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input strings secret and guess. We iterate through both strings once to count bulls and cows.
    // SC: O(1) as we use a fixed-size array of size 10 to count the occurrences of digits in secret and guess.
    // Approach:
    //   1. We can iterate through both strings secret and guess simultaneously.
    //   2. For each character, if they are equal, we increment the bulls count.
    //   3. If they are not equal, we increment the count of the corresponding digit in secretCount and guessCount arrays.
    //   4. After iterating through both strings, we can calculate the cows count by taking the minimum of the counts of each digit in secretCount and guessCount arrays.
    //   5. Finally, we return the result in the format "xAyB" where x is the number of bulls and y is the number of cows.
    string getHint(string secret, string guess)
    {
        int bulls = 0, cows = 0;
        int secretCount[10] = {0}, guessCount[10] = {0};
        int n = secret.size();
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                secretCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }
        for (int d = 0; d < 10; d++)
            cows += min(secretCount[d], guessCount[d]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
