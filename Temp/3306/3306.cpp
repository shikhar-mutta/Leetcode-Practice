// Link: https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    long long atMost(const string& word, int K) {
        if (K < 0) return 0;
        int n = word.size();
        int lastSeen[5] = {-1,-1,-1,-1,-1};
        string vowels = "aeiou";
        auto vowelIdx = [&](char c) -> int {
            for (int i = 0; i < 5; i++) if (vowels[i] == c) return i;
            return -1;
        };
        int left = 0, consonants = 0;
        long long total = 0;
        for (int right = 0; right < n; right++) {
            char c = word[right];
            if (isVowel(c)) lastSeen[vowelIdx(c)] = right;
            else consonants++;

            while (consonants > K) {
                if (!isVowel(word[left])) consonants--;
                left++;
            }

            int threshold = min({lastSeen[0], lastSeen[1], lastSeen[2], lastSeen[3], lastSeen[4]});
            if (threshold >= left) total += (threshold - left + 1);
        }
        return total;
    }

    long long countOfSubstrings(string word, int k) {
        return atMost(word, k) - atMost(word, k - 1);
    }
};
