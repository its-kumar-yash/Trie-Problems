// Given a array of N strings, find the longest common prefix among all strings present in the array.

// Google Microsoft

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Approach 1 - Brute Force Solution

    string longestCommonPrefix(string arr[], int N)
    {
        string ans = "";

        // iterating over first string and checking its prefix in other string
        for (int i = 0; i < arr[0].length(); i++)
        {
            char ch = arr[0][i];

            bool match = true;

            // check char in remaining strings
            for (int j = 1; j < N; j++)
            {

                // if not match
                if (arr[j].length() < i || ch != arr[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }

        if (ans.length() == 0)
        {
            return "-1";
        }

        return ans;
    }




    //Approach 2 Using Trie

    class TrieNode
    {
    public:
        TrieNode *children[26];
        bool isEnd;
        int childrenCount;

        // constuctor
        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            isEnd = false;
            childrenCount = 0;
        }
    };

    class Trie
    {
    public:
        TrieNode *root;

        Trie()
        {
            root = new TrieNode();
        }

        void insert(string word)
        {
            TrieNode *curr = root;

            for (int i = 0; i < word.length(); i++)
            {
                int index = word[i] - 'a';

                if (curr->children[index] == NULL)
                {
                    curr->children[index] = new TrieNode();
                    curr->childrenCount++;
                }

                curr = curr->children[index];
            }

            curr->isEnd = true;
        }

        string lcp(string first)
        {

            string ans = "";

            for (int i = 0; i < first.size(); i++)
            {

                char ch = first[i];

                if (root->childrenCount == 1)
                {

                    ans.push_back(ch);
                    // aage badho

                    int index = ch - 'a';

                    root = root->children[index];
                }
                else
                {
                    break;
                }

                if (root->isEnd == true)
                {
                    break;
                }
            }

            return ans;
        }
    };

    string longestCommonPrefix(string arr[], int N)
    {

        Trie *root = new Trie();

        // insert all string into trie
        for (int i = 0; i < N; i++)
        {
            string str = arr[i];

            root->insert(str);
        }

        string first = arr[0];

        string ans = root->lcp(first);

        if (ans.length() == 0)
        {
            return "-1";
        }
        else
        {
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends