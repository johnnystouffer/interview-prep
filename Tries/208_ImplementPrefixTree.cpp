#include <string>

using namespace std;

/**
 * 208. Implement Trie (Prefix Tree)
 * 
 * Implementing a prefix tree in C++
 * This was a good way to learn how to 
 * do memory management in C++ so 
 * woohoo
 */

struct TrieNode {
    TrieNode* children[26];
    bool end = false;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char i : word) {
            int index = i - 'a';

            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->end = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;

        for (char i : word) {
            int index = i - 'a';

            if (!node->children[index]) {
                return false;
            }

            node = node->children[index];
        }
        if (!node->end) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char i : prefix) {
            int index = i - 'a';

            if (!node->children[index]) {
                return false;
            }

            node = node->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */