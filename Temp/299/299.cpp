// Link: https://leetcode.com/problems/bulls-and-cows/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: count exact position matches (bulls), then count remaining
// digit-frequency overlap for cows via two count arrays
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int secCount[10] = {0}, guessCount[10] = {0};
        for (int i = 0; i < (int)secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else {
                secCount[secret[i] - '0']++;
                guessCount[guess[i] - '0']++;
            }
        }
        for (int d = 0; d < 10; d++) cows += min(secCount[d], guessCount[d]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
