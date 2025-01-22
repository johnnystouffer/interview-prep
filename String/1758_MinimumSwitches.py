"""
1758. Minimum Changes To Make Alternating Binary String

We can easily make this O(n) where we only need to iterate over twice
There are only two ways to make this string, 0101010... or 101010....

So we chose one to do mimick, and we count how many changes we needed
and since the string are inverse we can do the minimum of count and 
the length of the string - count
"""

class Solution:

    def minOperations(self, s: str) -> int:
        count = 0

        for i in range(len(s)):
            if i % 2 == 0:
                if s[i] != '1':
                    count += 1
            else:
                if s[i] == '1':
                    count += 1

        return min(len(s) - count, count)



            

        
            