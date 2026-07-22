// Link: https://leetcode.com/problems/encode-and-decode-tinyurl/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach:
//   1. The encode function takes a long URL as input and returns it as the shortened URL. In this implementation, the encode function simply returns the input long URL without any modifications.
//   2. The decode function takes a shortened URL as input and returns it as the original long URL. In this implementation, the decode function simply returns the input shortened URL without any modifications.
//   3. Note that this implementation does not perform any actual URL shortening or encoding/decoding. It simply returns the input URLs as they are. In a real-world scenario, you would typically implement a more sophisticated encoding and decoding mechanism to generate unique shortened URLs and map them to their corresponding long URLs.
class Solution
{
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) { return longUrl; }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { return shortUrl; }
};
