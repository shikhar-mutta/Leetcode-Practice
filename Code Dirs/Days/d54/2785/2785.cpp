// Link: https://leetcode.com/problems/sort-vowels-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//  1. Create a frequency array to count the occurrences of each vowel in the input string
//  2. Iterate through the input string and for each vowel, replace it with the next vowel in the frequency array, decrementing the count of that vowel in the frequency array
//  3. Return the modified string with sorted vowels
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' ||
               ch == 'O' || ch == 'U';
    }

    string sortVowels(string s)
    {
        int freq[128] = {0};

        for (char ch : s)
        {
            if (isVowel(ch))
            {
                freq[ch]++;
            }
        }

        int current = 0;

        for (char &ch : s)
        {
            if (isVowel(ch))
            {

                while (freq[current] == 0)
                {
                    current++;
                }

                ch = current;
                freq[current]--;
            }
        }

        return s;
    }
};
