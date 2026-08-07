// Link: https://leetcode.com/problems/replace-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total dict length + sentence length) SC: O(dict)
// Approach: insert dictionary roots into a set; for each word in the sentence, check successive prefixes for membership, replacing with the shortest matching root found.
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, res;
        bool first = true;
        while (ss >> word) {
            if (!first) res += " ";
            first = false;
            string chosen = word;
            for (int len = 1; len <= (int)word.size(); len++) {
                string prefix = word.substr(0, len);
                if (roots.count(prefix)) { chosen = prefix; break; }
            }
            res += chosen;
        }
        return res;
    }
};
