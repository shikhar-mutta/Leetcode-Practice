// Link: https://leetcode.com/problems/count-substrings-divisible-by-last-digit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: For each digit, we maintain the prefix modulo for 3, 7, and 9. We also maintain the count of prefixes for each modulo value. For each digit, we can calculate the number of substrings that end at that digit and are divisible by the last digit. We can do this by checking the prefix modulo for 3, 7, and 9 and using the counts of prefixes to calculate the number of valid substrings. For digits 4 and 8, we check the last two and three digits respectively to see if they are divisible by 4 or 8. For digit 0, we can add the number of substrings that end at that digit and are divisible by 10. For digits 1, 2, and 5, we can add the number of substrings that end at that digit and are divisible by 1, 2, or 5 respectively.
class Solution
{
public:
    long long countSubstrings(string s)
    {
        int n = s.size();
        long long ans = 0;
        vector<long long> cnt3(3, 0), cnt9(9, 0);
        cnt3[0] = 1;
        cnt9[0] = 1;

        int pref3 = 0, pref9 = 0;
        vector<int> invPow7(n + 1, 1);
        int inv10 = 5;
        for (int i = 1; i <= n; i++)
            invPow7[i] = (invPow7[i - 1] * inv10) % 7;

        vector<long long> cnt7(7, 0);
        cnt7[0] = 1;

        int pref7 = 0;

        for (int i = 0; i < n; i++)
        {
            int d = s[i] - '0';

            pref3 = (pref3 * 10 + d) % 3;
            pref9 = (pref9 * 10 + d) % 9;
            pref7 = (pref7 * 10 + d) % 7;

            switch (d)
            {
            case 0:
                break;

            case 1:
            case 2:
            case 5:
                ans += (i + 1);
                break;

            case 3:
            case 6:
                ans += cnt3[pref3];
                break;

            case 9:
                ans += cnt9[pref9];
                break;

            case 4:
            {
                ans += 1; // single digit
                if (i >= 1)
                {
                    int x = (s[i - 1] - '0') * 10 + d;
                    if (x % 4 == 0)
                        ans += i;
                }
                break;
            }

            case 8:
            {
                ans += 1;
                if (i >= 1)
                {
                    int x = (s[i - 1] - '0') * 10 + d;
                    if (x % 8 == 0)
                        ans += 1;
                }
                if (i >= 2)
                {
                    int x = (s[i - 2] - '0') * 100 + (s[i - 1] - '0') * 10 + d;
                    if (x % 8 == 0)
                        ans += (i - 1);
                }
                break;
            }

            case 7:
            {
                int key = (pref7 * invPow7[i + 1]) % 7;
                ans += cnt7[key];
                break;
            }
            }

            cnt3[pref3]++;
            cnt9[pref9]++;
            int key7 = (pref7 * invPow7[i + 1]) % 7;
            cnt7[key7]++;
        }

        return ans;
    }
};
