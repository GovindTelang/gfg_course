//1.Queue Using Array
//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    arr[rear]=x;
    rear = rear+1;
        // Your Code
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear) return -1;
    int ans = arr[front];
    front = (front+1);
    return ans;
        // Your Code       
}

//2. Operations on Queue

class Solution{
    public:
    
    //Function to push an element in queue.
    void enqueue(queue<int> &q,int x)
    {
        q.push(x);
       //Your code here
    }
     
    //Function to remove front element from queue.
    void dequeue(queue<int> &q)
    {
        q.pop();
        //Your code here
    }
    
    //Function to find the front element of queue.
    int front(queue<int> &q)
    {
        int x = q.front();
        return x;
        //Your code here
    }
    
    //Function to find an element in the queue.
    string find(queue<int> q, int x)
    {
        while(q.empty()==false){
            if(q.front()==x) return "Yes";
            q.pop();
        }
        return "No";
        //Your code here
    }
};


//3. Queue using Linked List
void MyQueue:: push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if(front==NULL){
        front=temp;
        rear=temp;
        return;
    }
    rear->next=temp;
    rear=rear->next;
    // Your Code
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL) return -1;
    QueueNode *temp = front;
    front = front->next;
    int a = temp->data;
    if(front==NULL){
        rear=NULL;
    }
    delete(temp);
    return a;
    // Your Code       
}



//4. Stack using two queues
//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q1.push(x);
        // Your Code
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if(q1.size()==0) return -1;
    while(q1.size()>1){
        int a = q1.front();
        q2.push(a);
        q1.pop();
    }
    int b = q1.front();
    q1.pop();
    while(q2.size()>0){
        int a = q2.front();
        q1.push(a);
        q2.pop();
    }
    return b;
        // Your Code       
}


//5.Queue using two Stacks
//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    s1.push(x);
    // Your Code
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
   if(s1.size()==0) return -1;
   while(s1.empty()==false){
       int a = s1.top();
       s1.pop();
       s2.push(a);
   } 
   int b = s2.top();
   s2.pop();
   while(s2.empty()==false){
       int a = s2.top();
       s2.pop();
       s1.push(a);
   }
   return b;
}


//6. Queue Reversal
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;
        while(q.empty()==false){
            s.push(q.front());
            q.pop();
        }
        while(s.empty()==false){
            q.push(s.top());
            s.pop();
        }
        return q;
        // add code here.
    }
};


//7. Reverse First K elements of Queue

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> s;
        queue<int> q1;
        while(q.size()!=0 && k--){
            int a = q.front();
            q.pop();
            s.push(a);
        }
        while(s.empty()==false){
            int a = s.top();
            s.pop();
            q1.push(a);
        }
        while(q.size()!=0){
            int a = q.front();
            q.pop();
            q1.push(a);
        }
        
        return q1;
    }
};



