// Link: https://leetcode.com/problems/count-vowel-substrings-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int count_Vowel_At_Most_K_Unique_Vowels(string s, int k)
    {
        unordered_map<char, int> freq;
        int count = 0;
        int left = 0, right = 0;
        while (right < s.size())
        {
            if (!isVowel(s[right])) // Reset window
            {
                left = right + 1;
                right++;
                freq.clear();
                continue;
            }
            freq[s[right++]]++;
            while (freq.size() > k)
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int countVowelSubstrings(string word)
    {
        return (count_Vowel_At_Most_K_Unique_Vowels(word, 5) -
                count_Vowel_At_Most_K_Unique_Vowels(word, 4));
    }
};