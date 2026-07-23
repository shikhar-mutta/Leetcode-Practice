// Link: https://leetcode.com/problems/vowel-spellchecker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), SC: O(n)
// Approach: Hashing
//  1. We will use a hash set to store the words in the wordlist
//  2. We will use a hash map to store the lowercase version of the words in the wordlist
//  3. We will use a hash map to store the vowel version of the words in the wordlist
//  4. For each query, we will check if it is present in the hash set, if yes we will return it
//  5. If not, we will check if the lowercase version of the query is present in the hash map, if yes we will return the corresponding word from the wordlist
//  6. If not, we will check if the vowel version of the query is present in the hash map, if yes we will return the corresponding word from the wordlist
//  7. If not, we will return an empty string
class Solution
{
    string lower(const string &s)
    {
        string s2(s);
        for (char &c : s2)
            c = tolower(c);
        s2.push_back('.');
        return s2;
    }
    bool isvowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string vowel(const string &s)
    {
        string s2(s);
        for (char &c : s2)
        {
            c = tolower(c);
            if (isvowel(c))
                c = '*';
        }
        s2.push_back('.');
        return s2;
    }

public:
    vector<string> spellchecker(vector<string> &wordlist,
                                vector<string> &queries)
    {
        unordered_set<string> st;
        unordered_map<string, string> mp;
        for (const auto &s : wordlist)
            mp[s] = s;

        for (const auto &s : wordlist)
        {
            string s2 = lower(s);
            if (mp.count(s2) == 0)
            {
                mp[s2] = s;
            }
            string s3 = vowel(s);
            if (mp.count(s3) == 0)
            {
                mp[s3] = s;
            }
        }

        vector<string> ans;
        ans.reserve(queries.size());
        for (const auto &q : queries)
        {
            if (mp.count(q))
            {
                ans.push_back(q);
                continue;
            }
            string s2 = lower(q);
            if (mp.count(s2))
            {
                ans.push_back(mp[s2]);
                continue;
            }
            string s3 = vowel(q);
            if (mp.count(s3))
            {
                ans.push_back(mp[s3]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};