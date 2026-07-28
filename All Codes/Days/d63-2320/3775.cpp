// Link: https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: two pointers to traverse the string, count vowels in the first word,
//  then reverse each subsequent word whose vowel count matches the target.
class Solution
{
public:
    string reverseWords(string s)
    {
        auto it1 = s.begin();
        auto it2 = s.begin();
        const char vowels[] = "aeiou";

        int frst_v = 0;
        while (it1 < s.end() && *it1 != ' ')
        {
            for (char c : vowels)
                if (*it1 == c)
                {
                    frst_v++;
                    break;
                }

            it1++;
        }

        it1++;
        it2 = it1;

        while (it1 < s.end())
        {
            // assert(*it1 != ' ');
            it2 = it1;
            int v = 0;

            while (it1 < s.end() && *it1 != ' ')
            {
                // cout << *it1 << '\n';
                // if (v <= frst_v)
                for (char c : vowels)
                    if (*it1 == c)
                    {
                        v++;
                        break;
                    }
                it1++;
            }

            if (v == frst_v)
            {
                reverse(it2, it1);
                // cout << s << '\n';
            }
            it1++;
        }

        return s;
    }
};