// Link: https://leetcode.com/problems/remove-invalid-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n) where n is the length of the string s. In the worst case, we may need to generate all possible combinations of parentheses.
    // SC: O(n) where n is the length of the string s. The recursion stack can go as deep as the length of the string s.
    // Approach:
    //  1. We can use a recursive approach to generate all possible combinations of the input string by removing invalid parentheses.
    //  2. We can keep track of the balance of parentheses while scanning the string from left to right.
    //  3. If we encounter an extra closing parenthesis, we can try removing one of the closing parentheses from the range of characters scanned so far.
    //  4. We can then recurse on the new string with the removed parenthesis and continue scanning from the same index.
    //  5. Once we finish scanning the string without any extra closing parentheses, we can reverse the string and repeat the process to remove any extra opening parentheses.
    //  6. Finally, we can add the valid strings to the result vector.
    vector<string> removeInvalidParentheses(const string &s)
    {
        vector<string> result;

        // First pass:
        // Remove invalid closing parentheses ')'
        remove(s, result, 0, 0, '(', ')');

        return result;
    }

private:
    void remove(const string &s,
                vector<string> &result,
                int scanStart,
                int removeStart,
                char openParen,
                char closeParen)
    {
        int balance = 0;

        // Scan the string from left to right.
        // balance tracks whether we have more open or close parentheses.
        for (int i = scanStart; i < static_cast<int>(s.size()); ++i)
        {
            if (s[i] == openParen)
            {
                ++balance;
            }
            else if (s[i] == closeParen)
            {
                --balance;
            }

            // As long as balance >= 0, the prefix is still valid.
            if (balance >= 0)
            {
                continue;
            }

            // If balance < 0, we found an extra closeParen.
            // We now try removing one closeParen from the range [removeStart, i].
            for (int j = removeStart; j <= i; ++j)
            {
                // Only remove closeParen candidates.
                // Also skip duplicates:
                // If there are consecutive closeParen chars, only remove the first one.
                if (s[j] == closeParen &&
                    (j == removeStart || s[j - 1] != closeParen))
                {

                    string next =
                        s.substr(0, j) + s.substr(j + 1);

                    // Recurse with:
                    // - same scan index i, because prefix before i was already checked
                    // - removeStart = j, so we do not re-remove earlier chars
                    remove(next, result, i, j, openParen, closeParen);
                }
            }

            // Important:
            // We stop here because once we detect an invalid prefix,
            // all fixes must happen before or at i.
            return;
        }

        // If we finish the scan without balance < 0,
        // then there is no extra closeParen in this direction.
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        if (openParen == '(')
        {
            // First pass is done.
            // Reverse the string and swap roles of parentheses:
            // this lets us remove extra openParen '(' using the exact same logic.
            remove(reversed, result, 0, 0, ')', '(');
        }
        else
        {
            // Second pass is done.
            // reversed is now a valid string in original order.
            result.push_back(reversed);
        }
    }
};