#include "../libraries.h"

using namespace std;

/**
 * 242. Valid Anagram
 * 
 * For valid anagrams we just want to store the string
 * in an easy to access way (map) and make sure that it
 * follows this correctly.
 */

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.size() != t.size()) { return false; }
    
            unordered_map<char, int> mapping;
            for (char c : s) {
                if (mapping.find(c) == mapping.end()) {
                    mapping[c] = 0;
                }
                ++mapping[c];
            }
    
            for (char c : t) {
                if (mapping.find(c) == mapping.end() || mapping[c] == 0) {
                    return false;
                }
                --mapping[c];
                if (mapping[c] == 0) { mapping.erase(c); }
            }
            if (mapping.size() != 0) { return false; }
            return true;
        }
    };