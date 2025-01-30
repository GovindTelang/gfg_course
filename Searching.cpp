//1.Majority Element
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int count=1;
        int res=0;
        for(int i = 1;i<size;i++)
        {
         if(a[i] == a[res]) count++;
         else {count--;}
         if(count == 0) 
         {
            count = 1;
            res=i;
         }
        }
        
        count = 0;
        for(int i=0;i<size;i++)
        {
            if(a[res] == a[i]) count++;
        }
        if(count <= (size/2)) return -1;
        return a[res];
        // your code here
        
    }
};


//2. Smallest Positive Missing

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        bool flag=false;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int i=1;
        for(i=1;i<n+1;i++){
            if(mp.find(i)==mp.end()){
                flag=true;
                break;
            }
        }
        return i;
    }
};


//3. Square Root
class Solution {
  public:
    long long int floorSqrt(long long int x) {
        // Your code goes here
    if(x==0||x==1) return x;
    long long int low = 1;
    long long int high = x;
    long long int ans;
    while(low <= high)
    {   
       long long int mid = (high+low)/2;
        if(mid*mid == x){
         return mid;
        }
        if(mid*mid < x){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
    }
};


//4. Minimum Number in a sorted rotated array
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        int ans=arr[0];
       while(low<=high){
           int mid=(low+high)/2;
         
           if(arr[mid]>arr[high]){
               low=mid+1;
           }
           else{
               high=mid-1;
               ans=min(arr[mid],ans);
           }
          
       }
       // this works till the last case
      /* map<int,int> s;
        for(int i=0;i<=high;i++){
            s[arr[i]]++;
        }
        return s.begin()->first;*/
        
        // Your code here
        return ans;
    }
};


//5. Indexes of Subarray Sum
/*Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].*/

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target){
        int n = arr.size();
        int start = 0,end = 0;
        long long sum = 0;
        while(end<n){
            sum += arr[end];
            while(sum>target && start<end){
                sum -= arr[start++];
            }
            if(sum==target){
                return {start+1,end+1};
            }
            end++;
        }
        return {-1};
    }
};



//6. Median of Two sorted arrays
/*Given two sorted arrays of sizes N and M respectively. The task is to find the median of the two arrays when they get merged.
If there are even number of elements in the resulting array, find the floor of the average of two medians.*/

class Solution
{
    public:
    //Function to find the median of the two arrays when they get merged.
    int findMedian(int arr[], int n, int brr[], int m)
    {
        if(n>m) return findMedian(brr,m,arr,n);
        int l = 0;
        int r = n;
        while(l<=r){
            int mid1 = l+(r-l)/2;
            int mid2 = (m+n+1)/2-mid1;
            
            int x1 = (mid1==0)?INT_MIN:arr[mid1-1];
            int x2 = (mid2==0)?INT_MIN:brr[mid2-1];
            int x3 = (mid1==n)?INT_MAX:arr[mid1]; //ydi mid1 yani left side ke arr ke elemnts ka count hi pure arr ke elemnts aa gye toh rhs main intmax
            int x4 = (mid2==m)?INT_MAX:brr[mid2]; // ydi mid2 main yani left side ke brr ke elements ka count hi pure brr ke elements aa gye toh rhs main intmax
            
            if(x1<=x4 && x2<=x3){
                if((m+n)%2) return max(x1,x2);
                else return (max(x1,x2)+min(x3,x4))/2;
            }
            else if(x1>x4){
                r=mid1-1;
            }
            else l=mid1+1;
        }
        return -1;//if ans is not possible actually main yeh line execute nhi hogi
        // code here
    }
};



//7. Count only Repeated
/*Given an array arr[] of n positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating x(any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.
Note: If there's no repeating element, Return {-1,-1}.*/

class Solution
{
    public:
    //Function to find repeated element and its frequency.
    pair<long, long> findRepeating(long *arr, int n){
       pair<long, long> ans;
       if(arr[n-1]==n) {return {-1,-1};}
       ans.second = (long)n-(arr[n-1]-arr[0]);
       long slow = arr[0],fast=arr[0];
       do{
           slow = arr[slow];
           fast = arr[arr[fast]];
       }
       while(slow!=fast);
       slow=arr[0];
       while(slow!=fast){
           slow=arr[slow];
           fast=arr[fast];
       }
       ans.first = slow;
       return ans;
        //code here
    }
};



//8. Two Repeated Elements
/*You are given an integer n and an integer array arr of size n+2. All elements of the array are in the range from 1 to n. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.
Note: Return the numbers in their order of appearing twice. So, if x and y are repeating numbers, and x's second appearance comes before the second appearance of y, then the order should be (x, y).*/


class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        vector<int> v;
        int count[n+1]={0};
        for(int i=0;i<n+2;i++){
            count[arr[i]]++;
            if(count[arr[i]] == 2){
                v.push_back(arr[i]);
            }
        }
        return v;
        // Your code here
    }
};



//9. Allocate Minimum Pages
/*You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).*/


class Solution {
  public:
      bool isPossible(vector<int>&arr,int k,int mid){
      int cnt=1;
      int sum=0;
      for(int i=0;i<arr.size();i++){
          if(sum+arr[i]>mid){
              sum=arr[i];
              cnt++;
          }
          else
          sum+=arr[i];
      }
      return cnt<=k;
  }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size())
        return -1;
       int low=*max_element(arr.begin(),arr.end());
       int high=accumulate(arr.begin(),arr.end(),0);
       int ans=-1;
       while(low<=high){
           int mid=(low+high)/2;
           if(isPossible(arr,k,mid)){
           high=mid-1;
              ans=mid;
           }
           else
               low=mid+1;
       }
       return ans;
    }
};



//10. Maximum Water Between Two Buildings
/*Given an integer array representing the heights of N buildings, the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum.
Note: The total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller building.*/

class Solution
{
    public:
    //Function to return the maximum water that can be stored.
    int maxWater(int height[], int n) 
    { 
        if(n<3) return 0;
        int low=0,high=n-1;
        int ans=0;
        while(low<high){
        int govind=(high-low-1)*(min(height[low],height[high]));
        ans=max(ans,govind);
        if(height[low]<height[high]){
            low++;
        }
        else{
            high--;
        }
        
        }
        return ans;
    } 
};
