// Link: https://leetcode.com/problems/merge-close-characters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
//  Approach: Use a sliding window of size k to keep track of the last k characters seen.
//  If a character is seen again, skip it. When the window exceeds size k, remove the oldest character from the answer and the seen set. Finally, append any remaining characters in the window to the answer.
class Solution
{
public:
    string mergeCharacters(string s, int k)
    {
        int n = s.length();
        vector<char> last_k;
        vector<int> seen(26, 0);
        string ans = "";
        int start = 0;
        for (char &ch : s)
        {
            if (seen[ch - 'a'] > 0)
                continue;
            seen[ch - 'a']++;
            last_k.push_back(ch);

            if ((int)last_k.size() > k)
            {
                char rem = last_k[start++];
                ans += rem;
                seen[rem - 'a']--;
            }
        }
        for (int i = start; i < min(start + k, (int)last_k.size()); i++)
        {
            ans += last_k[i];
        }
        return ans;
    }
};