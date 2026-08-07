// Link: https://leetcode.com/problems/design-search-autocomplete-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(S) per input() where S = number of stored sentences SC: O(S)
// Approach: maintain a frequency map of complete sentences; accumulate the typed prefix until '#', then linear-scan all sentences with matching prefix, sort by (-freq, lexicographic), take top 3.
class AutocompleteSystem {
    unordered_map<string,int> freq;
    string cur;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < (int)sentences.size(); i++) freq[sentences[i]] = times[i];
    }

    vector<string> input(char c) {
        if (c == '#') {
            freq[cur]++;
            cur.clear();
            return {};
        }
        cur += c;
        vector<pair<string,int>> matches;
        for (auto& [s, f] : freq) {
            if (s.size() >= cur.size() && s.compare(0, cur.size(), cur) == 0) matches.push_back({s, f});
        }
        sort(matches.begin(), matches.end(), [](auto& a, auto& b){
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        vector<string> res;
        for (int i = 0; i < (int)matches.size() && i < 3; i++) res.push_back(matches[i].first);
        return res;
    }
};
