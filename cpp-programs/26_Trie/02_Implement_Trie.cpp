// Implement Trie
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insertion
    void insertUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // ASSUMPTION: All characters in word will be uppercase
        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // Character in present (Move to the next one)
            child = root->children[index];
        }
        else
        {
            // Character is absent (Create one)
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive Call
        insertUtil(child, word.substr(1));
    }
    // Main
    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // Search
    bool searchUtil(TrieNode *root, string word)
    {
        // Base Case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // Character in present (Move to the next one)
            child = root->children[index];
        }
        else
        {
            // Character is absent
            return false;
        }

        // Recursive Call
        return searchUtil(child, word.substr(1));
    }
    // Main
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    // Prefix
    bool prefixUtil(TrieNode *root, string prefix)
    {
        // Base Case
        if (prefix.length() == 0)
        {
            return true;
        }

        int index = prefix[0] - 'A';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            // Character in present (Move to the next one)
            child = root->children[index];
        }
        else
        {
            // Character is absent
            return false;
        }

        // Recursive Call
        return prefixUtil(child, prefix.substr(1));
    }
    // Main
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};

int main()
{
    Trie t;
    t.insertWord("ARM");
    t.insertWord("DO");
    t.insertWord("TIME");

    cout << t.searchWord("TIME") << endl;
    cout << t.searchWord("TIM") << endl;

    cout << t.startsWith("A") << endl;
    return 0;
}