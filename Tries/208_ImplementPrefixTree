class TrieNode:
    """
    A Trie Node to keep track of each individual letter and what
    follows it
    """
    def __init__(self):
        self.dic = {}
        self.end = False

class Trie:
    # initialize the root node which is nothing really it just holds the first letters
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserting a word into the Trie
        It will still fail if you try to add a word that
        has already been added, it just won't do anything
        meaningful
        
        param word: the word we are adding to the tree
        """
        currNode = self.root
        for char in word:
            if char not in currNode.dic:
                currNode.dic[char] = TrieNode()
            currNode = currNode.dic[char]
        currNode.end = True

    def search(self, word: str) -> bool:
        """
        Searching for a word in the Trie 
        If there is a word but it was not specifically
        added it will return false since that letter
        was not considered the end of the word

        param word: the word we are searching for
        """
        currNode = self.root
        for char in word:
            if char not in currNode.dic:
                return False
            currNode = currNode.dic[char]
        if currNode.end != True:
            return False
        return True
        

    def startsWith(self, prefix: str) -> bool:
        """
        Searching for the start of the word
        If the letters are an entire word or the start
        of the word then it will return true, otherwise
        false

        param prefix: the word we are searching for
        """
        currNode = self.root
        for char in prefix:
            if char not in currNode.dic:
                return False
            currNode = currNode.dic[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)