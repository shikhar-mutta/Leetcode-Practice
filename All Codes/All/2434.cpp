// Link: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the size of the input string s.
// SC: O(n), as we are using a stack to store the characters of the input string s.
//  Approach:
//   1. We initialize a vector count of size 26 to keep track of the count of each character in the input string s.
//   2. We iterate through each character of the input string s and increment the count of the corresponding character in the count vector.
//   3. We initialize a stack tstack to store the characters of the input string s and a string ans to store the final answer.
//   4. We iterate through each character of the input string s using a while loop. For each character, we find the minimum character that is still present in the count vector. We then push characters from the input string s to the stack until we reach the minimum character. We then pop characters from the stack and append them to the ans string until we reach the minimum character. We then decrement the count of the minimum character in the count vector and append it to the ans string. We repeat this process until we have processed all characters of the input string s.
//  5. Finally, we pop any remaining characters from the stack and append them to the ans string
class Solution
{
public:
    string robotWithString(string s)
    {
        vector<int> count(26, 0);

        for (char ch : s)
        {
            count[ch - 'a']++;
        }

        int n = s.size();
        stack<char> tstack;
        int curr = 0;
        string ans = "";
        while (curr < n)
        {

            // get min index
            int min_char = 0;
            for (min_char = 0; min_char < 26; min_char++)
            {
                if (count[min_char] > 0)
                {
                    break;
                }
            }
            if (min_char >= 26)
            {
                break;
            }

            // now lets push to stack until minchar comes
            min_char += 'a';

            while (!tstack.empty() && tstack.top() <= min_char)
            {
                ans += tstack.top();
                tstack.pop();
            }
            count[min_char - 'a']--;
            ans += (char)min_char;

            while (curr < n && s[curr] != min_char)
            {
                tstack.push(s[curr]);
                count[s[curr] - 'a']--;
                curr++;
            }
            curr++;
        }

        while (!tstack.empty())
        {
            ans += tstack.top();
            tstack.pop();
        }
        return ans;
    }
};