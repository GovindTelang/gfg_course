//1. Find length of Loop
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(struct Node *head) {
        // Code here
        Node *slow=head;
        Node *fast=head;
        if(slow->next==NULL) return 0;
        int count=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
       if(slow!=fast) return 0;
       slow=slow->next;
       count++;
       while(slow!=fast){
           slow=slow->next;
           count++;
       }
       return count;
    }
};

//2. Doubly linked list Insertion at given position
/*Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.*/

void addNode(Node *head, int pos, int data)
{ 
Node *curr=head;
Node *temp = new Node(data);

for(int i=0;i<pos;i++){
    curr=curr->next;
}
temp->next=curr->next;
if(curr->next!=NULL){
curr->next->prev=temp;}
curr->next=temp;
temp->prev=curr;
//curr->next->prev=temp;

/*curr->prev->next=temp;
temp->prev=curr->prev;
curr->prev=temp;
if(curr->next!=NULL){
temp->next=curr;
}+*/
   // Your code here
}


//3. Add Number Linked Lists
/*Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.*/

class Solution {
  public:
     Node* reverseList(Node* head)
    {
        if(head == NULL)
            return NULL;
            
        Node* prev = NULL;
        Node* forward = NULL;
        Node* curr = head;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            
            curr -> next = prev;
            
            prev = curr;
            
            curr = forward;
        }
        
        return prev;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        Node* head1 = reverseList(num1);
        Node* head2 = reverseList(num2);
        
        int carry = 0;
        
        Node* dummy = new Node(-1);
        Node* head = dummy;
        
        while(head1 && head2)
        {
            int val1 = head1 -> data;
            int val2 = head2 -> data;
            
            int sum = val1 + val2 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        while(head1)
        {
            int val1 = head1 -> data;
            
            int sum = val1 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head1 = head1 -> next;
        }
        
        while(head2)
        {
            int val2 = head2 -> data;
            
            int sum = val2 + carry;
            
            carry = sum / 10;
            
            int num = sum % 10;
            
            Node* temp = new Node(num);
            
            dummy -> next = temp;
            
            dummy = temp;
            
            head2 = head2 -> next;
        }
        
        if(carry != 0)
        {
            Node* temp = new Node(carry);
            
            dummy -> next = temp;
            
            dummy = temp;
        }
        
        head = head -> next;
        
        Node* newHead = reverseList(head);
        
        while(newHead -> data == 0)
        {
            newHead = newHead -> next;
        }
        
        return newHead;
    }
};


//4. Swap Kth nodes from ends
/*A singly linked list and an integer of k are given. You need to swap the kth node from the beginning and the kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.
Note: The driver code will output "true" if you successfully swap the nodes.*/

// Function to swap Kth node from beginning and end in a linked list.
class Solution {
  public:
    int help(Node *head){
        if(!head) return 0;
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    Node* swapKthNode(Node* head, int k) {
        // code here
    int n = help(head);
    if(k>n || k == n-k+1) return head;
    Node * beg = head, * beg_prev = NULL;
    Node * end = head, * end_prev = NULL;
    for(int i=1;i<k;i++){
        beg_prev=beg;
        beg=beg->next;
    }
    for(int i=1;i<n-k+1;i++){
        end_prev=end;
        end=end->next;
    }
    if(beg_prev){
        beg_prev->next=end;
    }
    if(end_prev){
        end_prev->next=beg;
    }
    Node *temp = beg->next;
    beg->next=end->next;
    end->next=temp;
    if(k==1) return end;
    if(k==n) return beg;
    return head;
    }
};


//5. Delete without head pointer
/*You are given a node del_node of a Singly Linked List where you have to delete a value of the given node from the linked list but you are not given the head of the list.

By deleting the node value, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before & after the del_node node should be in the same order.
Note:

Multiple nodes can have the same values as the del_node, but you must only remove the node whose pointer del_node is given to you.
It is guaranteed that there exists a node with a value equal to the del_node value and it will not be the last node of the linked list.*/

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
     
     del_node->data = del_node->next->data;
     del_node->next = del_node->next->next;
      
    }
};


//6. Remove Duplicates from a Sorted Linked List
/*Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.*/

Node *removeDuplicates(Node *head)
{
  Node *curr=head;
  while(curr!=NULL && curr->next!=NULL){
      if(curr->data==curr->next->data){
        Node *temp = curr->next;
        curr->next=curr->next->next;
        delete temp;
      }
      else{
          curr=curr->next;
      }
  }
  return head;
}


//7. Identical Linked Lists
/*Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false.*/

bool areIdentical(struct Node *head1, struct Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->data != curr2->data) return 0;
        curr1=curr1->next;
        curr2=curr2->next;
    }
    if(curr1==NULL && curr2!=NULL) return 0;
    if(curr2==NULL && curr1!=NULL) return 0;
    return 1;
    // Code here
}


//8. Kth from End of Linked List
/*Given the head of a linked list and the number k, Your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.*/
class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        
        Node *curr=head;
        int x=1;
        while(curr->next!=NULL){
            curr=curr->next;
            x++;
        }
        if(x<k) return -1;
        Node *temp=head;
        int y=x-k;
        while(y){
         temp=temp->next;   
         y--;
        }
        return temp->data;
    }
};


//9. Remove loop in Linked List
/*Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.
The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast) return;
        slow=head;
        if(slow==head && fast==head){
            while(fast->next!=head){
                fast=fast->next;
            }
        }
        
        else{
        while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }}
        fast->next=NULL;
    }
};


//10. Intersection in Y Shaped Lists

Given the head of two singly linked lists, return the point where these two linked lists intersect.
Note: It is guaranteed that the intersected node always exists.
Custom Input Format:
head1 contains the nodes before intersection in list1
head2 contains the nodes before intersection in list2
CommonList contains the nodes after intersection of list1 and list2.


class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        
    Node *curr1=head1;
    int c1=0;
    Node *curr2=head2;
    int c2=0;
    while(curr1!=NULL){
        curr1=curr1->next;
        c1++;
    }
    while(curr2!=NULL){
        curr2=curr2->next;
        c2++;
    }
    curr1=head1;
    curr2=head2;
    int y=abs(c2-c1);
    if(c2>c1){
        while(y--){
        curr2=curr2->next;
        }
    }
    else{
        while(y--){
        curr1=curr1->next;
        }
    }
    while(curr1!=NULL && curr2!=NULL){
        if(curr1==curr2) return (curr1->data);
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return -1;
    }
};



//11. Pairwise swap of nodes in LinkedList
//Given a linked list of N positive integers. You need to swap elements pairwise. Your task is to complete the function pairwise_swap().
struct Node* pairwise_swap(struct Node* head)
{
    Node *curr=head;
    while(curr!=NULL && curr->next!=NULL){
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
    return head;
    // your code here
}



//12. Clone List with Next and Random
/*You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

NOTE : Original linked list should remain unchanged.*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        unordered_map<Node *,Node *> mp;
        for(Node* curr = head;curr!=NULL;curr=curr->next){
            mp[curr]=new Node(curr->data);
        }
        for(Node* curr = head;curr!=NULL;curr=curr->next){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];
        }
        return mp[head];
    }
};



//13. LRU Cache
/*Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

PUT x y: sets the value of the key x with value y
GET x: gets the key of x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be initialized.*/

class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    class node{
    public: 
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v) {
            key = k;
            val = v;
        }
    };
    int capacity;
    unordered_map<int,node*>mp;
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    LRUCache(int cap)
    {
       capacity = cap;
       head->next = tail;
       tail->prev = head;
        // code here
    }
     void addNode(node* newNode) {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    { if(mp.find(key) == mp.end()) return -1;
        
        node* res = mp[key];
        deleteNode(res);
        addNode(res);
        
        return res->val;
        // your code here
    }
    
    //Function for storing key-value pair.
    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()) {
            node* exist = mp[key];
            mp.erase(key);
            deleteNode(exist);
        } 
        if(mp.size()==capacity) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        mp[key] = head->next;
        // your code here   
    }
};



//14. Merge two sorted linked lists
// Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    Node *head=NULL;
    Node *tail=NULL;
    if(head1->data<=head2->data){
    head=head1;
    tail=head1;
    head1=head1->next;
    }
    else{
    head=head2;
    tail=head2;
    head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
    if(head1->data<=head2->data){
        tail->next=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        tail->next=head2;
        tail=head2;
        head2=head2->next;
    }
    }
    if(head1==NULL) tail->next=head2;
    else{
    tail->next=head1;
    }
    return head;
    }
};



//15. Merge K sorted linked lists
/*Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list*/

class Solution {
  public:
  class compare{
  public:
   bool operator()(Node *a,Node *b){
      return a->data>b->data; //keval heap ke case main ulta hota hn
      }
  };
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr){
        // Your code here
        int k=arr.size();
        priority_queue<Node*,vector<Node*>,compare> p(arr.begin(),arr.end());
        Node *root=new Node(0);
        Node *tail = root;
        Node *temp;
        while(!p.empty()){
            temp=p.top();
            p.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next) p.push(temp->next);
        }
        return root->next;}
    };



//16. Palindrome Linked List
class Solution{
  public:
    Node* revList(struct Node* head) {
        // code here
        // return head of reversed list
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {if(head==NULL) return true;
    Node *slow=head,*fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node *rev=revList(slow->next);
    Node *curr=head;
    while(rev!=NULL){
        if(rev->data!=curr->data) return false;
        rev=rev->next;
        curr=curr->next;
    }
    return true;
        //Your code here
    }
};



//17. Delete in a Doubly Linked List
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
      if(x==1){
          Node *temp=head->next;
          delete head;
          return temp;
      }
      Node *curr=head;
      int count=1;
      while(count!=x){
          curr=curr->next;
          count++;
      }
      if(curr->next!=NULL){
          curr->prev->next=curr->next;
          curr->next->prev=curr->prev;
      }
      else{
          curr->prev->next=NULL;
      }
      
      delete curr;
      return head;
      
    }
};



//18. Insert in Sorted way in a Sorted DLL
/*Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).
Note: The DLL is sorted in ascending order*/
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
       Node* curr=head;
      bool last=false;
      while(curr){
          if(curr->data>=x){
              struct Node* temp=getNode(x);
              temp->next=curr;
              curr->prev=temp;
              return temp;
          }
          else if(curr->data < x and curr->next and curr->next->data >= x){
              break;
          }
          else if(!curr->next){
              last=true;
              break;
          }
          else{
              curr=curr->next;
          }
      }
      struct Node* temp=getNode(x);
      temp->next=curr->next;
      temp->prev=curr;
      if(!last)
          curr->next->prev=temp;
      curr->next=temp;
      return head;
  }
};


//19. Reverse a linked list

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node* curr=head;
        Node* prev=NULL;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};


//20. Find Middle of Circular Doubly Linked List
class Solution{
    public:
    int findMiddle(Node * head)
    {
        if(head==NULL) return 0;
        if(head->next==head) return head->data;
        if(head->next->next==head) return head->next->data;
        int count=1;
        Node *curr;
        for(curr=head;curr->next!=head;curr=curr->next){
            count++;
        }
        curr=head;
        for(int i=0;i<count/2;i++){
            curr=curr->next;
        }
        return curr->data;
       //Your code here
    }
};


//21. Is The Doubly Linked List Circular
class Solution{
    public:
    bool isCircular(Node * head)
    {
       /*Node *curr=head;
       if(head->next==NULL) return 0;
       do{
           curr=curr->next;
       }while(curr->next!=NULL && curr->next!=head);
       if(curr->next)*/
    if(head->prev==NULL)
    return false;
    
    Node *temp=head->prev;
    if(temp->next==NULL)
    return false;
    
    
    if(temp->next==head &&head->prev==temp)
    return true;
    
    return false;
    }
};
