// Longest common prefix
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
    int childCount;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
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
            root->childCount++;
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

    // Longest common prefix
    void lcp(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);

                // Update
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal == true)
            {
                break;
            }
        }
    }
};

// Main
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // Insert all strings into Trie
    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}

int main()
{
    vector<string> arr;
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cout << "Enter string " << i + 1 << ":" << endl;
        cin >> s;
        arr.push_back(s);
    }

    string ans = longestCommonPrefix(arr, n);
    cout << "Longest Common Prefix: " << ans << endl;
    return 0;
}