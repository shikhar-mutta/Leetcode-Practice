// Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepOpt1(string text)
    {
        int n = text.size();
        unordered_map<char, int> m;
        vector<pair<char, int>> vec;
        for (int i = 0; i < n; i++)
            m[text[i]]++;
        char ch = text[0];
        int freq = 1;
        for (int i = 1; i < n; i++)
        {
            if (ch == text[i])
                freq++;
            else
            {
                vec.push_back({ch, freq});
                ch = text[i];
                freq = 1;
            }
        }
        vec.push_back({ch, freq});
        int maxLen = INT_MIN;
        for (int i = 0; i < vec.size(); i++)
        {
            maxLen = max(maxLen, min(vec[i].second + 1, m[vec[i].first]));
        }
        for (int i = 1; i < vec.size() - 1; i++)
        {
            if (vec[i].second == 1 && (vec[i - 1].first == vec[i + 1].first))
            {
                int len = vec[i - 1].second + vec[i + 1].second;
                if (m[vec[i - 1].first] > len)
                    len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};