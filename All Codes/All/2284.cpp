// Link: https://leetcode.com/problems/sender-with-largest-word-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total message length + distinct senders)
// SC: O(distinct senders)
// Approach: for each message, its word count is (number of spaces + 1);
// accumulate that per sender in a hash map. Track the sender with the
// highest total, breaking ties by lexicographically larger name.
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> wordCount;

        for (int i = 0; i < messages.size(); ++i) {
            int words = 1;   // one more word than the number of spaces
            for (char c : messages[i])
                if (c == ' ') ++words;
            wordCount[senders[i]] += words;
        }

        string best;
        int maxWords = 0;
        for (auto& [sender, count] : wordCount) {
            if (count > maxWords || (count == maxWords && sender > best)) {
                maxWords = count;
                best = sender;
            }
        }
        return best;
    }
};
