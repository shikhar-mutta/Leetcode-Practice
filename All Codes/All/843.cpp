// Link: https://leetcode.com/problems/guess-the-word/description/

#include <bits/stdc++.h>
using namespace std;

class Master
{
    string secret;
    int guessesUsed = 0;
    int maxGuesses;
    bool solved = false;

public:
    Master(const string &secret, int maxGuesses = 10) : secret(secret), maxGuesses(maxGuesses) {}
    int guess(const string &word)
    {
        guessesUsed++;
        if (guessesUsed > maxGuesses)
            return -1;
        int c = 0;
        for (int i = 0; i < (int)word.size(); i++)
            if (word[i] == secret[i])
                c++;
        if (c == (int)secret.size())
            solved = true;
        return c;
    }
    bool wasSolved() const { return solved; }
};

// TC: O(n^2)  SC: O(n)
// Approach: Randomly guess a word from the list. If it is not the secret word, filter the list to only include words that have the same number of matching characters with the guessed word as returned by the Master.guess() function. Repeat until the secret word is found or the list is empty.
//  The random guessing helps to avoid worst-case scenarios and ensures that we can find the secret word within a reasonable number of guesses.

class Solution
{
public:
    int match(const string &a, const string &b)
    {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
            cnt += (a[i] == b[i]);
        return cnt;
    }

    void findSecretWord(vector<string> &words, Master &master)
    {
        srand(time(nullptr));

        while (!words.empty())
        {
            string g = words[rand() % words.size()];
            int x = master.guess(g);
            if (x == 6)
                return;

            vector<string> nxt;
            for (string &w : words)
                if (match(g, w) == x)
                    nxt.push_back(w);

            words.swap(nxt);
        }
    }
};