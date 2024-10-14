// Trie Implementation in C++

#include <iostream>
#include <unordered_map>

using namespace std;

// Trie node structure
class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    // Constructor
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }

    // Check if any word in the Trie starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

// Main function to demonstrate Trie operations
int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("batman");

    cout << (trie.search("app") ? "Found 'app'" : "'app' not found") << endl;  // Output: Found 'app'
    cout << (trie.search("batman") ? "Found 'batman'" : "'batman' not found") << endl;  // Output: Found 'batman'
    cout << (trie.startsWith("bat") ? "Prefix 'bat' exists" : "Prefix 'bat' doesn't exist") << endl;  // Output: Prefix 'bat' exists
    cout << (trie.search("batwoman") ? "Found 'batwoman'" : "'batwoman' not found") << endl;  // Output: 'batwoman' not found

    return 0;
}
