// Link: https://leetcode.com/problems/encrypt-and-decrypt-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: encrypt O(len)  decrypt O(1) amortized  SC: O(dict_size)
//  Approach: encrypt maps each char via keys->values lookup. decrypt would
//  be ambiguous per-char, so precompute the encryption of every dictionary
//  word once; decrypt(word2) counts how many dictionary words encrypt to
//  word2 exactly (O(1) via a hashmap of encrypted-dictionary-word counts).
class Encrypter
{
public:
    Encrypter(vector<char> &keys, vector<string> &values,
              vector<string> &dictionary)
    {
        for (int i = 0; i < keys.size(); ++i)
        {
            char key = keys[i];
            string &val = values[i];
            charToEncryptedStr[key - 'a'] = val;
        }

        // precompute all possible words - since they are at most 100, beats
        // trying all 2^n combinations and finding at most 100.
        for (const auto &word : dictionary)
        {
            ++encryptedStringCounts[encrypt(word)];
        }
    }

    string encrypt(const string &word1)
    {
        string soln;
        soln.reserve(word1.size() * 2);
        for (char c : word1)
        {
            const string &encrypted = charToEncryptedStr[c - 'a'];
            if (!encrypted.size())
            {
                return "";
            }
            soln.append(encrypted);
        }
        return soln;
    }

    int decrypt(const string &word2)
    {
        auto it = encryptedStringCounts.find(word2);
        if (it == encryptedStringCounts.end())
        {
            return 0;
        }
        return it->second;
    }

private:
    array<string, 26> charToEncryptedStr{};             // 'a' -> "ez"
    unordered_map<string, int> encryptedStringCounts{}; // "ezfghz" -> 3
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */