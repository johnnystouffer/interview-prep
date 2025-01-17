"""
125. Valid Palindrome

This is a very straight forward solution
you get two pointers at each end of the 
string and make sure all alphanumeric chars
match up with eachother...

Ignore the fact I could not get it for a bit
rip.
"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1

        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1

            if s[l].lower() != s[r].lower():
                return False
            
            l += 1
            r -= 1
            
        return True