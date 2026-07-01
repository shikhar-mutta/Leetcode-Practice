// Link: https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;

        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        int level = 1;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return level;

                for (int i = 0; i < (int)word.size(); i++)
                {
                    char orig = word[i];
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == orig)
                            continue;
                        word[i] = c;
                        if (dict.count(word))
                        {
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            level++;
        }
        return 0;
    }
};
