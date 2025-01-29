//1. Activity Selection
/*Given some activities with their start and end day given in array start[] and end[]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.*/

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    typedef pair<int,int> P;
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<P> ans;
        for(int i=0;i<n;i++){
            ans.push_back({end[i],start[i]});
        }
        sort(ans.begin(),ans.end());
        int res = 0;
        int end_time = -1;
        for(int i=0;i<n;i++){
            if(end_time<ans[i].second){
                end_time = ans[i].first;
                res++;
            }
        }
        return res;
        
        // Your code here
    }
};



//2. N meetings in one room
/*You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.*/

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    typedef pair<int,int> P;
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
      vector<P> v;//we want to have maximum meetings so we select those meetings whose ending time is less
      for(int i=0;i<n;i++){
          v.push_back({end[i],start[i]});//so we sort according to ending times
      }
      sort(v.begin(),v.end());
      int count = 0;
      int end_time=-1;
      for(int i=0;i<n;i++){
          if(end_time<v[i].second){
              count++;
              end_time=v[i].first;
          }
      }
      return count;
    }
};



//3. Fractional Knapsack
/*Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.*/

bool comp(Item a,Item b){
    return a.value * b.weight > b.value * a.weight;
}
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr,arr+n,comp);
        double profit = 0;
        int i=0;
        while(i<n && w>0){
            if(w>=arr[i].weight){
                w -= arr[i].weight;
                profit += arr[i].value;
            }
            else{
                double temp = arr[i].value;
                temp /= arr[i].weight;
                profit += w*temp;
                w = 0;
                break;
            }
            i++;
        }
        return profit;
    }
};



//4. Job Sequencing Problem
/*You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.*/

bool comp(Job a,Job b){
    return a.profit>b.profit;
}
int findPar(int num,vector<int> &parent){
    if(parent[num]==num) return num;
    return parent[num] = findPar(parent[num],parent);
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
    sort(arr,arr+n,comp);
    int deadline = 0;
    for(int i=0;i<n;i++){
        deadline=max(deadline,arr[i].dead);
    }
    vector<int> ans(2);
    vector<int> parent(deadline+1);
    for(int i=0;i<deadline+1;i++){
        parent[i]=i;
    }
    for(int i=0;i<n;i++){
        int slot = findPar(arr[i].dead,parent);
        if(slot>0){
            ans[0]++;
            ans[1]+=arr[i].profit;
            parent[slot]=slot-1;
        }
    }
    return ans;
    } 
};



//5. Largest number with given sum
/*Geek lost the password of his super locker. He remembers the number of digits N as well as the sum S of all the digits of his password. He know that his password is the largest number of N digits that can be made with given sum S. As he is busy doing his homework, help him retrieving his password.*/
class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum>9*n) return "-1";
        string ans = "";
        int x = 0;
        int nine = sum/9;
        int remain = sum%9;
        for(int i=0;i<nine;i++){
            ans += "9";
            x++;
        }
        if(remain){
        ans += to_string(remain);
        x++;
        }
        while(x!=n){
            ans += "0";
            x++;
        }
        return ans;
    }
};



//6. Huffman Decoding
/*You are given an encoded binary string and a Huffman MinHeap tree, your task is to complete the function decodeHuffmanData(), which decodes the binary encoded string and returns the original string. 
Note: Each node of the min heap contains 2 data members, a character, and an integer to denoting its frequency. The character '$' is the special character used for internal nodes whose min heap node only needs an integer field. The code in the chart is generated by the following rule:
- If we want to reach a node from the root then in the path, for right turn we use 1 and for left turn we use 0.*/
/*
Structure of the node of Huffman tree is as
struct MinHeapNode
{
    char data;
    int freq;
    MinHeapNode *left, *right;
};
*/

class Solution {
  public:
   /* class Node{
        public:
        int freq;
        char c;
        Node * left,*right;
        Node(int frequency,char name){
            freq = frequency;
            c = name;
            left = NULL;
            right = NULL;
        }
    };
    class comp{
        public:
        bool operator()(Node * a ,Node * b){
            return a->freq > b->freq;
        }
    };
    void preorder(Node * root,string &temp,vector<string> &ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        temp.push_back('0'); //for going to left
        preorder(root->left,temp,ans);
        temp.pop_back();
        temp.push_back('1'); //for going to right
        preorder(root->right,temp,ans);
        temp.pop_back();
    }*/
   /* void help(int &i,struct MinHeapNode* root,string bS){
        if(i>bS.size()) return; // = isliye as i=bS.size() par woh access nhi kr paaega har baar correct 
        if(!root) return;
        if(!root->left && !root->right){
          ans += root->data;
          return;
        }
        if(bS[i]=='1') help(++i,root->right,bS);
        else if(bS[i]=='0') help(++i,root->left,bS);
    }*/
    string decodeHuffmanData(struct MinHeapNode* root, string bS) {
     string ans = "";
     MinHeapNode* curr = root;  // Start at the root of the Huffman tree
        // Traverse each bit in the binary string bS
     for (int i = 0; i < bS.size(); i++) {
            // Move left if the bit is '0', right if it's '1'
        if (bS[i] == '0') {
                curr = curr->left;
         } else {
                curr = curr->right;
          }
            
            // If we've reached a leaf node, append the character
            if (!curr->left && !curr->right) {
                ans += curr->data;  // Add the character to the result
                curr = root;  // Go back to the root for the next bit sequence
            }
        }
    return ans;
    }
};
