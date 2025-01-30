Linear Probing in Hashing
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Linear Probing to handle collisions.
    vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray)
    {
           vector<int> hashTable(hashSize, -1);

    // Insert elements into the hash table
    for (int i=0;i<sizeOfArray;i++) {
        int index = arr[i] % hashSize;
        int originalIndex = index;

        // Handle collision using linear probing
        while (hashTable[index] != -1 && hashTable[index] != arr[i]) {
            index = (index + 1) % hashSize;
            // If we have looped back to the original index, the table is full for this element
            if (index == originalIndex) {
                break;
            }
        }

        // If an empty slot or duplicate is found, insert the element
        if (hashTable[index] == -1 || hashTable[index] == arr[i]) {
            hashTable[index] = arr[i];
        }
    }

    // Print the final hash table
    return hashTable;
}
        //Your code here
    

};



//2. Separate chaining in Hashing
class Solution{
  public:
    //Complete this function
    //Function to insert elements of array in the hashTable avoiding collisions.
    vector<vector<int>> separateChaining(int hashSize,int arr[],int sizeOfArray)
    {
      vector<vector<int>> ans(hashSize);
      for(int i=0;i<sizeOfArray;i++){
        int index=arr[i]%hashSize;
        ans[index].push_back(arr[i]);
      }
      return ans;
    }
};


//3. Quadratic Probing in Hashing
class Solution{
  public:
    //Function to fill the array elements into a hash table 
    //using Quadratic Probing to handle collisions.
    void QuadraticProbing(vector <int>&hash, int hashSize, int arr[], int N)
    {
      for(int i=0;i<N;i++){
        int index=arr[i]%hashSize;
        int original=index;
        int j=1;
        while(hash[index]!=arr[i] && hash[index]!=-1){
            index=(original+j*j)%hashSize;
            j++;
            
            if(index==original) break;
        }
        if(hash[index]==-1||hash[index]==arr[i]){
            hash[index]=arr[i];
        }
      }
    
    }


};



//4. Check Equal Arrays
//User function template for C++

class Solution{
    public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
    unordered_map<ll,int> mp;
    for(int i=0;i<N;i++){
        mp[A[i]]++;
    }
    for(int i=0;i<N;i++){
        if(mp.find(B[i])==mp.end()) return false;
        if(mp[B[i]]==0) return false;
        mp[B[i]]--;
    }
    return true;
    }
};


//5. Hashing for pair - 1
//You are given an array of distinct integers and a sum. Check if there's a pair with the given sum in the array.
int sumExists(int arr[], int N, int sum) {
    // Your code here.
    unordered_set<int> s(arr,arr+N);
    for(int i=0;i<N;i++){
       if(s.find(sum-arr[i])!=s.end() && s.find(sum-arr[i])!=s.find(arr[i])){
           return 1;
       }
    }
    return 0;
}


//6. Hashing for pair - 2
//You are given an array of integers and an integer sum. You need to find if two numbers in the array exists that have sum equal to the given sum.
int sumExists(int arr[], int N, int sum) {
    // Your code here
    unordered_set<int> s(arr,arr+N);
    for(int i=0;i<N;i++){
       if(s.find(sum-arr[i])!=s.end() && s.find(sum-arr[i])!=s.find(arr[i])){
           return 1;
       }
    }
    return 0;
}


//7. Count Non-Repeated Elements
//You are given an array of integers arr[]. You need to print the count of non-repeated elements in the array.


class Solution{
    public:
    //Complete this function
    //Function to return the count of non-repeated elements in the array.
    int countNonRepeated(int arr[], int n)
    {
        unordered_map<int,int> s;
        for(int i=0;i<n;i++){
        s[arr[i]]++;   
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s[arr[i]]==1) count++;
        }
        return count;
        //Your code here
    }

};


//8. Sort Elements by Decreasing Frequency
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        unordered_map<int,int> mp;
        vector<int> ans;//don't do vector<int> ans(n) and then use push_back as o/p will be 0 0 0 n times and then your elemnts do arr[i]= instead 
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>> pairs;
        for(auto i:mp){
            pairs.push_back({i.first,i.second});
        }
        sort(pairs.begin(),pairs.end(),cmp);
        for(auto p:pairs){
            while(p.second--){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};


//9. Sort according to an Array
/*Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.*/
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
      /*int a=0;
      for(int i=0;i<A2.size();i++){
        for(int j=0;j<A1.size();j++){
            if(A1[j]==A2[i]){
                swap(A1[a],A1[j]);
                a++;
            }
        }
      }
      sort(A1.begin()+a,A1.end());
      return A1;  */
        //Your code here
    vector<int> ans;
     map<int,int> mp;
     for(int i=0;i<N;i++){
        mp[A1[i]]++;
     }
     for(int i=0;i<M;i++){
        while(mp[A2[i]]){
            ans.push_back(A2[i]);
            mp[A2[i]]--;
        }
     }
     for(auto i:mp){
         if(i.second>0){
             while(i.second>0){
             ans.push_back(i.first);
             i.second--;}
         }
     }
     return ans;
     
    } 
};


//10. Intersection of Arrays with Distinct Elements
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    int res=0;
    unordered_set<int> s(a,a+n);
    for(int i=0;i<m;i++){
        if(s.find(b[i])!=s.end()){
        res++;
        s.erase(b[i]);
        }
        
    }
    return res;
    }
};


//11. Union of Arrays with Duplicates

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> x;
        for(auto it : a) x.insert(it);
        for(auto it : b) x.insert(it);
        return x.size();
    }
};



// 12. Positive Negative Pair
// Given an array of distinct integers, find all the pairs having both negative and positive values of a number in the array.

// User function template for C++

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) 
    {
     vector<int> ans;
     unordered_map<int,int> mp;
     for(int i=0;i<n;i++){
         mp[abs(arr[i])]++;
         if(mp[abs(arr[i])]==2){
             ans.push_back(-abs(arr[i]));
             ans.push_back(abs(arr[i]));
         }
     }
     return ans;
     
    }
};


// 13. Subarray with 0 sum
//Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not.

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s;
        int presum=0;
        for(int i=0;i<n;i++){
            presum+=arr[i];
            if(s.find(presum)!=s.end()){
                return true;
            }
            if(presum==0) return true;
            else{
                s.insert(presum);
            }
        }
        return false;
        //Your code here
    }
};


//14. Zero Sum Subarrays
//You are given an array arr[] of integers. Find the total count of subarrays with their sum equal to 0.

//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        
        map<long long int,long long int> mp;
        long long int count=0;
        mp[0]=1;
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()){
                count+=mp[sum];
            }
            mp[sum]++;
        }
        //code here
      /*  unordered_set<long long int> s;
        long long int prsum=0;
        long long int count=0;
        for(int i=0;i<n;i++){
            prsum+=arr[i];
            if(s.find(prsum)!=s.end()) count++;
            if(prsum==0) count++;
            else{
                s.insert(prsum);
            }
        }*/
        return count;
    }
};



//15. Subarray range with given sum
//Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size();
        int presum = 0;
        int count = 0;
        map<int,int> mp;
        mp[presum]=1;
        for(int i=0;i<n;i++){
            presum += arr[i];
            if(mp.find(presum-tar)!=mp.end()) count+=mp[presum-tar];
            mp[presum]++;
        }
        return count;
    }
};


//16. Subarrays with equal 1s and 0s

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        unordered_map<int,int> mp;
        mp[0]=1;
        long long int res=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mp.find(sum)!=mp.end()){
             res+=mp[sum];   
            }
            mp[sum]++;
        }
        return res;
        //Your code here
    }
};


//17. Longest Consecutive Subsequence
// Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        map<int,int> mp;
        for(auto i : arr) mp[i]=i;
        int ans=0;
        int curr=1;
        for(auto it : mp){
            if(mp.find(it.first+1)!=mp.end()){
                curr++;
            }
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        return ans;
    }
};


//18. Numbers containing 1, 2 and 3
/*You are given an array arr[] of integers. Your task is to find all the numbers in the array whose digits consist only of {1, 2, 3}.

Return an array containing only those numbers from arr. The order of the numbers in the output array should be the same as their order in the input array.*/

//User function template for C++

//Function to find all the numbers with only 1,2 and 3 in their digits.
void findAll() {
     for(int i=1;i<1000000;i++){
        int num=i;
        bool v=1;
        while(num>0){
            int temp=num%10;
            if(temp==1||temp==2||temp==3){
             num=num/10; 
            }
            else{
             v=0;
             break;
            }
        }
        if(v){
         mp[i]=1;
        }
     }
}


//19. Winner of an election
//Given an array of n names arr of candidates in an election, where each name is a string of lowercase characters. A candidate name in the array represents a vote casted to the candidate. Print the name of the candidate that received the maximum count of votes. If there is a draw between two candidates, then print lexicographically smaller name.

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int freq=0;
        string ans;
        for(auto it : mp){
            if(it.second>freq){
                freq=it.second;
                ans=it.first;
            }
        }
        return {ans,to_string(freq)};
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
    }
};


//20. Account Merge
/*Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

Note: Accounts themselves can be returned in any order.*/

// User function Template for C++

class Solution {
    int find(int a, int par[])
    {
        if(a == par[a])
            return a;
        return par[a] = find(par[a], par);
    }
     
    void unionn(int a,int b,int par[],int sz[], set<string> s[]){
    	a = find(a,par);
    	b = find(b,par);
    	if(a == b)
    		return ;
    	if(sz[a]>sz[b])
    		swap(a,b);
    	par[a] = b;
    	sz[b] += sz[a];
    	s[b].insert(s[a].begin(), s[a].end());
    }
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        int par[n], sz[n];
        set<string> s[n];
        for(int i=0;i<n;i++)
            par[i] = i, sz[i] = 1, s[i].insert(accounts[i].begin() + 1, accounts[i].end());
        
        for(int i=0;i<accounts.size();i++)
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                unionn(mp[accounts[i][j]], i, par, sz, s);
                mp[accounts[i][j]] = i;
            }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
            if(par[i] == i)
            {
                // vector<int> ansHere(s[i].begin(), s[i].end());
                ans.push_back({accounts[i][0]});
                ans.back().insert(ans.back().end(), s[i].begin(), s[i].end());
                // ans.back().push_back(ansHere);
            }
        return ans;
    }
};

