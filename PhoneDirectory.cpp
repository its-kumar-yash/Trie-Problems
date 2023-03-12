//Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
//Note: If there is no match between query and contacts, print "0".

//Expected Time Complexity: O(|s| * n * max|contact[i]|)
//Expected Auxiliary Space: O(n * max|contact[i]|)


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    
    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();    
    }
    
    void insert(string word){
        TrieNode* curr = root;
        
        for(int i = 0; i< word.length(); i++){
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }
            
            curr = curr->children[index];
        }
        
        curr->isEnd = true;
    }
    
    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->isEnd){
            temp.push_back(prefix);
        }
        
        for(char i = 'a'; i <= 'z'; i++){
            TrieNode* next = curr->children[i - 'a'];
            
            if(next != NULL){
                prefix.push_back(i);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string s){
        TrieNode* prev = root;
        
        vector<vector<string>> ans;
        
        string prefix = "";
        
        int i = 0;
        
        for(i = 0; i < s.length(); i++){
            
            char lastChar = s[i];
            
            prefix.push_back(lastChar);
            
            //check for last char
            TrieNode* curr = prev->children[lastChar - 'a'];
            
            if(curr == NULL){
                break;
            }
            
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            
            ans.push_back(temp);
            temp.clear();
            
            prev = curr;
        }
        
        if(i < s.size()){
            while(i < s.size()){
                ans.push_back({"0"});
                i++;
            }
        }
        
        return ans;
    }
    
    
};



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* root = new Trie();
        
        //insert all string into trie
        for(int i = 0; i < n; i++){
            string t = contact[i];
            
            root->insert(t);
        }
        
        //return ans
        return root->getSuggestions(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends