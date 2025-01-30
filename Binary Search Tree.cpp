//1. Delete a node from BST

Node * getSuccesor(Node *root){
   
    Node *curr=root->right;
    while(curr && curr->left){
        curr=curr->left;
    }
    return curr;
}
 
Node *deleteNode(Node *root, int x) {
    // your code goes here
    if(!root) return root;
    if(root->data > x) root->left=deleteNode(root->left,x);
    else if(root->data < x) root->right=deleteNode(root->right,x);
    else{
        if(!root->left){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ = getSuccesor(root);
            root->data = succ->data;
            root->right = deleteNode(root->right,succ->data);
        }
        return root;
    }
    
}


//2. Floor in BST
int floor(Node* root, int key) {
    // Your code goes here
    int ans = -1;
    while(1){
    if(root==NULL) return ans;
    if(root->data == key) return key;
    else if(root->data < key){
        ans=root->data;
        root=root->right;
    }
    else root=root->left;}
    return ans;
}

//3. Ceil in BST
int findCeil(Node* root, int input) {
        // Your code goes here
    int ans = -1;
    while(1){
    if(root==NULL) return ans;
    if(root->data == input) return input;
    else if(root->data < input){
        root=root->right;
    }
    else{
     ans=root->data;
     root=root->left;
     
    }
    }
    return ans;

    // Your code here
}

//4. Smaller on Right
//Given an array arr[] of N elements. The task is to count maximum number of distinct smaller elements on right side of any array element. For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4.  Note that 20 has maximum 4 smaller elements on right side. Other elements have less count, for example 10 has 3 smaller elements on right side.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int maxDistinctSmallerOnRight(const vector<int>& arr) {
    int n = arr.size();
    int maxCount = 0;
    set<int> seen;

    // Iterate from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Insert the element into the set
        seen.insert(arr[i]);

        // Use the set to count distinct smaller elements
        auto it = seen.lower_bound(arr[i]);
        int count = distance(seen.begin(), it);
        
        // Update the maximum count
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int result = maxDistinctSmallerOnRight(arr);
        cout << result << endl;
    }

    return 0;
}


//5. Closest in BST
//Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        int res=INT_MAX;
        while(true){
            if(root==NULL) return res;
            if(root->data==K) return 0;
            else if(root->data > K){
                res=min(res,abs(root->data - K));
                root=root->left;
            }
            else{
                res=min(res,abs(root->data - K));
                root=root->right;
            }
        }
        
        //Your code here
    }
};


//6. Merge two BST 's

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void mapping(Node* root,map<int,int>&NodeCount){
        //base case
        if(root==NULL){
            return;
        }
        
        //left
        mapping(root->left,NodeCount);
        
        //increase count of node
        NodeCount[root->data]++;
        
        //right
        mapping(root->right,NodeCount);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>ans;
        map<int,int>NodeCount;
        
        //1st
        mapping(root1,NodeCount);
        
        //2nd
        mapping(root2,NodeCount);
        
        for(auto i: NodeCount){
            while(i.second--){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};



//7. Fixing Two nodes of a BST
//You are given the root of a binary search tree(BST), where exactly two nodes were swapped by mistake. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.

class Solution {
  public:
  void inorder(Node *root,vector<Node*> &ans){
      if(!root) return;
      inorder(root->left,ans);
      ans.push_back(root);
      inorder(root->right,ans);
  }
    
    void correctBST( struct Node* root )
    {
        Node *first=NULL;
        Node *second=NULL;
        vector<Node*> ans;
        inorder(root,ans);
        for(int i=1;i<ans.size();i++){
            if(ans[i]->data < ans[i-1]->data){
                if(first==NULL){
                    first=ans[i-1];
                }
                second=ans[i];
            }
        }
        swap(first->data,second->data);
        // add code here.
    }
};


//8. Find Common Nodes in two BSTs
/*Given two Binary Search Trees. Find the nodes that are common in both of them, ie- find the intersection of the two BSTs.

Note: Return the common nodes in sorted order.*/

class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> ans;
        stack<Node *> st1,st2;
        while(root1){
            st1.push(root1);
            root1=root1->left;
        }
        while(root2){
            st2.push(root2);
            root2=root2->left;
        }
        while(!st1.empty() && !st2.empty()){
            if(st1.top()->data == st2.top()->data){
                ans.push_back(st1.top()->data);
                root1=st1.top()->right;
                st1.pop();
                root2=st2.top()->right;
                st2.pop();
            }
            else if(st1.top()->data>st2.top()->data){
                root2=st2.top()->right;
                st2.pop();
            }
            else{
                root1=st1.top()->right;
                st1.pop();
            }
            while(root1){
                st1.push(root1);
                root1=root1->left;
            }
            while(root2){
                st2.push(root2);
                root2=root2->left;
            }
        }
            
        return ans;
     //Your code here
    }
};


//9. Pair Sum in BST
bool help(Node *root,int x,set<int> &s){
    if(root==NULL) return 0;
    if(help(root->left,x,s)==true) return 1;
    if(s.find(x-root->data)!=s.end()) return 1;
    else{
        s.insert(root->data);
    }
    return help(root->right,x,s);
}
bool findPair(Node* root, int X) 
{
    if(root==NULL) return 0;
    set<int> s;
    return help(root,X,s);
    // Your code here
}



//10. Vertical Tree Traversal
/*Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.*/

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
       
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *curr=q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level].push_back(curr->data);
            if(curr->left){
                q.push({curr->left,level-1});
            }
            if(curr->right){
                q.push({curr->right,level+1});
            }
        }
        vector<int> ans;
       for(auto it:mp){
           for(int it1 : it.second){
               ans.push_back(it1);
           }
       }
       return ans;
        //Your code here
    }
};



//11. Convert Level Order Traversal to BST
//Given an array BST[] of size N containing level order traversal of a Binary Search Tree. The task is to complete the function constructBst(), which constructs the BST (Binary Search Tree) from its given level order traversal.

Node* constructBst(int arr[], int n)
{
      if (n == 0) return NULL;
    
    queue<pair<Node *, pair<int, int>>> q;
    Node *root = new Node(arr[0]);
    q.push({root, {INT_MIN, INT_MAX}});
    
    for (int i = 1; i < n; i++) {
        while (!q.empty()) {
            Node *temp = q.front().first;
            pair<int, int> range = q.front().second;
            
            if (arr[i] > range.first && arr[i] < range.second) {
                if (arr[i] < temp->data) {
                    if (temp->left == NULL) {
                        temp->left = new Node(arr[i]);
                        q.push({temp->left, {range.first, temp->data}});
                        break; // move to the next element in arr
                    } else {
                        q.pop();
                    }
                } else {
                    if (temp->right == NULL) {
                        temp->right = new Node(arr[i]);
                        q.push({temp->right, {temp->data, range.second}});
                        q.pop(); // right child is added, so pop the current node
                        break; // move to the next element in arr
                    } else {
                        q.pop();
                    }
                }
            } else {
                q.pop(); // current element doesn't fit in the range, pop the current node
            }
        }
    }
    
    return root;

    // Code here
}


//12. Preorder to BST
/*Given an array arr[] of N nodes representing preorder traversal of some BST. You have to build the BST  from the given preorder traversal. 

In Pre-Order traversal, the root node is visited before the left child and right child nodes.*/

class Solution {
  public:
  Node *help(int pre[],int size,int &i,int bound){
      if(i==size || pre[i]>bound) return NULL;
      Node *temp=newNode(pre[i++]);
      temp->left = help(pre,size,i,temp->data);
      temp->right = help(pre,size,i,bound);
      return temp;
  }
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        int i=0;
        Node *root= help(pre,size,i,INT_MAX);
        return root;
    }
};



//13. Bottom View of Binary Tree

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> mp;
        while(!q.empty()){
            Node *curr=q.front().first;
            int x = q.front().second;
            q.pop();
            mp[x]=curr->data;
            if(curr->left){
                q.push({curr->left,x-1});
            }
            if(curr->right){
                q.push({curr->right,x+1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};


//14. LCA in BST
node* lca(node* root, int n1, int n2)
{
    while (root != NULL) {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;
 
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;
 
        else
            break;
    }
    return root;
}


//15. Count BST nodes that lie in a given range
/*Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side*/

class Solution{
public:
    void help(Node *root,int l,int h, int &count){
        if(root==NULL) return;
        help(root->left,l,h,count);
        if(root->data >= l && root->data <= h) count++;
        help(root->right,l,h,count);
    }
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        help(root,l,h,count);
        return count;
      // your code goes here   
    }
};


//16. Top View of Binary Tree

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(mp.find(line)==mp.end()){
                mp[line]=node->data;}
                
                if(node->left!=NULL) q.push({node->left,line-1});
                if(node->right!=NULL) q.push({node->right,line+1});
                
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        //Your code here
    }

};


