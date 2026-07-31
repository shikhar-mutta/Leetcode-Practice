// Link: https://leetcode.com/problems/count-complete-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26 * k), SC: O(26)
//  Approach: We can use a sliding window approach to find the count of complete substrings.
//  A complete substring is defined as a substring where each character appears exactly k times. We can iterate through the string and for each character, we can maintain a frequency array to count the occurrences of each character in the current window. We can also maintain a variable to keep track of the number of characters that have exactly k occurrences. If this variable equals the number of unique characters in the current window, we have found a complete substring. We can then slide the window and update the frequency array and the variable accordingly. Finally, we return the total count of complete substrings found.
class Solution
{
public:
    int solve(string &s, int start, int end, int k)
    {
        int ans = 0;
        int m = end - start + 1;

        for (int t = 1; t <= 26; t++)
        {
            int len = t * k;
            if (len > m)
                break;

            vector<int> freq(26, 0);
            int exactlyK = 0;

            for (int i = start; i < start + len; i++)
            {
                int c = s[i] - 'a';
                if (freq[c] == k)
                    exactlyK--;
                freq[c]++;
                if (freq[c] == k)
                    exactlyK++;
            }

            if (exactlyK == t)
                ans++;

            for (int r = start + len; r <= end; r++)
            {
                int l = r - len;

                int c = s[l] - 'a';
                if (freq[c] == k)
                    exactlyK--;
                freq[c]--;
                if (freq[c] == k)
                    exactlyK++;

                c = s[r] - 'a';
                if (freq[c] == k)
                    exactlyK--;
                freq[c]++;
                if (freq[c] == k)
                    exactlyK++;

                if (exactlyK == t)
                    ans++;
            }
        }

        return ans;
    }

    int countCompleteSubstrings(string word, int k)
    {
        int n = word.size();
        int ans = 0;
        int start = 0;

        for (int i = 1; i < n; i++)
        {
            if (abs(word[i] - word[i - 1]) > 2)
            {
                ans += solve(word, start, i - 1, k);
                start = i;
            }
        }

        ans += solve(word, start, n - 1, k);
        return ans;
    }
};
