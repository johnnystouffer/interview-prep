#include <string>

using namespace std;

/**
 * 125. Valid Palindrome
 * 
 * Basically what we want to do is make sure it 
 * is a number or in the alphabet, if net move to the next 
 * character. 
 * 
 * Then compare the l and r ones, if they are not the same it is not
 * a palindrome
 */

class Solution {
public:
    bool isPalindrome(string s) {
        // create the left or right 
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < s.length() && !isalnum(tolower(s[l]))) {
                l += 1;
            }
            while (r >= 0 && !isalnum(tolower(s[r]))) {
                r -= 1;
            }
            if (l > r) {
                return true;
            }

            if (!(tolower(s[l]) == tolower(s[r]))) {
                return false;
            }

            l += 1;
            r -= 1;
        }
        return true;
    }
};