//1. Count the nodes at distance K from leaf
/*Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, then it would add only 1 to our count.*/

//Node Structure
/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void solve(Node* root,int k,set<Node*> &s,vector<Node*> v) {
        if(!root) return;
        v.push_back(root);
        if(root->left==NULL && root->right==NULL) {
            int n=v.size()-1;
            if(k<=n) s.insert(v[n-k]);
        }
        solve(root->left,k,s,v);
        solve(root->right,k,s,v);
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
        set<Node*> s;
        vector<Node*> v;
        solve(root,k,s,v);
        return s.size(); 
    }
};


// 2. Level order traversal
//Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        queue<Node *> q;
        if(root==NULL) return ans;
        q.push(root);
        while(q.empty()==false){
         Node *a = q.front();
         q.pop();
         ans.push_back(a->data);
         if(a->left!=NULL){
            q.push(a->left);
         } 
         if(a->right!=NULL){
            q.push(a->right);
        }
        }
        return ans;
      //Your code here
    }
};



//3.Level Order Line by Line
//Given a Binary Tree, your task is to find its level order traversal.
//Note: The driver code prints the levels '$' separated.
vector<vector<int>> levelOrder(Node* node)
{
    vector<vector<int>> ans;
    if(node==NULL) return ans;
    queue<Node *> q;
    q.push(node);
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i=0;i<size;i++){
        Node *curr = q.front();
        q.pop();
        temp.push_back(curr->data);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
        }
        ans.push_back(temp);
    }
    return ans;
  //Your code here
}


//4. ZigZag Tree Traversal

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    vector<int> ans;
    if(root==NULL) return ans;
    queue<Node *>q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> v;
        for(int i=0;i<size;i++){
            Node *curr=q.front();
            q.pop();
            v.push_back(curr->data);
            if(curr->right){
                q.push(curr->right);
            }
            if(curr->left){
                q.push(curr->left);
            }
            
        }
        if(flag){
        reverse(begin(v),end(v));
        for(auto x:v){
            ans.push_back(x);
        }
        }
        else{
        for(auto x:v){
            ans.push_back(x);
        }
        }
        flag=!flag;
        
    }
    return ans;
    	// Code here
    }
};



//5. Children Sum in a Binary Tree

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     if(root==NULL) return  1;
     if(root->left==NULL && root->right==NULL){
         return 1;
     }
     int sum=0;
     if(root->left!=NULL){
         sum+=root->left->data;
     }
     if(root->right!=NULL){
         sum+=root->right->data;
     }
     return (sum==root->data && isSumProperty(root->left) && isSumProperty(root->right));        
    }
};


//6. Check if subtree
/*Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.*/

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool areEqual(Node *T,Node *S){
    
       if(T==NULL && S==NULL) return true;
       if(T==NULL || S==NULL) return false;
       return (T->data==S->data && areEqual(T->left,S->left) && areEqual(T->right,S->right));   
    }
    bool isSubTree(Node* T, Node* S) 
    {
        if(T==NULL) return false;
        if(areEqual(T,S)){
            return true;
        }
        return isSubTree(T->left,S) || isSubTree(T->right,S);
    }
};


//7. Foldable Binary Tree
bool isMirror(Node *left,Node *right){
    if(!left && !right) return true;
    if(left && !right) return false;
    if(!left && right) return false;
    return isMirror(left->left,right->right) && isMirror(left->right,right->left);
}
bool IsFoldable(Node* root)
{
  if(!root) return true;
  return isMirror(root->left,root->right);
}


//8. Vertical Width of a Binary Tree
//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
   
    vector<int> ans;
    vector<int> topView(Node *root)
    {
        queue<pair<int,Node*>> q;
        q.push(make_pair(0 ,root));
        
        map<int,int> mp;
        
        while(!q.empty()){
            
            pair<int , Node*> temp = q.front();
            q.pop();
            int x = temp.first;
            Node* node = temp.second;
            
            if(mp.find(x) == mp.end()){
                mp[x] = node -> data;
            }
            
            if(node -> left)    
                q.push(make_pair(x - 1 , node -> left));
            if(node -> right)   
                q.push(make_pair(x + 1 , node -> right));
        }
        for( auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
     int verticalWidth(Node* root) {
        if(root==NULL) return 0;
        vector<int> arr = topView(root);
        return arr.size();
    }
};


//9. Binary Tree to DLL
/*Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.*/

class Solution
{
    Node *prev=NULL;
    public:
    
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
      if(root==NULL) return root;
      Node *head = bToDLL(root->left);
      if(prev==NULL) {
        head=root;
      }
      else{
          root->left=prev;
          prev->right=root;
      }
      prev=root;
      bToDLL(root->right);
      return head;
        // your code here
    }
};


//10. Linked List to Binary Tree

class Solution {
  public:
    TreeNode *converter(vector<int> &arr,int i){
        if(i>=arr.size()) 
        return NULL;
        
        TreeNode *nod = new TreeNode(arr[i]);
        nod->left = converter(arr,2*i+1);
        nod->right = converter(arr,2*i+2);
        return nod;
        
    }
    void convert(Node *head, TreeNode *&root) {
        vector<int> ans;
        Node *curr=head;
        while(curr!=NULL){
            ans.push_back(curr->data);
            curr=curr->next;
        }
        root=converter(ans,0);
    }
};


//11. Construct Binary Tree from Parent Array
/*Given an array parent that is used to represent a tree. The array indices (0-based indexing) are the values of the tree nodes and parent[i] denotes the parent node of a particular node. The parent of the root node would always be -1, as there is no parent for the root. Construct the standard linked representation of Binary Tree from this array representation and return the root node of the constructed tree.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.*/

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
    Node *root=NULL;
    int n = parent.size();
    vector<Node*> v(n,NULL);
    //nodes create krte hn aur root find krlete hn 
    for(int i=0;i<n;i++){
        v[i]=new Node(i);
        if(parent[i]==-1) root=v[i];
    }
    //if left doesn't exist toh woh bana hi nhi hoga else left ban gya hn toh right banana hoga
    for(int i=0;i<n;i++){
        if(/*v[i]->data!=-1 &&*/parent[i]!=-1 ){
            if(v[parent[i]]->left==NULL){
                v[parent[i]]->left=v[i];
              }
            else{
                v[parent[i]]->right=v[i];
            }
    }
    }
    return root;
    }
};


//12. Connect Nodes of Levels
/*Given a binary tree, connect the nodes that are at the same level. You'll be given an addition nextRight pointer for the same.

Initially, all the next night pointers point to garbage values. Your function should set these pointers to the point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL*/

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       if(root==NULL) return;
       queue<Node *> q;
       q.push(root);
       root->nextRight=NULL;
       while(!q.empty()){
           vector<Node *> v;
           int size = q.size();
           
           for(int i=0;i<size;i++){
                 Node *curr = q.front();
                 q.pop();
                 if(curr->left) q.push(curr->left);
                 if(curr->right) q.push(curr->right);
                 v.push_back(curr);
           }
           int n = v.size();
           for(int i=0;i<n-1;i++){
               v[i]->nextRight=v[i+1];
           }
           v[n-1]->nextRight=NULL;
       }
    }    
      
};



//13.Diameter of a Binary Tree
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int ans=0;
        height(root,ans);
        return ans;
    }
    int height(Node *root,int &maxi){
        if(root==NULL) return 0;
        int lh = height(root->left,maxi);
        int rh = height(root->right,maxi);
        maxi = max(maxi,lh + rh + 1);
        return 1+max(lh,rh);
    }
};



//14. Maximum path sum from any node
class Solution {
  public:
 
  int findMaxi(Node* root,int &maxi){
       if(root==NULL){
            return 0;
        }
        int lmax = max(0,findMaxi(root->left,maxi));
        int rmax = max(0,findMaxi(root->right,maxi));
        maxi = max(maxi,root->data+lmax+rmax);
        return root->data+max(lmax,rmax);
  }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
       int maxi=INT_MIN;
       findMaxi(root,maxi);
       return maxi;
    }
};



//15. LCA in Binary Tree
/*Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.*/


class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL || root->data==n1 || root->data==n2) return root;
        Node* l=lca(root->left,n1,n2);
        Node *r=lca(root->right,n1,n2);
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;
       //Your code here 
    }
};


// 16. Maximum difference between node and its ancestor
//Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B. 


int diff;
int help(Node *root){
    if(!root) return INT_MAX;
    int l = help(root->left);
    int r = help(root->right);
    int mini = min(l,r);
    diff = max(diff,root->data-mini);
    return min(root->data,mini);
}
int maxDiff(Node* root)
{
   if(!root) return 0;
   diff = INT_MIN;
   help(root);
   return diff;
}


//17. Count Number of SubTrees having given Sum
int solve(Node* root, int X, int &count){
    if(!root) return 0;
    
    int left = solve(root->left,X,count);
    int right = solve(root->right,X,count);
    
    int sum = root->data+left+right;
    if(sum==X) count++;
    
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	int count = 0;
    solve(root,X,count);
    return count;
}

//18. Serialize and deserialize a binary tree
class Solution
{
    public:
    int index=0;
    //Function to serialize a tree and return a list containing nodes of tree.
    void serial(Node *root,vector<int> &ans){
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        serial(root->left,ans);
        serial(root->right,ans);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        serial(root,ans);
        return ans;
        //Your code here
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
        if(index==A.size()) return NULL;
        int val = A[index];
        index++;
        if(val==-1) return NULL;
        Node *root=new Node(val);
        root->left=deSerialize(A);
        root->right=deSerialize(A);
        return root;
       //Your code here
    }

};


//19. Maximum sum of Non-adjacent nodes
/*Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.*/

class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
   int findSum(Node* root, map<Node* , int>&dp){
        if(root==NULL){
            return 0;
        }
        
        if(dp[root]){
            return dp[root];
        }
        
        //include
        int include = root->data;
        if(root->left){
            if(root->left->left){
                include += findSum(root->left->left, dp);
            }
            if(root->left->right){
                include += findSum(root->left->right, dp);
            }
        }
        if(root->right){
            if(root->right->left){
                include += findSum(root->right->left, dp);
            }
            if(root->right->right){
                include += findSum(root->right->right, dp);
            }
        }
        
        //exclude
        int exclude = 0;
        if(root->left){
            exclude += findSum(root->left, dp);
        }
        if(root->right){
            exclude += findSum(root->right, dp);
        }
        
        return dp[root] = max(include, exclude);
    }
    int getMaxSum(Node *root) 
    {
        map<Node*, int>dp;
        int ans = findSum(root, dp);
        return ans;
        // Add your code here
    }
};



//20. Binary Tree to CDLL
class Solution
{
  public:
  Node *help(vector<Node *> &arr){
      int n = arr.size();
      for(int i=0;i<n-1;i++){
          arr[i]->right=arr[i+1];
      }
      arr[n-1]->right=arr[0];
      for(int i=1;i<n;i++){
          arr[i]->left=arr[i-1];
      }
      arr[0]->left=arr[n-1];
      return arr[0];
  }
  void inorder(vector<Node *> &arr,Node *root){
      if(!root) return;
      inorder(arr,root->left);
      arr.push_back(root);
      inorder(arr,root->right);
  }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        vector<Node *> arr;
        inorder(arr,root);
        Node *head = help(arr);
        return head;
    //add code here.
    }
};




