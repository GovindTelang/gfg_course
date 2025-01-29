//Q1. Maximum Index
//Given an array arr of positive integers. The task is to return the maximum of j - i subjected to the constraint of arr[i] < arr[j] and i < j.
/*Input: arr[] = [1, 10]
Output: 1
Explanation: arr[0] < arr[1] so (j-i) is 1-0 = 1.*/

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        int arr1[n],arr2[n];
        arr1[0]=a[0];
        arr2[n-1]=a[n-1];
        for(int i=1;i<n;i++){
            arr1[i]=min(a[i],arr1[i-1]);
            arr2[n-i-1]=max(a[n-i-1],arr2[n-i]);
        }
        int ans=0,i=0,j=0;
        while(i<n && j<n){
            if(arr1[i]<=arr2[j]){
                ans=max(ans,abs(j-i));
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
        // Your code here
    }
};


//Q2. Check if array is sorted and rotated
/*Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.*/

class Solution{
    public:
    // arr: input array
    // num: length of array
    // This function returns true or false
    //Function to check if array is sorted and rotated.
    bool checkRotatedAndSorted(int arr[], int num){
       int count = 0;
       for(int i=0;i<num-1;i++){
           if(arr[i]>arr[i+1]){
               count++;
           }
       }
       if(count==1) return true;
       return false;
        // Your code here
        
    }
};


//Q3. Rearrange an array with O(1) extra space
/*Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].
NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.*/

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        // Your code here
        int i;
        for(i=0;i<n;i++){
            arr[i]=arr[i]+(arr[arr[i]]%n)*n;
        }
        
        for(i=0;i<n;i++){
            arr[i]=arr[i]/n;
        }
        
    }
};


//Q4. Rotate Array
/*Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.
Note: Consider the array as circular.*/

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void reverse(vector<int> &arr,int low,int high){
        while(low < high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    } 
    void rotateArr(vector<int>& arr, int d) {
        // code here
       int n = arr.size();
       if(d>n){ d %= n; }
       reverse(arr, 0, d-1);
       reverse(arr, d, n-1);
       reverse(arr, 0, n-1);
    }
};


//Q5. Array Leaders
//You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int res=a[n-1];
        ans.push_back(res);
      for(int i=n-2;i>=0;i--){
          if(a[i]>=res) {
              res = a[i];
              ans.push_back(res);
          }
      }
      reverse(ans.begin(), ans.end());
      return ans;
        // Code here
        
    }
};


//Q6. Rearrange Array Alternately
/*Given an array of positive integers. Your task is to rearrange the array elements alternatively i.e. first element should be the max value, the second should be the min value, the third should be the second max, the fourth should be the second min, and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.*/

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    {
        int i,j;
        int maxi = arr[n-1]+1;
        j=n-1;
        for(i=0;i<n;i+=2){
            arr[i]=arr[i]+(arr[j]%maxi)*maxi;
            j--;
        }
        j=0;
        for(i=1;i<n;i+=2){
            arr[i]=arr[i]+(arr[j]%maxi)*maxi;
            j++;
        }
        
        for(i=0;i<n;i++){
            arr[i]=arr[i]/maxi;
        }	 
    }
};


//Q7. Smallest Positive Missing
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
Note: Positive number starts from 1. The array can have negative integers too.

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


//Q8. Frequencies in a Limited Array
/*You are given an array arr[] containing positive integers. The elements in the array arr[] range from 1 to n (where n is the size of the array), and some numbers may be repeated or absent. Your task is to count the frequency of all numbers in the range 1 to n and return an array of size n such that result[i] represents the frequency of the number i (1-based indexing).*/
class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    {   int n=N;
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            mp[arr[i-1]]++;
        }
        for(int i=1;i<=n;i++){
            arr[i-1]=mp[i];
        }
        // code here
    }
};


//Q9. Stock buy and sell
class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector<vector<int>> ans;
    for(int i=0;i<n-1;i++){
            if(A[i]<A[i+1]){
                ans.push_back({i,i+1});
            }}
        
        return ans;
    }
};


//Q10. Trapping Rain Water
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long ans=0;
        int prev[n],next[n];
        prev[0]=arr[0];
        next[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            prev[i]=max(prev[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            next[i]=max(next[i+1],arr[i]);
        }
        for(int i=0;i<n;i++){
        ans += min(prev[i],next[i])-arr[i]; 
        }
        return (int)ans;
    }
};


//Q11. Kadane's Algorithm
//Given an integer array arr[]. You need to find the maximum sum of a subarray.
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int n = arr.size();
        long long sum = 0;
        long long maxi = INT_MIN;
        for(int i = 0 ; i <n; i++){
            sum += arr[i];
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0) 
           { sum = 0;}
        
        }
        return maxi;
    }
};


//Q12. Max Circular Subarray Sum
//Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
     int maxSubarraySum(vector<int> &arr,int n){
        int res = arr[0];
        int maxi = arr[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi + arr[i],arr[i]);
            res = max(maxi,res);
        }
        return res;
    }
    int circularSubarraySum(vector<int> &arr) {
        int num = arr.size();
        int normal = maxSubarraySum(arr,num);
        if(normal<0) return normal;
        int sum = 0;
        for(int i = 0; i<num ; i++){
            sum += arr[i];
            arr[i] = -arr[i];
        }
        int circular = sum + maxSubarraySum(arr,num);
        return max(normal,circular);
    }
};


//Q13. Minimum adjacent difference in a circular array
//Given an array Arr of n integers arranged in a circular fashion. Your task is to find the minimum absolute difference between adjacent elements.
class Solution{
    public:
    //Function to find minimum adjacent difference in a circular array.
    // arr[]: input array
    // n: size of array
    int minAdjDiff(int arr[], int n){  
        int res=abs(arr[n-1]-arr[0]);
        for(int i=0;i<n-1;i++){
            res=min(res,abs(arr[i]-arr[i+1]));
        }
        return res;
        // Your code here
        
    }
};


//Q14. Wave Array
/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place). In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
If there are multiple solutions, find the lexicographically smallest one.
Note: The given array is sorted in ascending order, and you don't need to return anything to change the original array.*/

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        for(int i=0;i+1<n;i+=2){
            swap(arr[i],arr[i+1]);
        }
        // Your code here
        
    }
};


//Q15. Maximum occured integer
/*Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one.
The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].

For example, consider the following ranges.
l[] = {2, 1, 3}, r[] = {5, 3, 9}
Ranges represented by the above arrays are.
[2, 5] = {2, 3, 4, 5}
[1, 3] = {1, 2, 3}
[3, 9] = {3, 4, 5, 6, 7, 8, 9}
The maximum occurred integer in these ranges is 3.*/

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {
     int freq[maxx+1]={0};
     for(int i=0;i<n;i++){
         freq[l[i]]++;
         freq[r[i]+1]--;
     }
     int res=0;
     for(int i=1;i<maxx;i++){
         freq[i]+=freq[i-1];
         if(freq[i]>freq[res]){
         res=i;}
     }
     return res;
        // Your code here
    }
};


//Q16. Who has the majority?
/*Given an array arr[] of size N and two elements x and y, use counter variables to find which element appears most in the array. If both elements have the same frequency, then return the smaller element.
Note:  We need to return the element, not its count.*/

class Solution{
  public:
    // Function to find element with more appearances between two elements in an
    // array.
    int majorityWins(int arr[], int n, int x, int y) {
        int countx = 0,county = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==x) countx++;
            if(arr[i]==y) county++;
        }
        if(countx>county) return x;
        if(countx<county) return y;
        else return min(x,y);
            // code here
    }
};


//Q17. Fraction Trouble
/*Consider the set of irreducible fractions A = {n/d | n≤d and d and gcd(n,d) = 1}.You are given a member of this set and your task is to find the largest fraction in this set less than the given fraction.
Note: this is a set and so all the members are unique.*/

lass Solution{
	public:
	/*
	private static int gcd(int a, int b)
    {
        // base case: if b is 0, return a
        if (b == 0)
            return a;
        
        // recursively call gcd function with remainder of a divided by b
        return gcd(b, a % b);
    }

    // method to find the largest fraction less than or equal to a given fraction n/d
    public int[] LargestFraction(int n, int d)
    {
        // initialize variables to store numerator and denominator of the largest fraction found
        int r = 0, s = 1;
        
        // set the limit for the denominator
        int limit = 10000;
        
        // loop through possible denominators from the limit to 2
        for (int q = limit; q >= 2; q--)
        {
            // calculate the numerator using the given fraction n/d and current denominator q
            int p = (n * q - 1) / d;
            
            // check if the current fraction is larger than the previous largest fraction
            if (p * s >= r * q)
            {
                // update the numerator and denominator of the largest fraction
                s = q;
                r = p;
            }
        }
        
        // calculate the greatest common divisor of the numerator and denominator
        int D = gcd(r, s);
        
        // create an array to store the resulting fraction
        int[] res = new int[2];
        
        // divide the numerator and denominator by their greatest common divisor 
        // and store the result in the array
        res[0] = (r / D);
        res[1] = (s / D);
        
        // return the resulting fraction
        return res;
    }*/
    //also checkout the hint for this same problem https://www.geeksforgeeks.org/problems/fraction-trouble1410/1
	vector<int>LargestFraction(int n, int d){
	    // Code here
	    vector<int> ans;
	    int r=0,s=1;
	    int limit = 10000;
	    for(int q=limit;q>=1;q--){
	        int p=(n*q-1)/d;
	        if(p*s>r*q){ //note: yaha par hum = laga rhe hn as hume bade se bada chahiye
	            s=q;
	            r=p;
	        }
	    }
	    int x = __gcd(r,s);
	    r=r/x;
	    s=s/x;
	    ans={r,s};
	    return ans;
	}
};


//Q18. Longest Subarray Of Evens And Odds
class Solution{
    public:
    //Complete this function
    //Function to find the length of longest subarray of even and odd numbers.
    int maxEvenOdd(int arr[], int n) 
    { 
        int res=1;
        int cur=1;
        for(int i=1;i<n;i++){
            if(arr[i-1]%2 == 0 && arr[i]%2 == 1 || arr[i]%2 == 0 && arr[i-1]%2 == 1){
                cur++;
                res=max(res,cur);
            }
            else{
                cur=1;
            }
    
        }
        return res;
       //Your code here
    } 
};


//Q19. Betting game
/*You are involved in a betting game whose rules are as follows :
a) If you win a round, the bet amount will be added to your current sum and next bet amount will become $1;
b) If you lose a round, the bet amount will be reduced from your current sum and next bet will become twice the previous.
c) game ends either when all the rounds are complete or when you don't have sufficient sum.
Initially, you are given with a string result consisiting of characters from the set {'W', 'L'}, where 'W' indicates a win and 'L' indicates a loss, and initial sum is 4. Initial bet amount for the 1st round will be $1.
You need to find and print the amount at the end of the game (final sum) and in case you do not have enough money in between the game to play the next round, then return -1.*/

class Solution{
    public:
        int betBalance(string result)
        {   int bet=1;
            int iniSum=4;
            int n=result.size();
            for(int i=0;i<n;i++){
                if(iniSum<bet){
                    return -1;
                }
                if(result[i]=='W'){
                    iniSum+=bet;
                    bet=1;
                }
               else{
                    iniSum-=bet;
                    bet *= 2;
                }
            }
            return iniSum;
            // code here
        }
};


//Q20. Equilibrium Point
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
    int n = arr.size();
    if(n==1) return 1;
    long long int totalsum = 0;
    for(int i=0; i<n; i++){
        totalsum += arr[i];
    }
    long long int leftsum = 0;
    for(int i=0; i<n; i++){
        totalsum -= arr[i];
        if(leftsum == totalsum){
         return i;
        }
        leftsum += arr[i];
    }
    return -1;
    
        // Your code here
    }
};


//Q21. Strongest Neighbour
//Given an array arr[] of n positive integers. The task is to find the maximum for every adjacent pairs in the array.
void maximumAdjacent(int sizeOfArray, int arr[]){
    int n = sizeOfArray;
    for(int i=0; i<n-1; i++){
        cout<<max(arr[i],arr[i+1])<<" ";
    }
    /*******************************************
     * Your code here
     * Function should print max adjacents for all pairs
     ********************************************/
}
