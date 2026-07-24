// Link: https://leetcode.com/problems/sentence-similarity-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TC: O(n), SC: O(n)
    //Approach: Two Pointers
    // 1. We can split the sentences into words and store them in two vectors.
    // 2. We can use two pointers to compare the words from the beginning and the end of the vectors.
    // 3. If the words are equal, we can move the pointers inward. If the words are not equal, we can check if the remaining words in the shorter vector can be matched with the remaining words in the longer vector.
    // 4. If the pointers meet in the middle, we can return true. Otherwise, we can return false.
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> a = split(sentence1), b = split(sentence2);
        if (a.size() > b.size())
            swap(a, b);

        int m = a.size(), n = b.size();
        int i = 0;
        while (i < m && a[i] == b[i])
            ++i;

        int j = 0;
        while (j < m - i && a[m - 1 - j] == b[n - 1 - j])
            ++j;

        return i + j == m;
    }

private:
    vector<string> split(const string &s)
    {
        vector<string> res;
        stringstream ss(s);
        string w;
        while (ss >> w)
            res.push_back(w);
        return res;
    }
};