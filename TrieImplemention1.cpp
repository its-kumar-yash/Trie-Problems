#include<bits/stdc++.h>
using namespace std;

// ** Babbar Implementation **

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        //constructor
        TrieNode(char ch){
            data = ch;

            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtilWord(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                //last node terminal position
                root->isTerminal = true;
                return;
            }

            //asumptions words will be in capital alphabets A -Z
            int index = word[0] - 'A';
            TrieNode* child;

            ///present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                //absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //recursive call for rest of words
            insertUtilWord(child, word.substr(1));
        }

        void insertWord(string word){
            insertUtilWord(root, word);
        }


        bool searchUtilWord(TrieNode *root, string word){
            //base case
            if(word.length() == 0){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            else{
                //absent
                return false;
            }

            //recurive
            return searchUtilWord(child, word.substr(1));
        }

        bool searchWord(string word){
            return searchUtilWord(root, word);
        }

        bool removeUtilWord(TrieNode *root, string word){

            //base case
            if(word.length() == 0){
                //make isterminal false
                root->isTerminal = false;
                return true;
            }

            //rest is same as searching algo
            int index = word[0] - 'A';
            TrieNode* child;

            //Present
            if(root->children[index] != NULL){
                child = root->children[index];
            }
            //absent
            else{
                return false;
            }

            return removeUtilWord(child, word.substr(1));
        }

        bool removeWord(string word){
            return removeUtilWord(root, word);
        }
};

int main(){

    Trie *t = new Trie();
    t->insertWord("ABCD");

    cout<<"Present "<< t->searchWord("ABCD") << endl;
    
    cout<<t->removeWord("ABCD")<<endl;

    cout<<"Absent "<< t->searchWord("ABCD") << endl;

    return 0;
}




