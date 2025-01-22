class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # get the left of the window
        left = 0
        # set to save all the characeters
        charSet = set()
        # len in a variable
        n = len(s)
        # save the max length
        maxLen = 0

        # we iterate through the list which will increase our window
        for right in range(n):
            # if our new character is not in the character set we add it
            if s[right] not in charSet:
                charSet.add(s[right])
                # additionally we will see if this is the new max
                maxLen = max(maxLen, right - left + 1)
            # otherwise we have a repeating character so we close the window until we find it
            else:
                # while the right letter still exists
                while s[right] in charSet:
                    # close the window by removing the left char and increase i
                    charSet.remove(s[left])
                    left += 1
                # afterwards we can add right since we removed the old version of it
                charSet.add(s[right])

        return maxLen
