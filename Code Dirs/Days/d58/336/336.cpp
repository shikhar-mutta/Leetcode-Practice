// Link: https://leetcode.com/problems/palindrome-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * k^2), where n is the number of words and k is the average length of the words.
    // SC: O(n * k), where n is the number of words and k is the average length of the words.
    // Approach:
    //  1. Create a map to store the words and their indices.
    //  2. Create a set to store the lengths of the words.
    //  3. For each word, reverse it and check if it exists in the map
    //  4. If it exists, add the pair to the result.
    //  5. For each length in the set, check if the prefix or suffix of the reversed word is a palindrome and if the corresponding word exists in the map.
    //  6. If it exists, add the pair to the result.
    //  7. Return the result.
    bool isPalindrome(const string &s, int l, int r)
    {
        while (l < r)
        {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;
        unordered_map<string, int> wordMap;
        set<int> lengths;

        for (int i = 0; i < words.size(); ++i)
        {
            wordMap[words[i]] = i;
            lengths.insert(words[i].length());
        }

        for (int i = 0; i < words.size(); ++i)
        {
            string s = words[i];
            int len = s.length();
            reverse(s.begin(), s.end());

            if (wordMap.count(s) && wordMap[s] != i)
            {
                result.push_back({i, wordMap[s]});
            }

            auto it = lengths.find(len);
            for (auto lengthIt = lengths.begin(); lengthIt != it; ++lengthIt)
            {
                int d = *lengthIt;

                if (isPalindrome(s, 0, len - d - 1))
                {
                    string rcl = s.substr(len - d);
                    if (wordMap.count(rcl))
                    {
                        result.push_back({i, wordMap[rcl]});
                    }
                }

                if (isPalindrome(s, d, len - 1))
                {
                    string rcr = s.substr(0, d);
                    if (wordMap.count(rcr))
                    {
                        result.push_back({wordMap[rcr], i});
                    }
                }
            }
        }

        return result;
    }
};