// Link: https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/description/

#include <bits/stdc++.h>
using namespace std;

static const int _ = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// TC: O(n log n) where n is the length of the string
// SC: O(n) for the hash vectors
// Approach:
//  1. We can divide the strings s and t into k substrings of equal length
//  2. We can then sort the substrings of s and t and compare them
//  3. If they are equal, then we can rearrange the substrings of s to form t
//  4. If they are not equal, then we cannot rearrange the substrings of s to form t
//  5. Finally, we return true if we can rearrange the substrings of s to form t, otherwise we return false
class Solution
{
public:
    bool isPossibleToRearrange(string s, string t, int k)
    {
        if (s == t)
            return true;

        int n = s.length();
        int m = n / k;

        // Будем хранить хеши подстрок вместо самих строк
        vector<unsigned long long> s_hashes, t_hashes;
        s_hashes.reserve(k);
        t_hashes.reserve(k);

        // Используем простое, но эффективное хеширование (Polynomial rolling hash)
        // Для коротких подстрок это на порядки быстрее, чем substr
        auto get_hash = [&](const string &str, int start, int len)
        {
            unsigned long long h = 0;
            for (int i = 0; i < len; ++i)
            {
                h = h * 31 + (str[start + i] - 'a' + 1);
            }
            return h;
        };

        for (int i = 0; i < n; i += m)
        {
            s_hashes.push_back(get_hash(s, i, m));
            t_hashes.push_back(get_hash(t, i, m));
        }

        // Сортируем числа (это в разы быстрее, чем сортировать строки)
        sort(s_hashes.begin(), s_hashes.end());
        sort(t_hashes.begin(), t_hashes.end());

        return s_hashes == t_hashes;
    }
};