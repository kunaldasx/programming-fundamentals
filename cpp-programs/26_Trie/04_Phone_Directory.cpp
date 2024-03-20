// Implement a Phone Directory
#include <iostream>
#include <vector>
#include <string>
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
        int index = word[0] - 'a';
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

    void printSuggestions(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];

            if (next != NULL)
            {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastCh = str[i];

            prefix.push_back(lastCh);

            // Check for last Character
            TrieNode *curr = prev->children[lastCh - 'a'];

            // If not found
            if (curr == NULL)
                break;

            // If found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    // Creation of Trie
    Trie *t = new Trie();

    // Insert all contacts in Trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWord(str);
    }

    // Return ans
    return t->getSuggestions(queryStr);
}

int main()
{
    vector<string> contactList;

    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ":" << endl;
        string s;
        cin >> s;
        contactList.push_back(s);
    }

    string queryStr;
    cout << "Enter the prefix: ";
    cin >> queryStr;

    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << endl;
        }
        cout << endl;
    }
    return 0;
}