#include<bits/stdc++.h>
using namespace std;

// ** Striver Implementation**

// Iterative Approach


//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);


// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    TrieNode* curr = root;
    
    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        //absent
        if(curr->children[index] == NULL){
            curr->children[index] = new TrieNode();
        }
        
        curr = curr->children[index];
    }
    
    curr->isLeaf = 1;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* curr = root;
    
    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        
        if(curr->children[index] == NULL){
            return false;    
        }
        
        curr = curr->children[index];
    }
    
    return curr->isLeaf;
    
}


#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define MAX 10^19
// Alphabet size (# of symbols)
 
#define ALPHABET_SIZE (26)
#define INDEX(c) ((int)c - (int)'a')
 
#define FREE(p) \
    free(p);    \
    p = NULL;
using namespace std;
 
// forward declration
typedef struct trie_node trie_node_t;
 
// trie node
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};
 
// trie ADT
typedef struct trie trie_t;
 
struct trie
{
    trie_node_t *root;
    int count;
};
void deleteKey(trie_node_t *root, char key[]);
trie_node_t *getNode1(void)
{
    trie_node_t *pNode = NULL;
 
    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));
 
    if( pNode )
    {
        int i;
 
        pNode->value   = 0;
 
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
 
    return pNode;
}
 
void initialize(trie_t *pTrie)
{
    pTrie->root = getNode1();
    pTrie->count = 0;
}
 
void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( pCrawl->children[index] )
        {
            // Skip current node
            pCrawl = pCrawl->children[index];
        }
        else
        {
            // Add new node
            pCrawl->children[index] = getNode1();
            pCrawl = pCrawl->children[index];
        }
    }
 
    // mark last node as leaf (non zero)
    pCrawl->value = pTrie->count;
}
 
int ifExsist(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
    if( !pCrawl)
        {
            return 0;
        }
    for( level = 0; level < length; level++ )
    {
        index = INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    if(pCrawl && pCrawl->value)
        return 1;
    else
        return 0;
}
int compare_strings(char a[], char b[]){
    if(strlen(a)!=strlen(b))
        return 1;
    for(int i=0;i<strlen(a);i++){
        if(a[i]!=b[i])
            return 1;
    }
    return 0;
}

// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};*/
class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
    trie_node_t *curr = root;
    
    for(int i = 0; i < strlen(key); i++){
        
        int index = key[i] - 'a';
        
        curr = curr->children[index];
    }
    
    curr->value = 0;
  }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char keys[MAX][MAX];
        for(int i=0;i<n;i++){
            fflush(stdin);
            cin>>keys[i];
        }
        trie_t trie;
        initialize(&trie);
        for(int i = 0; i < n; i++){
            insert(&trie, keys[i]);
        }
        char abc[MAX];
        fflush(stdin);
        cin>>abc;
        Solution obj;
        obj.deleteKey(trie.root, abc);
        if(ifExsist(&trie, abc)==false){
            int f1=0;
            for(int i=0;i<n;i++){
                if(compare_strings(keys[i],abc)){
                    if(ifExsist(&trie,keys[i])==false){
                        f1=1;
                        break;
                    }
                }
            }
            if(f1){
                cout<<"0";
            }
            else{
                cout<<"1";
            }
        }
        else
            cout<<"0";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends