// Link: https://leetcode.com/problems/unique-morse-code-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        const string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        // Use an unordered_set to store unique Morse code representations
        unordered_set<string> ans;
        ans.reserve(words.size());
        for (const auto &word : words)
        {
            string code;
            for (char ch : word)
                code += morse[ch - 'a'];
            ans.insert(move(code)); // Move the code string into the set to avoid unnecessary copying
        }
        return ans.size(); // Return the number of unique Morse code representations
    }
};
