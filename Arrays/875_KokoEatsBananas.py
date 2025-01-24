import math

"""
875. Koko Eating Bananas

This one has tricked me for a while but I finally figured it 
out.

Basically you do a binary search BUT you DONT need to BINARY 
SEARCH ON AN ARRAY. The answer will be between 1 and then max
of the piles, therefore we can binary search THAT

Additionally we track how many hours it would take Koko at the
given mid point, if it takes to long, then we need to do mid+1
however if we hit h, we still might be able to go faster, 
hence why we do what we do for r, instead of mid-1 we just do
mid since it may be the answer if hoursSpent == h
"""

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)

        while l < r:
            mid = (l + r) // 2

            hoursSpentx = 0
            for pile in piles:
                hoursSpent += math.ceil(pile/mid)

            if hoursSpent > h:
                l = mid + 1
            if hoursSpent <= h:
                r = mid
            
        return r