from typing import List

"""
17. Letter Combinations of a Phone Number
Difficulty -> Medium

This is an example of combinations, we can use combinations
and back tracking to add all the different ways to interpret
by saving all the hashLetters in a map, alternatively if you
don't want to type that out you can use ASCII values but
Z will make it a little harder.
"""

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def letterRecurse(currStr, i):
            if i == len(digits):
                if currStr != '':
                    allLists.append(currStr[:])
                return
            
            for letter in hashLetters[digits[i]]:
                currStr += letter
                letterRecurse(currStr, i+1)
                currStr = currStr[:-1]
        
        allLists = []

        hashLetters = {"2": "abc",
         "3": "def",
          "4":"ghi", 
          "5":"jkl", 
          "6":"mno", 
          "7":"pqrs", 
          "8":"tuv", 
          "9":"wxyz"}

        letterRecurse("", 0)
        return allLists

        


