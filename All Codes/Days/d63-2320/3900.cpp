// Link: https://leetcode.com/problems/longest-balanced-substring-after-one-swap/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: prefix sum pre[i] = (#1s - #0s) up to i. A balanced
//  substring corresponds to equal prefix sums (diff 0). A single swap can
//  only close a gap of 2 (moving a surplus '1' or '0' out), so also check
//  substrings whose prefix-sum difference is +-2, provided a character
//  of the needed type still exists OUTSIDE that substring to swap in
//  (checked via total counts, trying the earliest matching prefix
//  position first, falling back to the second-earliest if that one
//  doesn't leave a spare character outside).
class Solution
{
public:
    int longestBalanced(string s)
    {
        int n = s.size();
        int Z = count(s.begin(), s.end(), '0');
        int O = n - Z;

        // f1/f2 = prima e seconda occorrenza di ogni valore di prefisso (offset +n)
        vector<int> f1(2 * n + 1, -2), f2(2 * n + 1, -2);
        int P = 0;
        f1[n] = 0; // prefisso 0 all'indice 0
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            P += (s[i - 1] == '1') ? 1 : -1;
            int idx = P + n;

            // diff 0: già bilanciato, nessun vincolo
            if (f1[idx] != -2)
                ans = max(ans, i - f1[idx]);

            // diff +2: due '1' in più, serve uno '0' fuori → len <= 2Z
            if (idx - 2 >= 0 && f1[idx - 2] != -2)
            {
                int len = i - f1[idx - 2];
                if (len <= 2 * Z)
                    ans = max(ans, len);
                else if (f2[idx - 2] != -2)
                    ans = max(ans, i - f2[idx - 2]);
            }

            // diff -2: due '0' in più, serve un '1' fuori → len <= 2O
            if (idx + 2 <= 2 * n && f1[idx + 2] != -2)
            {
                int len = i - f1[idx + 2];
                if (len <= 2 * O)
                    ans = max(ans, len);
                else if (f2[idx + 2] != -2)
                    ans = max(ans, i - f2[idx + 2]);
            }

            // registra l'occorrenza del prefisso corrente
            if (f1[idx] == -2)
                f1[idx] = i;
            else if (f2[idx] == -2)
                f2[idx] = i;
        }
        return ans;
    }
};