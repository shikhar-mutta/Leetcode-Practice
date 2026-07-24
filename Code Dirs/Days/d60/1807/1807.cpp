// Link: https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach: Hash Map
    // 1. We can use a hash map to store the key-value pairs from the knowledge vector.
    // 2. We can iterate through the string s and whenever we encounter a '(', we can extract the key and check if it exists in the hash map. If it does, we can append the corresponding value to the answer string. If it doesn't, we can append a '?' to the answer string. If we encounter any other character, we can simply append it to the answer string.
    // 3. Finally, we can return the answer string.
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        string ans;
        unordered_map<string, string> mp;
        for (auto &it : knowledge)
        {
            mp[it[0]] = it[1];
        }

        int n = s.size();
        int ind = 0;
        while (ind < n)
        {

            if (s[ind] == '(')
            {

                string word;
                ind++;
                while (ind < n && s[ind] != ')')
                {
                    word += s[ind];
                    ind++;
                }
                ind++;
                if (mp.count(word))
                {
                    ans += mp[word];
                }
                else
                {
                    ans += "?";
                }
            }
            else
            {
                ans += s[ind];
                ind++;
            }
        }
        return ans;
    }
};