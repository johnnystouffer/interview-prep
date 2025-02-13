#include "../libraries.h"

using namespace std;

/**
 * 20. Valid Parentheses
 * 
 * This is a good first ever LC problem, doing it tonight because I am tired
 * and upset because I watched youtube since my stuff was cancelled anyways.
 */

class Solution {
    public:
        bool isValid(string s) {
            stack<char> prev;
            unordered_map<char, char> ending = {{')','('}, {']','['}, {'}','{'}};
    
            for (char c : s) {
                if (ending.find(c) != ending.end()) {
                    if (!prev.empty() && prev.top() == ending[c]) {
                        prev.pop();
                        continue;
                    } else {
                        return false;
                    }
                    continue;
                }
                prev.push(c);
            }
            return prev.empty();
        }
    };