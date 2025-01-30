//1. Implement stack using array
//Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1) return -1;
    int y = arr[top];
    top--;
    return y;
    // Your Code       
}



//2. Stack using Linked List
//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    StackNode *temp = new StackNode(x);
    temp->next=top;
    top=temp;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top==NULL) return -1;
    StackNode *temp = top->next;
    top->next=NULL;
    int y = top->data;
    top=temp;
    return y;
    // Your Code
}


//3. Operations on Stack
/*Given a stack of integers and Q queries. The task is to perform the operation on stack according to the query.

The queries can be of 4 types:

i x: (adds element x in the stack).
r: (removes the topmost element from the stack).
h: Prints the topmost element.
f y: (check if the element y is present or not in the stack). Print "Yes" if present, else "No". */

//Function to push an element into the stack.
void insert(stack<int> &s,int x)
{
    s.push(x);
    //Your code here
}

//Function to remove top element from stack.
void remove(stack<int> &s)
{
    s.pop();
    //Your code here
}

//Function to print the top element of stack.
void headOf_Stack(stack<int> &s)
{
    int x=s.top();//Your code here
    cout<<x<<" "<<endl; 
}

//Function to search an element in the stack.
bool find(stack<int> s, int val)
{
    bool exists=false;
    while(!s.empty()){
        if(s.top()==val) {
        exists=true;}
        s.pop();
    }
    //Your code here
    
    if(exists==true){
        return true;
    }
    else{
        return false;
    }
}



//4. Delete Mid of a Stack
/*Given a stack s, delete the middle element of the stack without using any additional data structure.

Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from the bottom of the stack.

Note: The output shown by the compiler is the stack from top to bottom.*/

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        vector<int> v;
        int y = (sizeOfStack+1)/2;
        y = sizeOfStack-y+1;
        while(y--){
            v.push_back(s.top());
            s.pop();
        }
        int a=v.size();
        for(int i=a-2;i>=0;i--){
            s.push(v[i]);
        }
        // code here.. 
    }
};


//5. Parenthesis Checker
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
    stack<int> s;
        for(int i=0;i<x.size();i++){
            if(x[i]=='('||x[i]=='{'||x[i]=='['){
                s.push(x[i]);
            }
            else if(s.empty() && x[i]==']') return 0;
            else if(s.empty() && x[i]==')') return 0;
            else if(s.empty() && x[i]=='}') return 0;
            else if(x[i]==']' && s.top()=='[') s.pop();
            else if(x[i]=='}' && s.top()=='{') s.pop();
            else if(x[i]==')' && s.top()=='(') s.pop();
            else if(x[i]==']' && s.top()!='[') return 0;
            else if(x[i]=='}' && s.top()!='{') return 0;
            else if(x[i]==')' && s.top()!='(') return 0;
        }
        return s.empty();
    }

};


//6. Removing consecutive duplicates
//You are given string s. You need to remove the consecutive duplicates from the given string using a Stack. 

class Solution
{
    public:
    //Function to remove consecutive duplicates from given string using Stack.
    string removeConsecutiveDuplicates(string s)
    {
        string ans = "";
        ans+=s[0];
        stack<char> a;
        a.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]!=a.top()){
                ans += s[i];
                a.push(s[i]);
            }
        }
        return ans;
        // Your code here
    }
};


//7. Removing consecutive duplicates - 2
/*You are given string s. You need to remove the pair of duplicates.
Note: The pair should be of adjacent elements and after removing a pair the remaining string is joined together.*/

class Solution
{
    public:
    //Function to remove pair of duplicates from given string using Stack.
    string removePair(string str)
    {
       /* string s = "";
        int i=0;
        
        while(i<n-1){
            if(str[i]==str[i+1]){
                i+=2;
            }
            else if(str[i]!=str[i+1]){
                s+=str[i];
                i++;
            }
            else if(i==n-2 && str[i]!=str[i+1]){
                s+=str[n-1];
                i++;
            }
        }
        if(str[n-2]!=str[n-1]){
            s+=str[n-1];
        }
        return s;*/
        int n=str.length();
        stack<char> s;
        string a="";
        s.push(str[0]);
        for(int i=1;i<n;i++){
            if( !s.empty() && s.top()==str[i]) s.pop();
            else{
                s.push(str[i]);
            }
        }
        while(!s.empty()){
          a+=s.top();
          s.pop();
        }
        reverse(a.begin(),a.end());
        return a;
        // Your code here
    }
};



//8. Two Stacks in an Array
/*Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
push1 : pushes element into the first stack.
push2 : pushes element into the second stack.
pop1 : pops an element from the first stack and returns the popped element. If the first stack is empty, it should return -1.
pop2 : pops an element from the second stack and returns the popped element. If the second stack is empty, it should return -1.*/



class twoStacks
{
    public:
    int *arr;
    int cap,top1,top2;
    twoStacks()
    {
        cap=100;
        top1=-1;
        top2=100;
        arr = new int [100];
        
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
     if(top1<top2-1){
        top1++;
        arr[top1]=x;
     }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top1<top2-1){
            top2--;
            arr[top2]=x;
        }
       
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
     if(top1>=0){
         int x=arr[top1];
         top1--;
         return x;
     }   
     return -1;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2<cap){int x=arr[top2];
       top2++;
       return x;}
       return -1;
    }
};


//9. Stock span problem
/*The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.*/

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        stack<int> s;
        s.push(0);
        ans.push_back(1);
        for(int i=1;i<n;i++){
            while(s.empty()==false && price[s.top()]<=price[i]){
                s.pop();
            }
            int span = s.empty() ? i+1 : i-s.top();
            ans.push_back(span);
            s.push(i);
        }
        return ans;
       // Your code here
    }
};



//10. Next Greater Element
/*Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.*/

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        stack<long long> s;
        s.push(arr[n-1]);
        ans.push_back(-1);
        for(int i=n-2;i>=0;i--){
            while(s.empty()==false && s.top()<=arr[i]){
                s.pop();
            }
            long long nextLar = s.empty() ? -1 : s.top();
            ans.push_back(nextLar);
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



//11. Get min at pop
//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n)
{
    stack<int> st;
    st.push(arr[0]);
    int mini = arr[0]; 
  for(int i=1;i<n;i++){
      if(arr[i]<=st.top()){
      st.push(arr[i]);
      mini = arr[i];
      }
      else{
      st.push(mini);
      }
  }  
  return st;
   // your code here
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s)
{
    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
        
    
    // your code here
}


//12. Histogram Max Rectangular Area
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<int> s;
        long long res=0;
        for(int i=0;i<n;i++){
            long long curr=0;
            while(s.empty()==false && arr[s.top()]>=arr[i]){
                int x = s.top();
                s.pop();
                curr = arr[x]*(s.empty() ? i : (i-s.top()-1));
                res=max(res,curr);
            }
            s.push(i);
        }
        while(s.empty()==false){
            int x = s.top();
            s.pop();
            long long int curr = arr[x]*(s.empty()?n:(n-s.top()-1));
            res=max(res,curr); // note i denotes the next smaller ele and s.top denotes the prev small element
        }
        return res;
        // Your code here
    }
};



//13. The Celebrity Problem
/*A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int> in(n,0),out(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]){
                    in[j]++;
                    out[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(in[i] == n-1 and out[i] == 0) return i;
        }
        return -1;
    }
};



//14. Infix to Postfix
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ans="";
        stack<char> st;
        map<char,int> precedence;
        precedence['+']=2;
        precedence['-']=2;
        precedence['*']=3;
        precedence['/']=3;
        precedence['(']=1;
        precedence['^']=4;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalpha(s[i])||s[i]>='0' && s[i]<='9'){
                ans+=s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.empty()==false && st.top()!='('){
                 ans+=st.top();//we dont want () in our answer
                 st.pop();
                }
                if(st.empty()==false){
                 st.pop();
                }
            }
            else{
                while(st.empty()==false && precedence[s[i]]<=precedence[st.top()]){
                ans+=st.top();    //idhar hamko right associativity of ^ ko iugnore krne kaha hn
                st.pop();
                }
                st.push(s[i]);
            }}//end of for loop
          
          while(st.empty()==false){
                ans+=st.top();
                st.pop();
            }
        return ans;
    }
};


//15. Evaluation of Postfix Expression
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> s;
        for(int i=0;i<S.size();i++){
            if(S[i]=='*'){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                int x=op2*op1;
                s.push(x);
            }
            else if(S[i]=='/'){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                int y=op2/op1;
                s.push(y);
            }
            else if(S[i]=='+'){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                int z=op1+op2;
                s.push(z);
            }
            else if(S[i]=='-'){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                int w=op2-op1;
                s.push(w);
            }
            else{
                s.push(S[i]-'0');//bhai plz string characters ko integer toh bana le
            }
        }
        return s.top();
        // Your code here
    }
};



//16. Maximum of minimum for every window size
/*Given an array of integers arr[] of size N, the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to N.

More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=N.*/

class Solution {
  public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(vector<int>& arr) {
        // Your code here
  /*  int n = arr.size();
    vector<int> res(n, 0);

    // Consider all windows of different 
    // sizes starting from size 1
    for (int k = 1; k <= n; k++) {
      
        // Initialize max of min for current window size k
        int maxOfMin = INT_MIN;

        // Traverse through all windows of current size k
        for (int i = 0; i <= n - k; i++) {
          
            // Find minimum of current window
            int minVal = arr[i];
            for (int j = 1; j < k; j++) {
                if (arr[i + j] < minVal)
                    minVal = arr[i + j];
            }

            // Update maxOfMin if required
            if (minVal > maxOfMin)
                maxOfMin = minVal;
        }

        // Store max of min for current window size
        res[k - 1] = maxOfMin;
    }

    return res;*/
     int n = arr.size();
    vector<int> res(n, 0); 
    stack<int> s;

    // Array to store the length of the window 
    // where each element is the minimum
    vector<int> len(n, 0);

    // Traverse through array to determine 
    // window sizes using a stack
    for (int i = 0; i < n; i++) {
      
        // Process elements to find next smaller 
        // element on the left
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? i : i - s.top() - 1;
            len[top] = windowSize;
        }
        s.push(i);
    }

    // Process remaining elements in the stack
    // for right boundaries
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int windowSize = s.empty() ? n : n - s.top() - 1;
        len[top] = windowSize;
    }

    // Fill res[] based on len[] and arr[]
    for (int i = 0; i < n; i++) {
        int windowSize = len[i] - 1;  // 0-based indexing
        res[windowSize] = max(res[windowSize], arr[i]);
    }

    // Fill remaining entries in res[] to ensure 
    // all are max of min
    for (int i = n - 2; i >= 0; i--)
        res[i] = max(res[i], res[i + 1]);

    return res;
    }
};



