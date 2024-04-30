// 1915. Number of Wonderful Substrings
// Medium

// 1466

// 191

// Add to List

// Share
// A wonderful string is a string where at most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
// Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: word = "aba"
// Output: 4
// Explanation: The four wonderful substrings are underlined below:
// - "aba" -> "a"
// - "aba" -> "b"
// - "aba" -> "a"
// - "aba" -> "aba"
// Example 2:

// Input: word = "aabb"
// Output: 9
// Explanation: The nine wonderful substrings are underlined below:
// - "aabb" -> "a"
// - "aabb" -> "aa"
// - "aabb" -> "aab"
// - "aabb" -> "aabb"
// - "aabb" -> "a"
// - "aabb" -> "abb"
// - "aabb" -> "b"
// - "aabb" -> "bb"
// - "aabb" -> "b"
// Example 3:

// Input: word = "he"
// Output: 2
// Explanation: The two wonderful substrings are underlined below:
// - "he" -> "h"
// - "he" -> "e"
 

// Constraints:

// 1 <= word.length <= 105
// word consists of lowercase English letters from 'a' to 'j'.

class Solution {
public:
   long long wonderfulSubstrings(string& word) {
        uint16_t freq[1024] = {0}; // parity for 'a'~'j'
        uint16_t sum = 0;
        freq[0] = 1; // empty string counts 1
        for (int c : word) {
            int index = c - 'a';
            sum ^= (1 << index);
            freq[sum]++;
        }

        long long cnt = 0, cnt1 = 0;// even,  odd
        for (int i = 0; i < 1024; i++) { // start from i = 0
            long long f = freq[i];
            if (f == 0)
                continue;
            cnt += f*(f-1) / 2; // count substrings with even frequency once
            for (char b = 0; b < 10; b++) {
                int j=i^(1<< b); // all possible single bit differences
                cnt1+=f*freq[j]; // count substrings with one odd frequency
                                // they are counted twice
            }
        }
        return cnt + cnt1 / 2;
    }
};