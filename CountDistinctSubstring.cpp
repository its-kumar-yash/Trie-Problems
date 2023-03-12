//Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.


#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


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
    
    int insert(string word){
        TrieNode* curr = root;
        int count = 0;
        
        for(int i = 0; i < word.length(); i++){
            int index = word[i] - 'a';
            
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
                count++;
            }
            
            curr = curr->children[index];
        }
        
        return count;
    }
};


/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int cnt = 0;
    
    Trie* t = new Trie();
    
    for(int i = 0; i < s.length(); i++){
        string temp = s.substr(i);
        cnt += t->insert(temp);
    }
    
    return cnt + 1;
}