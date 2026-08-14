// Link: https://leetcode.com/problems/encrypt-and-decrypt-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Encrypter {
    unordered_map<char,string> keyToVal;
    unordered_map<string,int> decryptCount;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < (int)keys.size(); i++) keyToVal[keys[i]] = values[i];
        for (auto& w : dictionary) {
            string enc = encrypt(w);
            decryptCount[enc]++;
        }
    }

    string encrypt(string word1) {
        string res;
        for (char c : word1) {
            if (!keyToVal.count(c)) return "";
            res += keyToVal[c];
        }
        return res;
    }

    int decrypt(string word2) {
        auto it = decryptCount.find(word2);
        return it == decryptCount.end() ? 0 : it->second;
    }
};
