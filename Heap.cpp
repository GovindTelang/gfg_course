/*1. A binary heap is a Binary Tree with the following properties:
1) Its a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
3) 3  (a query like this removes the min element from the min-heap and prints it ).*/ 1.
/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/



//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if (heap_size == 0)
		return -1;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	swap(harr[0],harr[heap_size-1]);
	heap_size--;
	MinHeapify(0);

	return harr[heap_size];
    // Your code here
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if(i>heap_size-1) return;
    decreaseKey(i, INT_MIN);
	extractMin();
    // Your code here
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    if (heap_size == capacity)
	{
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(harr[i], harr[parent(i)]);
	i = parent(i);
	}
    // Your code here
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}



// 2.Heap Sort
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        if(left<n && arr[left]>arr[largest]) largest=left;
        if(right<n && arr[right]>arr[largest]) largest=right;
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
        
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
      for (int i = n / 2 - 1; i >= 0; i--) 
      heapify(arr, n, i);
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
        //code here
    }
};

//3. Kth largest element
class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // implementing MinHeap using priority queue.
        priority_queue<int, vector<int>, greater<int> > pq;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            // if size of priority queue becomes equal to k and top
            // element is smaller than arr[i], we pop the front
            // element and push arr[i] in priority queue.
            if (pq.size() == k && pq.top() < arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
            // else we just push arr[i] in priority queue.
            else if (pq.size() < k)
                pq.push(arr[i]);
        }
        // returning the top element of priority queue.
        return pq.top();
    }
};


//4.Nearly sorted
/*Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.*/
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
       priority_queue<int,vector<int> , greater<int>>pq; // min heap
        int n = arr.size(); // array size 
        // push (k + 1) elements into min heap
        for(int i = 0 ; i <= k ; i++) {
            pq.push(arr[i]);
        }
        
        int index = 0;
        // pop root of min heap, which will be the smallest element in the window
       // place at 'index'
       // push next element into min heap, so that there are always (k + 1) elements in min heap 
        for(int i = k + 1 ; i < n ; i++) {
            arr[index++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        // if min heap is NOT empty
       // insert remaining elements
        while(!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        } 
    }
};



//5. K Most occurring elements
class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    typedef pair<int,int> P;
    int kMostFrequent(int arr[], int n, int k) 
    {   int ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto &it:mp){
            int value = it.first;
            int freq = it.second;
            pq.push({freq,value});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans+=pq.top().first;
            pq.pop();
        }
        return ans;
    	// Your code here	
    } 
};


//6. Rearrange characters
/*Given a string S such that it may contain repeated lowercase alphabets. Rearrange the characters in the string such that no two adjacent characters are same.*/
class Solution
{
    public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    typedef pair<int,char> P;
    string rearrangeString(string str)
    {
        int n = str.length();
        vector<int> count(26,0);
        for(char&ch : str){
            count[ch-'a']++;
            if(count[ch-'a'] > (n+1)/2) return "";//like aaab it is not possible
        }
        //max heap max freq wale characters chahiye
        priority_queue<P> pq;
        for(char ch='a';ch<='z';ch++){
            if(count[ch-'a']>0){
                pq.push({count[ch-'a'],ch});
            }
        }
        
        string result = "";
        while(pq.size()>=2){
            auto p1 = pq.top();
            pq.pop();
            
            auto p2 = pq.top();
            pq.pop();
            
            
            result.push_back(p1.second);
            p1.first--;
            result.push_back(p2.second);
            p2.first--;
            
            if(p1.first>0) pq.push(p1);
            if(p2.first>0) pq.push(p2);
        }
        //ek character shyd bacha ho 
        if(pq.size()) result.push_back(pq.top().second);
        return result;
    	// Your code here
    }
};


//7. Merge k Sorted Arrays
/*Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).*/
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x : arr){
            for( auto i : x){
                pq.push(i);
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        //code here
    }
};


//8. Find median in a stream
/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.*/
class Solution
{
    public:
    priority_queue<int> leftHeap;//Max heap
    priority_queue<int,vector<int>,greater<int>> rightHeap;//min heap         
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(leftHeap.empty()){
            leftHeap.push(x);
            return;
        }
        if(x>leftHeap.top()) rightHeap.push(x);
        else leftHeap.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()                 
    {                                               
      if(rightHeap.size()>leftHeap.size()){
          leftHeap.push(rightHeap.top());
          rightHeap.pop();
      }
      else{
          if(rightHeap.size()<leftHeap.size()-1){
            rightHeap.push(leftHeap.top());
            leftHeap.pop();
          }
      }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(leftHeap.size()>rightHeap.size()){            
            return leftHeap.top();
        }
        else{
            double ans=leftHeap.top()+rightHeap.top();
            ans/=2;
            return ans;
        }
    }
};


//9. Kth largest element in a stream
//Given an input stream of n integers, find the kth largest element each time when an new element is added to the stream.
class Solution
{
    public:
    //Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k)
    {
        priority_queue<int,vector<int>,greater<int>>p;
        vector<int> ans;
        for(int i=0;i<n;i++){
            p.push(arr[i]);
            if(p.size()<k) ans.push_back(-1);
            else{
                while(p.size()>k){
                    p.pop();
                }
                ans.push_back(p.top());
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    	// your code here
    }
};





