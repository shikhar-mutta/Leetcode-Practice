// Link: https://leetcode.com/problems/decode-the-slanted-ciphertext/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach:
// 1. We can first check if the number of rows is equal to 1. If it is, we can return the input string as the answer.
// 2. We can then calculate the number of columns by dividing the length of the input string by the number of rows.
// 3. We can then create a vector of strings to store the rows of the input string.
// 4. We can then iterate through the rows and columns of the input string and store the characters in the vector of strings.
// 5. We can then iterate through the vector of strings and construct the decoded string by appending the characters in the correct order.
// 6. We can then remove any trailing spaces from the decoded string
// 7. We can return the decoded string as the answer.
class Solution
{
public:
    string decodeCiphertext(string s, int rows)
    {
        if (rows == 1)
            return s;
        int n = s.length();
        if (n == 0)
            return "";
        vector<string> temp;
        n = n / rows;
        int cur = 0;
        for (int i = 0; i < rows; i++)
        {
            temp.push_back(s.substr(cur, n));
            cur += n;
        }
        string ans = "";
        for (int i = 0; i < abs(n - rows + 2); i++)
        {
            for (int j = 0; j < rows; j++)
                ans.push_back(temp[j][i + j]);
        }
        ans.pop_back();
        while (ans[ans.length() - 1] == ' ')
            ans.pop_back();
        return ans;
    }
};