//1.Merge Without Extra Space

class Solution {
  public:
    void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
            int n = arr1.size();
            int m = arr2.size();
            long long arr3[n+m];
            for(int i=0;i<n;i++){
                arr3[i]=arr1[i];
            }
            for(int j=0;j<m;j++){
                arr3[n+j]=arr2[j];
            }
            sort(arr3,arr3+n+m);
            for(int i=0;i<n;i++){
                arr1[i]=arr3[i];
            }
            for(int j=0;j<m;j++){
                arr2[j]=arr3[n+j];
            }
    }
};


//2. Merge three sorted arrays
class Solution{
  public:
    // A, B, and C: input sorted arrays
    //Function to merge three sorted vectors or arrays 
    //into a single vector or array.
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
    { 
        vector<int> v;
        map<int,int> mp;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
        }
        for(int i=0;i<B.size();i++){
            mp[B[i]]++;
        }
        for(int i=0;i<C.size();i++){
            mp[C[i]]++;
        }
        for(auto x : mp){
            while(x.second>0){
                v.push_back(x.first);
                x.second--;
            }
        }
        return v;
        //Your code here
    } 

};


//3. Find triplets with zero sum
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr,arr+n);
        bool flag = false;
        for(int i=0;i<n;i++){
            int x = arr[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(x+arr[j]+arr[k]==0){
                    flag=true;
                    break;
                }
               else if(x+arr[j]+arr[k]>0){
                    k--;
                }
                else{
                    j++;
                }
                
            }
        
        }
        return flag;
        //Your code here
    }
};


//4. Count Inversions
/*Given an array of integers arr[]. Find the Inversion Count in the array.
Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. */

class Solution {
  public:
    // Function to count inversions in the array.
    int  merge(vector<int>&arr ,int s ,int mid , int e){
        int left =s,right = mid+1;
        int count=0;
        vector<int>temp;
        while(left<=mid && right<=e){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                count+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
             temp.push_back(arr[left]);
                left++;
        }
        while(right<=e){
            temp.push_back(arr[right]);
                right++;
        }
        for(int i=s;i<=e;i++){
            arr[i]=temp[i-s];
        }
         return count;
    }
    int sort(vector<int>&arr ,int s ,int e){
        if(s>=e){
            return 0 ;
        }
        int count=0;
        int mid = s+ (e-s)/2;
        count+=sort(arr,s,mid);
        count+=sort(arr,mid+1,e);
        count+=merge(arr,s,mid,e);
        return count;
    }

    int inversionCount(vector<int> &arr) {
    /*   int count =0;
        for(int i =0;i<arr.size();i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(arr[i]>arr[j])
                {
                    count++;
                }
            }
        }
        return count;*/
        int n=arr.size();
       int count= sort(arr,0,n-1);
        return count;
        // Your Code Here
    }
};



//5. Quick Sort
/*Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. Given an array, arr[], with starting index low and ending index high, complete the functions partition() and quickSort(). Use the last element as the pivot so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.

Note: The low and high are inclusive.*/

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
        // code here
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
       // Your code here
    }
};


//6. Closet 0s 1s and 2s
/*Given an array of 0s, 1s, and 2s. Arrange the array elements such that all 0s come first, followed by all the 1s and then, all the 2s.

Note: Do not use the inbuilt sort function.*/

class Solution{
    public:
    
    // The function should do the stated modifications in the given array arr[]
    // Do not return anything.
    
    // arr[]: Input Array
    // N: Size of the Array arr[]
    //Function to segregate 0s, 1s and 2s in sorted increasing order.
    void segragate012(int arr[], int N)
    {
        int low=0,mid=0,high=N-1;
        while(mid<=high){
            if(arr[mid]==0){
                swap(arr[low],arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
            }
        }
        // Your Code Here
    }
};


//7. Minimum Platforms
/*You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.*/


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0;
    	int j=0;
    	int maxi = 0;
    	int count = 0;
    	while(i<n){
    	   if(arr[i]<=dep[j]){
    	       count++;
    	       maxi = max(maxi,count);
    	       i++;
    	   }
    	   else{
    	       count--;
    	       j++;
    	   }
    	}
    	return maxi;
    }
};



//8. Counting Sort

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        string s;
        map<char,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
       
           for(auto j:mp){
            while(j.second>0){
                s += j.first ;
                j.second--;
            }
            }
            
        
        return s;
    }
};



//9. Count the number of possible triangles
/*Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 

A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.*/


class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int cnt = 0;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n;j++){
                int ind = lower_bound(arr.begin()+j+1,arr.end(),arr[i]+arr[j])-arr.begin();
                cnt += ind-j-1;
            }
        }
        return cnt;
    }
};



//10. Triplet Sum in Array
/*Given an array arr[] and an integer target, determine if there exists a triplet in the array whose sum equals the given target.

Return true if such a triplet exists, otherwise, return false.*/


class Solution{
    public:
    bool isPairSum(int arr[],int n,int x,int si){
        int i=si;
        int e=n-1;
        while(i<e){
        if(arr[i]+arr[e]==x) return true;
        else if(arr[i]+arr[e]>x) {e--;}
        else{
            i++;
        }}
        return false;
    }
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {   sort(A,A+n);
        for(int i=0;i<n-2;i++){
            if(isPairSum(A,n,X-A[i],i+1)){
                return true;
            }
        }
        return false;
        //Your Code Here
    }

};



//11. Number of pairs
/*Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.*/

class Solution {
  public:
    long long countPairs(vector<int> &X, vector<int> &Y) {
        // Your Code goes here.
        int M = X.size();
        int N = Y.size();
        vector<double> x(M),y(N);
        for(int i=0;i<M;i++){
            x[i]=log(X[i])/X[i];
        }
        for(int j=0;j<N;j++){
            y[j]=log(Y[j])/Y[j];
        }
        sort(x.begin(),x.end());
     //   sort(y.begin(),y.end());
        long long cnt = 0;
        for(int i=0;i<N;i++){
            int it = upper_bound(x.begin(),x.end(),y[i])-x.begin();
            if(it!=M) cnt += M-it;
        }
        return cnt;
    }
};



//12. Closer to sort
//Given an array arr[](0-based indexing) of N integers which is closer sorted (defined below) and an element x. The task is to find the index of element x if it is present. If not present, then print -1.
//Closer Sorted: The first array is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e, maybe to the arr[i+1] or arr[i-1].

class Solution{
  public:

    // arr[]: input array
    // n: size of array
    // x: element to find index
    //Function to find index of element x in the array if it is present.
    int closer(int arr[],int n, int x)
    {
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==x) return mid;
            else if(arr[mid-1]==x) return mid-1;
            else if(arr[mid+1]==x) return mid+1;
            else if(arr[mid]<x) low=mid+1;
            else high=mid-1;
        }
        return -1;
        //Your code here
    }
};



