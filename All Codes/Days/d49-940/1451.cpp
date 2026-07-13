// Link: https://leetcode.com/problems/rearrange-words-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) for string concatenation.
    // SC: O(n) for storing the words.
    //   Approach:
    //   1. Split the sentence into words.
    //   2. Store the starting index of each word in a map based on their lengths.
    //   3. Iterate through the map and concatenate the words based on their lengths to form the result.
    string arrangeWords(string text)
    {
        unordered_map<int, vector<int>> map;
        string curr = "";
        int maxsiz = 0;
        int siz;
        int index = 0;
        text[0] = tolower(text[0]);
        for (char x : text)
        {
            if (x != ' ')
            {
                string s1(1, x);
                curr += x;
            }
            else
            {
                siz = curr.size();
                maxsiz = maxsiz < siz ? siz : maxsiz;
                map[siz].push_back(index - siz);
                curr = "";
            }
            ++index;
        }

        if (curr != "")
        {
            siz = curr.size();
            maxsiz = maxsiz < siz ? siz : maxsiz;
            map[siz].push_back(index - siz);
        }

        string result = "";
        for (int i = 1; i <= maxsiz; ++i)
        {
            if (map.find(i) != map.end())
            {
                for (int j = 0; j < (int)map[i].size(); ++j)
                {
                    if (result == "")
                    {
                        result.append(text, map[i][j], i);
                    }
                    else
                    {
                        result += " ";
                        result.append(text, map[i][j], i);
                    }
                }
            }
        }
        result[0] = toupper(result[0]);
        return result;
    }
};