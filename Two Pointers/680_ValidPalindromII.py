
"""
680. Valid Palindromes
Difficulty -> Easy

This one is different from the first because basically if we
delete one will it be a palindrome

We want to check both ways to do it. delete the first or the
last (if we need to) this will run in O(n) because the worst 
case is we run through everything with one being deleted
"""

class Solution:
    def validPalindrome(self, s: str) -> bool:
        first, last = 0, len(s) - 1
        while first <= last:
            if s[first] == s[last]:
                first += 1
                last -= 1
            else:
                s1 = s[:first] + s[first+1:]
                s2 = s[:last] + s[last+1:]
                return s1 == s1[::-1] or s2 == s2[::-1]         
        return True