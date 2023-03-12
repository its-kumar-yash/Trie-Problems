//Given an array of non-negative integers of size N. Find the maximum possible XOR between two numbers present in the array.

//Flipkart

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class TrieNode{
public:
    TrieNode* children[2]; // two children are possible 0 & 1;
    bool isEnd;
    
    TrieNode(){
        for(int i = 0; i < 2; i++){
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
    
    //to insert a number(bit representation) into trie
    void insert(int num){
        TrieNode* curr = root;
        
        for(int i = 31; i>= 0; i--){
            //check if the ith index(bit) of number is set or not
            int bit = (num >> i) & 1;
            
            //if children does not contains this bit
            //create a new children
            if(curr->children[bit] == NULL){
                curr->children[bit] = new TrieNode();
            }
            
            curr = curr->children[bit];
        }
        
        curr->isEnd = true;
    }
    
    
    //to get the maximum xor for given integer x
    int getMax(int x){
        TrieNode* curr = root;
        int maxNum = 0;
        
        for(int i = 31; i >= 0; i--){
            
            //finding ith bit in given number
            int bit = (x >> i) & 1;
            
            // now check if opposite of bit is contained by children or not
            if(curr->children[1 - bit] != NULL){
                //do or operation in maxNum
                maxNum = maxNum | (1 << i);
                curr = curr->children[1 - bit];
            }
            else{
                curr = curr->children[bit];
            }
        }
        
        
        return maxNum;
    }
};


class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {   
        Trie* root = new Trie();
        
        //step 1 - insert all element into trie
        for(int i = 0; i < n; i++){
            root->insert(arr[i]);
        }
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            int ans = root->getMax(arr[i]);
            maxi = max(maxi, ans);
            
        }
        
        return maxi;
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

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends