// Trie Implementation
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

    // Is Empty
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                return false;
            }
        }
        return true;
    }

    // Delete
    TrieNode *deleteUtil(TrieNode *root, string word)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        // The last character of string is being processed
        if (word.length() == 0)
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }
            // Doesn't have any children
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int index = word[0] - 'A';

        if (root->children[index] != NULL)
        {
            // Character in present (Move to the next one)
            root->children[index] = deleteUtil(root->children[index], word.substr(1));
        }
        else
        {
            // Character is absent
            cout << "String doesn't exist" << endl;
            return root;
        }

        // Recursive Call

        // Has No Children and is not a terminal --- then it is safe to delete
        if (isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }

        return root;
    }
    // Main
    void deleteWord(string word)
    {
        TrieNode *ans = deleteUtil(root, word);
    }
};

int main()
{
    Trie t;
    t.insertWord("ARM");
    t.insertWord("DO");
    t.insertWord("TIME");
    t.insertWord("TIS");

    cout << t.searchWord("TIME") << endl;
    cout << t.searchWord("TIM") << endl;

    t.deleteWord("TIS");
    t.deleteWord("TIS");
    cout << t.searchWord("TIME") << endl;

    return 0;
}