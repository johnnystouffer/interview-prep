#include <unordered_map>
#include <string>

using namespace std;

/**
 * 3. Longest Substring with No Repeated Characters
 * 
 * A simple sliding window problem, the nice thing about this problem
 * is that it is the definition of a sliding window, basically
 * all we do is iterate through the array and move the left if we found
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if the string is empty then its 0
        if (s.length() == 0) {
            return 0;
        }

        // make the max, the sliding window numbers and the map 
        // to keep track of everything
        int l = 0, r = 0;
        int maxNum = 1;
        unordered_map<char, int> seenBefore;

        // loop through the string
        for (;r < s.length(); r++) {
            // if we have seen it before then update l (unless we already passed it)
            if (seenBefore.find(s[r]) != seenBefore.end()) {
                l = max(seenBefore[s[r]] + 1, l);
            }

            // mark that we have seen it then update our max number
            seenBefore[s[r]] = r;
            maxNum = max(r - l + 1, maxNum);
        }
        return maxNum;
    }
};