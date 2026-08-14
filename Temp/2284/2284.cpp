// Link: https://leetcode.com/problems/sender-with-largest-word-count/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> count;
        for (int i = 0; i < (int)messages.size(); i++) {
            int words = 1;
            for (char c : messages[i]) if (c == ' ') words++;
            count[senders[i]] += words;
        }
        string best;
        int bestCount = 0;
        for (auto& [name, c] : count) {
            if (c > bestCount || (c == bestCount && name > best)) {
                bestCount = c;
                best = name;
            }
        }
        return best;
    }
};
