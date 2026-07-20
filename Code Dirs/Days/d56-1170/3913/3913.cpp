// Link: https://leetcode.com/problems/sort-vowels-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(n)
    // Approach:
    //  1. Count the frequency of each vowel in the string.
    //  2. Store the first occurrence index of each vowel.
    //  3. Sort the vowels based on their frequency (descending) and first occurrence index (ascending).
    //  4. Create a new string with the sorted vowels and replace the vowels in the original string with the sorted ones.
    //  5. Return the modified string.
    string sortVowels(string s)
    {
        auto isVowel = [](char c)
        { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        int n = s.size();
        array<int, 26> cnt{}, first;
        first.fill(INT_MAX);
        for (int i = 0; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                cnt[s[i] - 'a']++;
                first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            }
        }
        string vowels = "aeiou";
        sort(vowels.begin(), vowels.end(), [&](char a, char b)
             {
            if (cnt[a - 'a'] != cnt[b - 'a'])
                return cnt[a - 'a'] > cnt[b - 'a'];
            return first[a - 'a'] < first[b - 'a']; });
        string fill;
        for (char v : vowels)
            fill += string(cnt[v - 'a'], v);
        int j = 0;
        for (int i = 0; i < n; i++)
            if (isVowel(s[i]))
                s[i] = fill[j++];
        return s;
    }
};
