"""
371. Sum of Two Integers

This was a hard one, basically sum the two numbers
together without without using add (+)... so I will 
come back to this with a better explanation

When doing the whole x ^ y, (x & y) << 1 thing it like
adds... I guess idfk bro what the hell is this
"""

class Solution:
    def getSum(self, a: int, b: int) -> int:
        x, y = abs(a), abs(b)

        if x < y:
            return self.getSum(b, a)

        sign = 1 if a > 0 else -1

        if a * b >= 0:
            while y:
                x, y = x ^ y, (x & y) << 1
        else:
            while y:
                x, y = x ^ y, (~(x) & y) << 1

        return x * sign