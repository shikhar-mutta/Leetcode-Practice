// Link: https://leetcode.com/problems/goat-latin/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(n).
    string toGoatLatin(string sentence)
    {
        int n = sentence.size(), cnt = 1, i = 0;
        string ans;
        while (n > i)
        {
            string word;
            while (n > i && sentence[i] != ' ')
                word += sentence[i++];
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' ||
                word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
                ans += word + "ma" + string(cnt, 'a') + " ";
            else
                ans += word.substr(1) + word[0] + "ma" + string(cnt, 'a') + " ";
            cnt++;
            i++;
        }
        ans.pop_back();
        return ans;
    }
};
