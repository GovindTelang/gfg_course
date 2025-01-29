//1. Combination Sum
/*Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. The same number may be chosen from the array any number of times to make target.*/
class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
   /* void findComb(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds){
        if(ind==arr.size()){
            if(target==0){
                //sort(ds.begin(),ds.end());
                ans.push_back(ds);
            }
            return;
        }
        if(arr[ind]<=target && arr[ind]!=arr[ind-1]){
            ds.push_back(arr[ind]);
            findComb(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        findComb(ind+1,target,arr,ans,ds);
    }*/
     void findComb(int ind, int target, vector<int> &A, vector<vector<int>> &ans, vector<int> &ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    
    for (int i = ind; i < A.size(); i++) {
        if (A[i] <= target && (i == ind || A[i] != A[i - 1])) {
            ds.push_back(A[i]);
            findComb(i, target - A[i], A, ans, ds);
            ds.pop_back();
        }
    }
}
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(A.begin(),A.end());
        findComb(0,B,A,ans,ds);
       /* for(auto it : ans){
            sort(it.begin(),it.end());
        }*/
        //sort(ans.begin(),ans.end());
        return ans;
    }
};


//2. M-Coloring Problem
/*You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.
Note: The graph is indexed with 0-based indexing.*/

class Solution {
  public:
    bool isSafe(int node,int color[],vector<int> adj[],int v,int col){
        for(auto it : adj[node]){
            if(color[it]==col) return false; 
        }
        return true;
    }
    bool solve(int node,int color[],int m,int v,vector<int> adj[]){
        if(node==v) return true;
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,adj,v,i)){
                color[node]=i;
                if(solve(node+1,color,m,v,adj)) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<int> adj[v];
        for(int i=0;i<edges.size();i++){
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int color[v] = {0};
        return solve(0,color,m,v,adj);
    }
};


//3. Rat Maze With Multiple Jumps
/*A Maze is given as N*N matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. Find if it is possible for the rat to reach from the source block to the destination block. The number of steps rat can jump from (i, j) is represented by maze[i][j].
Note:
If multiple solutions exist, the shortest earliest hop will be accepted. For the same hop distance at any point, forward will be preferred over downward.
In the maze matrix, 0 means the block is the dead end and non-zero number means the block can be used in the path from source to destination. The non-zero value of mat[i][j] indicates number of maximum jumps rat can make from cell mat[i][j].*/
bool safe(int x,int y,int n,vector<int> m[]){
        return ( x>=0 && x<n && y>=0 && y<n && m[x][y]!=0); 
    }
bool fn(vector<int> m[],vector<vector<int>>&vis, int x,int y,int n){
        if(x==n-1 && y==n-1){
            vis[x][y]=1;
            return true;
        }
        if(safe(x,y,n,m) && !vis[x][y]){
            vis[x][y]=1;
            for(int i=1;i<=m[x][y] && i<n;i++){
                if(fn(m,vis,x,y+i,n)) return true; //forward will be preferred over downward -> correct 
                if(fn(m,vis,x+i,y,n)) return true;
            }
            vis[x][y]=0;
            return false;
        } 
        return false;
    }
void solve(int n, vector<int> maze[]) 
{
    
        vector<vector<int>>vis(n,vector<int>(n,false));
        if(fn(maze,vis,0,0,n)){
            for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
        }
        else{
            cout<<-1<<endl; //this endl is very very important so that the code gets succesfiully submitted
            return;
        }     
}


//4. Largest number in K swaps
/*Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.*/
class Solution
{
    public:
    void findMaximumNumFun(int ind,string &str,string &ans,int k){
         if(k==0||ind>=str.size()){
            ans=max(str,ans);
            return;
         }
         char mx=str[ind];
         for(int i=ind; i<str.size(); i++){
              if(i==ind){
              findMaximumNumFun(ind+1,str,ans,k);               
              }
              if(str[i]>mx){
              swap(str[ind],str[i]);
              findMaximumNumFun(ind+1,str,ans,k-1); 
              swap(str[ind],str[i]);                  
              }
         } 
    }
    //Function to find the largest number after k swaps.
    // TLE DENE WALA CODE 
  /*  void findMax(string &str,int k,string &max){
     if (k == 0)
        return;

    int n = str.length();

    // Consider every digit
    for (int i = 0; i < n - 1; i++) {

        // Compare it with all digits after it
        for (int j = i + 1; j < n; j++) {
            // if digit at position i
            // is less than digit
            // at position j, swap it
            // and check for maximum
            // number so far and recurse
            // for remaining swaps
            if (str[i] < str[j]) {
                // swap str[i] with str[j]
                swap(str[i], str[j]);

                // If current num is more
                // than maximum so far
                if (str.compare(max) > 0)
                    max = str;

                // recurse of the other k - 1 swaps
                findMax(str, k - 1, max);

                // Backtrack
                swap(str[i], str[j]);
            }
        }
    }
    }*/
    
    string findMaximumNum(string str, int k)
    {
        /*string max = str;
        findMax(str,k,max);
        return max;*/
      string ans;
      int ind=0;
      findMaximumNumFun(ind,str,ans,k);
      return ans;
       // code here.
    }
};


//5. Unique Subsets
/*Given an array arr[] of integers of size N that might contain duplicates, the task is to find all possible unique subsets.
Note: Each subset should be sorted.*/

class Solution
{
    public:
    //Function to find all possible unique subsets.
    void findSubsets(int ind,vector<int> &arr,vector<int> &ds,vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubsets(i+1,arr,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        findSubsets(0,arr,ds,ans);
        return ans;
    }
};


//6. Solve the Sudoku
/*Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.*/

class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool isValid(int grid[N][N],int row,int col,int c){
        for(int i=0;i<9;i++){
            if(grid[i][col]==c) return false;
            if(grid[row][i]==c) return false;
            if(grid[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
          for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]==0){
                    for(int c = 1;c <= 9;c++){
                        if(isValid(grid,i,j,c)){
                            grid[i][j]=c;
                            if(SolveSudoku(grid)==true) return true;
                            else grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};


//7. Black and White
/*Given the chessboard dimensions. Find out the number of ways we can place a black and a white Knight on this chessboard such that they cannot attack each other.

Note:
The knights have to be placed on different squares. A knight can move two squares horizontally and one square vertically (L shaped), or two squares vertically and one square horizontally (L shaped). The knights attack each other if one can reach the other in one move.*/

bool isSafe(int i,int j,int n,int m){
    return i>=0 && i<n && j>=0 && j<m;
}
long long numOfWays(int N, int M)
{
    // write code here
    long long ans=0;
    int m=1e9+7;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            int cnt=0;
            if(isSafe(i+2,j+1,N,M)) cnt++;
            if(isSafe(i+2,j-1,N,M)) cnt++;
            if(isSafe(i-2,j+1,N,M)) cnt++;
            if(isSafe(i-2,j-1,N,M)) cnt++;
            if(isSafe(i+1,j+2,N,M)) cnt++;
            if(isSafe(i-1,j+2,N,M)) cnt++;
            if(isSafe(i-1,j-2,N,M)) cnt++;
            if(isSafe(i+1,j-2,N,M)) cnt++;
            ans=(ans%m+(N*M-cnt-1)%m)%m;  //tum dono knights ko khio par bhi
        }                  //rkhlo bas cnt wali positions ke alawa aur dono ko same 
    }                   //place par mat rkhna
    return ans;       
}
