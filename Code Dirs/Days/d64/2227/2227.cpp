// Link: https://leetcode.com/problems/encrypt-and-decrypt-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: encrypt O(len)  decrypt O(1) amortized  SC: O(dict_size)
// Approach: encrypt maps each char via keys->values lookup. decrypt would
// be ambiguous per-char, so precompute the encryption of every dictionary
// word once; decrypt(word2) counts how many dictionary words encrypt to
// word2 exactly (O(1) via a hashmap of encrypted-dictionary-word counts).
class Encrypter {
    unordered_map<char, string> enc;
    unordered_map<string, int> encDictCount;

    string encryptWord(const string& w) {
        string res;
        for (char c : w) {
            auto it = enc.find(c);
            if (it == enc.end()) return "";
            res += it->second;
        }
        return res;
    }

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < (int)keys.size(); i++) enc[keys[i]] = values[i];
        for (auto& w : dictionary) {
            string e = encryptWord(w);
            encDictCount[e]++;
        }
    }

    string encrypt(string word1) {
        return encryptWord(word1);
    }

    int decrypt(string word2) {
        auto it = encDictCount.find(word2);
        return it == encDictCount.end() ? 0 : it->second;
    }
};
