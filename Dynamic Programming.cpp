//Q1. Ways to write n as sum
// Given a positive integer n, the task is to find the number of different ways in which n can be written as a sum of two or more positive integers. Return the answer with the modulo 109+7.
//M1

class Solution {
public:
    // Function to count the number of different ways in
    // which n can be written as a sum of two or more
    // positive integers.
    int countWays1(int n, int sum)
    {
        if (n == 0) {
            return 0;
        }
        if (sum < 0) {
            return 0;
        }

        if (sum == 0) {
            return 1;
        }

        return countWays1(n, sum - n)
               + countWays1(n - 1, sum);
    }

    int countWays(int n)
    {
        // your code here
        return countWays1(n, n) - 1;
    }
};

//M2

class Solution {
  public:
    // Function to count the number of different ways in which n can be
    // written as a sum of two or more positive integers.
    int countWays(int n) {
        // table[i] will be storing the number of solutions for value i.
        // We need n+1 rows as the table is consturcted in bottom up
        // manner using the base case (n = 0).
        int table[n + 1];

        // initializing all table values as 0.
        for (int i = 0; i <= n; i++)
            table[i] = 0;

        int mod = (int)(1e9 + 7);

        // base case.
        table[0] = 1;

        // picking all integer one by one and updating the table[] values
        // from index j to the index less than or equal to n.
        for (int i = 1; i < n; i++)
            for (int j = i; j <= n; j++)
                table[j] = (table[j] % mod + table[j - i] % mod) % mod;

        // returning the result.
        return table[n] % mod;
    }
};


//Q2. Kadane's Algorithm - I
//You are given an array. Find the maximum possible sum of contiguous elements of the array ending at each position in the array. Also, return the overall maximum that we can achieve.
class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {
        // Initialize variables
        long long max_ending_here = arr[0];  // max sum of subarray ending at first element
        long long overall_max = arr[0];      // overall maximum sum
        
        // Print the first element's sum
        cout << max_ending_here << " ";
        
        // Traverse the array starting from the second element
        for (int i = 1; i < sizeOfArray; ++i) {
            // Update max_ending_here: either continue the subarray or start a new one
            max_ending_here = max((long long)arr[i], max_ending_here + arr[i]);
            
            // Print the max sum ending at this position
            cout << max_ending_here << " ";
            
            // Update the overall maximum sum
            overall_max = max(overall_max, max_ending_here);
        }
        
        // Move to the next line after printing all sums
        cout << endl;
        
        // Return the overall maximum sum
        return overall_max;
    }
};


//Q3. Kadane's Algorithm - II
//You are given an array arr of size sizeOfArr. You need to find the maximum sum in the array provided that you cannot sum neighboring elements or adjacent elements.
class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements.
    long long findMaxSumRecursive(int i, int arr[],vector<int> &dp) {
    // Base case
    if (i < 0) return 0;  // No elements left
    if (i == 0) return dp[0] = max(0, arr[0]);  // Only one element
    if(dp[i]!=-1) return dp[i];
    // Recurrence: max of including or excluding the current element
    return dp[i] = max(arr[i] + findMaxSumRecursive(i - 2, arr,dp), findMaxSumRecursive(i - 1, arr,dp));
}
    long long maximumSum(int arr[], int sizeOfArray)
    {
      int n = sizeOfArray;
      vector<int> dp(n,-1);
      int ans = INT_MIN;
      bool flag = 0;
      for(int i=0;i<n;i++){
        if(arr[i]>0) flag = 1;
        ans = max(ans,arr[i]);
      }
      if(flag==0) return ans;
      return findMaxSumRecursive(n-1,arr,dp);
    }
};


//Q4. Ways to Reach the n'th Stair
// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
class Solution {
  public:
    // Function to count number of ways to reach the nth stair.
    int countWays(int n) {
    int a = 0;
    int b = 1;
    int c = 1;
    for(int i=1;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
    }
};


//Q5.Nth Catalan Number
class Solution
{
    public:
    //Function to find the nth catalan number.
    int MOD=1e9+7;
    long long catalan(int n,vector<long long> &dp){
        if(n <= 1){
            return 1;
        }
        
        if(dp[n] !=-1){
            return dp[n];
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++){
              res = (res + (catalan(i, dp) * catalan(n - i - 1, dp)) % MOD) % MOD;
        }
        
        
        dp[n] = res;
        return res;
    }
    
    int findCatalan(int n) 
    {
      vector<long long> dp(n+1,-1);
      return catalan(n,dp);
    }
};


//Q6. Longest Common Subsequence
/*
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.
A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".*/
class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2) {
        // your code here
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};


//Q7. Coin Change - Minimum number of coins
//You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the given coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long help(int arr[], int ind, int T, vector<vector<int>>& dp){
     if(ind == 0){
        // Check if the target sum is divisible by the first element
        if(T % arr[0] == 0)
            return T / arr[0]; // If yes, return the quotient as the answer
        else
            return 1e9; // Otherwise, return a very large value to indicate it's not possible
    }
    
    // If the result for this index and target sum is already calculated, return it
    if(dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the minimum elements needed without taking the current element
    int notTaken = 0 + help(arr, ind - 1, T, dp);
    
    // Calculate the minimum elements needed by taking the current element
    int taken = 1e9; // Initialize 'taken' to a very large value
    if(arr[ind] <= T)
        taken = 1 + help(arr, ind, T - arr[ind], dp);
        
    // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
    return dp[ind][T] = min(notTaken, taken);
    }
    
    long long minimumNumberOfCoins(int coins[],int n,int value)
    {
       vector<vector<int>> dp(n,vector<int>(value+1,-1));
       long long ans = help(coins,n-1,value,dp);
       if(ans==1e9){
           return -1;
       }
       return ans;
    }
};


//Q8. Coin Change - Number of ways
//You have an infinite supply of coins, each having some value. Find out the number of ways to use the coins to sum-up to a certain required value.

class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long help(int arr[], int ind, int T, vector<vector<int>>& dp){
     if(ind == 0){
        // Check if the target sum is divisible by the first element
        if(T % arr[0] == 0)
            return 1; // If yes, return the quotient as the answer
        else
            return 0; // Otherwise, return a very large value to indicate it's not possible
    }
    
    // If the result for this index and target sum is already calculated, return it
    if(dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the minimum elements needed without taking the current element
    int notTaken = 0 + help(arr, ind - 1, T, dp);
    
    // Calculate the minimum elements needed by taking the current element
    int taken = 0;// Initialize 'taken' to a very large value
    if(arr[ind] <= T)
        taken = 0 + help(arr, ind, T - arr[ind], dp);
        
    // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
    return dp[ind][T] = notTaken + taken;
    }
    long long numberOfWays(int coins[],int n,int value)
    {
        vector<vector<int>> dp(n,vector<int>(value+1,-1));
        return help(coins,n-1,value,dp);
        
    }
};


//Q9. Minimum number of jumps
/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.*/

class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int minimumJumps(int arr[], int n){
         //striver ne krwaya tha
        if(arr[0]==0)
        return -1;
        int jumps=0, l=0, r=0;
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest, i+arr[i]);
            }
            if(farthest==0){
                return -1;
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};


//Q10. Count number of hops
// A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of nth steps.

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    const long long mod = 1e9+7;
    long long f(int i,int n,vector<long long> &dp){
        if(i==n){
            return 1;
        }
        else if(i>n) return 0;
        if(dp[i]!=-1) return dp[i]%mod;
        long long one = f(i+1,n,dp)%mod;
        long long two = f(i+2,n,dp)%mod;
        long long three = f(i+3,n,dp)%mod;
        
        return dp[i] = (one+two+three)%mod;
    }
    long long countWays(int n)
    {
        vector<long long> dp(n+1,-1);
        
        return f(0,n,dp);
        // your code here
        
    }
};


//Q11. Longest Increasing Subsequence
/*Given an array arr[] of integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).
A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.*/
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int maxi = 1;
        vector<int> dp;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            if (it == dp.end())
            {
                dp.push_back(a[i]);
            }
            else
            {
                int ind = it - dp.begin();
                dp[ind] = a[i];
            }
            maxi = max(maxi, (int)dp.size());
        }
        return maxi;
       // your code here
    }
};


//Q12. Shortest Common Supersequence
/*Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
Note: s1 and s2 can have both uppercase and lowercase English letters.*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int lcs(int n, int m, string s1, string s2) {
        // your code here
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        return m+n-lcs(m,n,X,Y);
    }
};


//Q13. Number of Unique Paths
/*Given a A X B matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.
Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].*/

class Solution
{
    public:
    //Function to find total number of unique paths.
    int f(int i,int j,vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = f(i-1,j,dp);
        int left = f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return f(a-1,b-1,dp);
    }
};


//Q14. Maximize The Cut Segments
/*Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.
Note: if no segment can be cut then return 0.*/

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int func(int l, int p, int q, int r,vector<int> &dp)
{
    if(l==0)
       return 0;                               // Base Case
           
     if(dp[l]!=-1)                              // If already memoized
        return dp[l];
        
     int a(INT_MIN),b(INT_MIN),c(INT_MIN);         // Intitialise a,b,& c with INT_MIN
  
     if(p<=l)                                      // If Possible to make a cut of length p
        a=func(l-p,p,q,r,dp);
  
     if(q<=l)                                      // If possible to make a cut of length q
        b=func(l-q,p,q,r,dp);
  
     if(r<=l)                                      // If possible to make a cut of length r
        c=func(l-r,p,q,r,dp);
  
     return dp[l]=1+max({a,b,c});                    // Memoize & return
        
}
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n+1,-1);
        int ans = func(n,x,y,z,dp);
        if(ans<0) return 0;
        return ans;
      
    }
};


//Q15. Sum of all substrings of a number
/*Given an integer s represented as a string, the task is to get the sum of all possible sub-strings of this string.
As the answer will be large, return answer modulo 109+7. 
Note: The number may have leading zeros.*/

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long toDigit(char a){ return a-'0';}
    long long sumSubstrings(string num){
        long long const mod = 1e9+7;
     int n = num.length();

// allocate memory equal to length of string

long long sumofdigit[n];

// initialize first value with first digit
sumofdigit[0] = toDigit(num[0]);

long long res = sumofdigit[0];
// loop over all digits of string
for (int i = 1; i < n; i++) {

long long numi = toDigit(num[i]);
// update each sumofdigit from previous value
sumofdigit[i]

= ((i + 1) * numi)%mod + (10 * sumofdigit[i - 1])%mod;
sumofdigit[i] = sumofdigit[i]%mod;
// add current value to the resul
res = (res+sumofdigit[i])%mod;
}
return res;  // your code here
    }
};


//Q16. 0 - 1 Knapsack Problem
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, vector<int>& wt, vector<int>& val,int n){
        if(n==0 || w == 0) return 0;
        if(w >= wt[n-1]) 
            return max(val[n-1] + solve(w-wt[n-1], wt, val, n-1) , solve(w, wt, val, n-1));
    
        else return solve(w, wt, val, n-1);
    }
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
       int n = wt.size();
       return solve(w, wt, val, n);
    }
};


//Q17. nCr
class Solution
{
    public:
    //Function to return nCr mod 10^9+7 for given n and r.
    const long long mod = 1e9+7;
    int nCrMemoization(int n,int r, vector<vector<int>>& dp) {
     if (r == 0 || r == n) {
        return 1;
    }

    // If already computed, return the stored value
    if (dp[n][r] != -1) {
        return dp[n][r];
    }

    // Recurrence relation: nCr = (n-1)Cr + (n-1)C(r-1)
    dp[n][r] = (nCrMemoization(n - 1, r, dp) + nCrMemoization(n - 1, r - 1, dp))%mod;

    return dp[n][r]%mod;
    }
    int nCrModp(int n, int r) 
    { 
    if(r>n) return 0;
    vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
    return nCrMemoization(n,r,dp);
      
    } 
};


//Q18. Optimal Strategy For A Game
/*You are given an integer array arr[] of size n. The array elements represent n coins of values v1, v2, ....vn. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value. You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.
Input: arr[] = [5, 3, 7, 10]
Output: 15
Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.*/
class Solution{
    public:
    long long maxsum(long long sum,int i,int j,int arr[],vector<vector<long long>> &dp){
        if(i+1 == j) return max(arr[i],arr[j]);
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = max(sum-maxsum(sum-arr[i],i+1,j,arr,dp),sum-maxsum(sum-arr[j],i,j-1,arr,dp));
    }
    long long maximumAmount(int n, int arr[]){
        /* will not work as this is greedy and greedy needs some uniformity and this qquestion lacks it
         for example arr[] = {8, 15, 3, 7} an dboth players play it optimally
    deque<int> dq(arr,arr+n);
    long long ans = 0;
    int cnt = 0;
    while(!dq.empty()){
        int maxi;
        if(!dq.empty()){
        maxi = max(dq.back(),dq.front()); 
        }
        if(cnt%2 == 0){
            ans += maxi;
        }
        if(maxi==dq.back()) dq.pop_back();
        else dq.pop_front();
        cnt++;
    }
    return ans;*/
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,-1));
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return maxsum(sum,0,n-1,arr,dp);
    }
};


//Q19. Reach a given score
//Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find the number of distinct combinations to reach the given score.
ll count(ll n) 
{
      long long int dp[n + 1]={0};
        dp[0]=1;
       

        for (int i = 3; i <= n; i++) {
            dp[i] += dp[i - 3];
        }

        for (int i = 5; i <= n; i++) {
            dp[i] += dp[i - 5];
        }

        for (int i = 10; i <= n; i++) {
            dp[i] += dp[i - 10];
        }

        return dp[n];
}


//Q20. Egg Dropping Puzzle
/*You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the egg breaks on a certain floor, it will break on any floor above.
Return the minimum number of moves you need to determine the value of f with certainty.
Input: n = 1, k = 2
Output: 2
Explanation: Drop the egg from floor 1. If it breaks, we know that f = 0. Otherwise, drop the egg from floor 2.If it breaks, we know that f = 1.  If it does not break, then we know f = 2. Hence, we need at minimum 2 moves to determine with certainty what the value of f is.
Input: n = 10, k = 5
Output: 3
Explanation: Drop the egg from floor 2. If it breaks, test floor 1 with a remaining egg.If it doesn’t break, drop from floor 4. If it breaks, test floor 3. If it still doesn’t break, we know the critical floor is 5.Hence, with a minimum of 3 moves, we can find the critical floor.
Input: n = 2, k = 10
Output: 4
Explanation: Drop the egg from floor 4. If it breaks, we only need to test floors 1 to 3 with the remaining egg.If it doesn't break, drop the egg from floor 7. If it breaks, we only need to test floors 5 and 6. If it doesn't break again, drop the egg from floor 9. If it breaks, test floor 8. If it still doesn’t break, we know the critical floor is 10.Hence, with a minimum of 4 moves, we can determine the critical floor.*/

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int res(int n,int k,vector<vector<int>> &dp){
        if(n==1) return k; 
        if(k<=1) return k;
        if(dp[n][k]!=-1) return dp[n][k];
        int mini = INT_MAX;
        for(int x=1;x<=k;x++){
            mini = min(mini,max(res(n-1,x-1,dp),res(n,k-x,dp))+1);
        }
        return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return res(n,k,dp);
    }
};


//Q21. Unique BST's
/*Given an integer. Find how many structurally unique binary search trees are there that stores the values from 1 to that integer (inclusive).*/

class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int MOD=1e9+7; 
    long long catalan(int n,vector<long long> &dp){ 
       if(n <= 1){ return 1; } 
       if(dp[n] !=-1){ return dp[n]; } 
       int res = 0; 
       for(int i=0;i<n;i++){ 
           res = (res + (catalan(i, dp) * catalan(n - i - 1, dp)) % MOD) % MOD; 
       } 
       dp[n] = res;
       return res;
       }
    int numTrees(int N) 
    {
      vector<long long> dp(N+1,-1);
      return catalan(N,dp);
        // Your code here
    }
};


//Q22. Stickler Thief
/*Stickler the thief wants to loot money from n houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot. Given an array, arr[] where arr[i] represents the amount of money in the i-th house, find the maximum amount he can loot.*/
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(int i,int arr[],vector<int> &dp){
        
        if(i<0) return 0;
        if(i==0) return arr[0];
        if(dp[i]!=-1) return dp[i];
        int take = arr[i]+f(i-2,arr,dp);
        int not_take = 0+f(i-1,arr,dp);
        return dp[i]=max(take,not_take);
    }
    int FindMaxSum(int arr[], int n)
    {
       vector<int> dp(n,-1);
       return f(n-1,arr,dp);
    }
};


//Q23. Max sum subarray by removing at most one element
//Given an array arr. You need to find the maximum sum of the sub-array with the condition that you are allowed to skip at most one element.
class Solution {
  public:
    // Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> f(n,0);
        int largetSoFar = max(arr[0],arr[n-1]);
        
        f[0] = arr[0]; // forward
        
        for(int i = 1; i < n; i++){
            f[i] = max(f[i - 1] + arr[i], arr[i]);
            largetSoFar = max(largetSoFar, f[i]);
        }
        
        vector<int> b(n, 0); // backward
        b[n - 1] = arr[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            b[i] = max(b[i + 1] + arr[i], arr[i]);
        }
        

        for(int i=1;i<=n-2;i++){
            largetSoFar = max(f[i - 1] + b[i + 1], largetSoFar);
        }
        
        return largetSoFar;
    /*  int n = arr.size();
      int pre[n];
      int suf[n];
      int ans = max(arr[0],arr[n-1]);
      pre[0]=arr[0];
      suf[n-1]=arr[n-1];
      for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],pre[i-1]+arr[i]);
        ans = max(ans,pre[i]);
      }
      for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],suf[i+1]+arr[i]);
        ans = max(ans,suf[i]);
      }
      for(int i=1;i<n-1;i++){
          ans = max(ans,pre[i-1]+suf[i+1]);
      }
      return ans;*/
    }
};


//Q24. Equal Sum Partition
/*Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.*/

class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
   bool subsetSumUtil(int ind, int target,int arr[], vector<vector<int>>& dp) 
    {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if (dp[ind][target] != -1) return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
    }
     
   bool subsetSumToK(int n, int k,int arr[]) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumUtil(n - 1, k, arr, dp);
   }


    bool findPartition(int a[], int n)
    {
        int sum = accumulate(a,a+n,0);
        if(sum%2) return false;
        return subsetSumToK(n,sum/2,a);
       
    }
};


