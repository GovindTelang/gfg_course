//1. Print adjacency list
//Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &num : edges){
            int first = num.first;
            int second = num.second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        return adj;
    }
};


//2. BFS of graph
/*Given a undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.*/
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> bfs;
        int vis[V] = {0};
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            bfs.push_back(top);
            for(auto &it : adj[top]){
                if(!vis[it]){
                vis[it]=1;
                q.push(it);
                }
            }
            
        }
        return bfs;
    }
};


//3. Distance of nearest cell having 1
/*Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.*/
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col]=steps;
            for(int i=0;i<4;i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
    }
};


//4. DFS of Graph
class Solution {
  public:  
 //note : int &node will not come as node for a particular call cannot be changed if u use & it wwill change
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        //traverse through all its neighbours 
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        int start = 0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls;
        
    }
};


//5. Rotten Oranges
/*Given a matrix where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i, j] can rot other fresh orange at indexes [i-1, j], [i+1, j], [i, j-1], [i,j+1] (up, down, left and right) in unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.*/

class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            //intni choti to glti mt kr meri jaan
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){
                q.push({{i,j},{0}});
                vis[i][j]=1;
                }
            }
        }
        
       int delrow[4]={-1,0,1,0};
       int delcol[4]={0,1,0,-1};
       
       int ans=0;
       
       while(!q.empty()){
           
           int row=q.front().first.first;
           int col=q.front().first.second;
           int dist=q.front().second;
           
           q.pop();
           
           ans=max(ans,dist);
           
           for(int i=0;i<4;i++){
               
                 int nrow=row+delrow[i];
                int ncol=col+delcol[i];
               
               if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                   vis[nrow][ncol]=1;
                   q.push({{nrow,ncol},{dist+1}});
               }
           }
       }
       
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(grid[i][j]==1 and vis[i][j]==0){
                  return -1;
              }
          }
      }
      return ans;
    }
};


//6. Steps by Knight
/*Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position coordinates of Knight have been given according to 1-base indexing*/

class Solution 
{
    void bfs(vector<int>&KnightPos,vector<int>&TargetPos,int N,int&ans,vector<vector<int>>&vis){
        int ix=KnightPos[0];
        int iy=KnightPos[1];
        int dirX[]={1,2,2,1,-1,-2,-2,-1};
        int dirY[]={2,1,-1,-2,-2,-1,1,2};
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{ix,iy}});
        while(!q.empty()){
            int lvl=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            vis[x][y]=1;
            for(int i=0;i<8;i++){
                int newx=x+dirX[i];
                int newy=y+dirY[i];
                if(newx==TargetPos[0] and newy==TargetPos[1]){
                    ans=lvl+1;
                    return;
                }
                else{
                    if(newx>=1 and newx<=N and newy>=1 and newy<=N and !vis[newx][newy]){
                        q.push({lvl+1,{newx,newy}});
                        vis[newx][newy]=1;
                    }
                }
            }
        }
    }
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>>vis(N+1,vector<int>(N+1));
        int ans=-1;
        bfs(KnightPos,TargetPos,N,ans,vis);
        return ans==-1?0:ans;
	}
};


//7. Find the number of islands
/*Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/

class Solution {
  public:
    int r;
    int c;
    int row[8]={-1,-1,-1,1,1,1,0,0};
    int col[8]={-1,0,1,-1,0,1,-1,1};
    // Function to find the number of islands
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    
    int numIslands(vector<vector<char>>& grid) {
    r=grid.size();
    c=grid[0].size();
    queue<pair<int,int>> q;
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='1'){
                count++;
                q.push({i,j});
                grid[i][j]='0';
                while(!q.empty()){
                    int new_i=q.front().first;
                    int new_j=q.front().second;
                    q.pop();
                    for(int k=0;k<8;k++){
                        if(valid(new_i+row[k],new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]=='1'){
                            grid[new_i+row[k]][new_j+col[k]]='0';
                            q.push({new_i+row[k],new_j+col[k]});
                        }
                    }
                }
            }
        }
    }
    return count;
    }
};


//8. Find whether path exist
/*Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall (blocked cell which we cannot traverse).
Note: There are only a single source and a single destination.*/

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    int n,m;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    bool valid(int i,int j)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int sx ,sy ,dx,dy;
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                 sx = i;
                 sy = j;
                }
                
                
            }
        }
        queue<pair<int,int>>q;
        q.push({sx,sy});
        grid[sx][sy] = 0;
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int new_i = i+row[k];
                int new_j = j+col[k];
                
                if(valid(new_i,new_j)&&grid[new_i][new_j]!=0)
                {
                    if(grid[new_i][new_j]==2)
                    return 1;
                    grid[new_i][new_j] = 0;
                    q.push({new_i,new_j});
                    
                }
                
            }
        }
        return 0;
    }
};


// 9.Level of Nodes
/*Given an integer x and an undirected acyclic graph with v nodes, labeled from 0 to v-1, and e edges, return the level of node labeled as x.

Level is the minimum number of edges you must travel from the node 0 to some target.

If there doesn't exists such a node that is labeled as x, return -1.*/

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>>q;
	    q.push(make_pair(0,0));
	    unordered_map<int,bool>visited;
	    while(!q.empty()){
	        pair<int,int>node = q.front();
	        q.pop();
	        int node_element = node.first;
	        int height = node.second;
	        if(node_element == X) return height;
	        visited[node_element] = true;
	        for(auto i:adj[node_element]){
	            if(!visited[i]){
	                q.push(make_pair(i,height+1));
	                visited[i] = true;
	            }
	        }
	    }
	    return -1;
	}
};


//10. Possible paths between 2 vertices
/*Given a Directed Graph having V nodes numbered from 0 to V-1, and E directed edges. Given two nodes, source and destination, count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesn't contain multiple edges, self-loop, and cycles.
*/
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
         // Code here
     /*    //correct hn yeh wala bhi
        vector<bool>vis(n,false);
        int ans=0;
        function<void(int)>dfs=[&](int src){
            if(src==dest){
                ans++;
                return;
            }
            vis[src]=true;
            for(auto i:adj[src]){
                if(!vis[i]){
                    dfs(i);
                }
            }
            vis[src]=false;
        };        
        dfs(src);
        return ans;   */
        queue<int>q;
        q.push(source);
        vector<int> vis(V,0);
        int cnt=0;
        while(!q.empty()){
            
            int node=q.front();
            q.pop();
            if (node==destination) {
                cnt++;
                continue;
            }
            for (auto it:adj[node]){
                q.push(it);
                
            }
        }
        return cnt;
    }
};


//12. X Total Shapes
/*Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).*/

class Solution
{
    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    
    bool valid(int i,int j)
    {
        return i>=0&&i<r&&j>=0&&j<c;
    }
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
         r = grid.size();
         c = grid[0].size();
        queue<pair<int,int>>q;
        int shapes = 0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='X')
                {
                    grid[i][j]='T';
                    shapes++;
                    q.push(make_pair(i,j));
                    while(!q.empty())
                    {
                        int new_i = q.front().first;
                        
                        int new_j = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]=='X')
                            {
                                
                                
                                grid[new_i+row[k]][new_j+col[k]]='T';
                                q.push(make_pair(new_i+row[k],new_j+col[k]));
                            }
                        }
                        
                    }
                }
            }
        }
        return shapes;
    }
};


// 13. Undirected Graph Cycle
/*Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].*/

class Solution {
  public:
    bool detect(int src,int vis[],vector<vector<int>>& adj){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push(make_pair(src,-1));
       
       while(!q.empty()){
           
        int node = q.front().first;
        int parent = q.front().second;
        
        q.pop();
        
        for(auto adjacent : adj[node]){
            if(!vis[adjacent]){
                q.push(make_pair(adjacent,node));
                vis[adjacent] = 1;
            }
            else if(adjacent!=parent){
                return true;
            }
        }
        
       }return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                if(detect(i,vis,adj)==true){
                    return true;
                }
            }
            
        }
        return false;
    }
};


//14. Topological sort
/*Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.*/

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int node,vector<vector<int>>& adj,stack<int> &st,int vis[]){
        vis[node]=1;
        for(int i=0;i<adj[node].size();i++){
          for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
          }  
        }
        st.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       int v = adj.size(); 
       int vis[v]={0};
       stack<int> st;
       for(int i=0;i<v;i++){
           if(!vis[i]){
               dfs(i,adj,st,vis);
           }
       }
       vector<int> ans;
       while(!st.empty()){
           int it = st.top();
           st.pop();
           ans.push_back(it);
       }
       return ans;
    }
};


//15. Minimum Swaps to Sort
/*Given an array arr[] of distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.*/

class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        vector<pair<int,int>>v;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        int ct=0;
        for(int i=0;i<v.size();)
        {
            if(v[i].second==i)
            {
                i++;
                continue;
            }
            else  
            {
                ct++;
                swap(v[i],v[v[i].second]);
            }
        }
        return ct;
    }
};


//16. Mother Vertex
/*Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
*/

class Solution 
{
    void dfs(int i,stack<int>&s,vector<int> &vis,vector<int>adj[]){
        vis[i]=1;
 
        for (auto it:adj[i] ){
            if (!vis[it]){
            dfs(it,s,vis,adj);
            }
        }
        s.push(i);
        return ;
    }
    void f(int i,vector<int> &vis,vector<int>adj[],int &count){
        vis[i]=1;
        
        count++;
        for (auto it:adj[i]){
            if (!vis[it]){
                f(it,vis,adj,count);
            }
        }
    }
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	stack<int>s;
    vector<int> vis(V,0);
    for (int i=0;i<V;i++){
        if (!vis[i]){
            dfs(i,s,vis,adj);
        }
    }
    int probable=s.top();
    vis.assign(V,0);
    int count=0;
    f(probable,vis,adj,count);
    if (count==V) return probable;
    return -1;
	}

};


//17. Cycle in a Directed Graph
/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex ito vertex j.*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        int v = adj.size();
        vector<int> res;
        
        queue<int> q;
        
        vector<int> indeg(v,0);
        
        for(int i=0;i<v;i++){
            for(auto x : adj[i]){
                indeg[x]++;
            }
        }
        
        for(int i=0;i<v;i++) if(indeg[i] == 0) q.push(i);
        
        while(!q.empty()){
            
            int ele = q.front();
            q.pop();
            
            res.push_back(ele);
            
            for(auto x : adj[ele]){
                indeg[x]--;
                if(indeg[x] == 0) q.push(x);
            }
        }
       if(res.size() == v) return false;
       return true;
    }
};


//18. Minimum Cost Path
/*Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).*/

class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	bool isValid(int newx,int newy,int n,int m){
	    return newx>=0 && newx<n && newy<m && newy>=0;
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
       int n = grid.size();
       int m = grid[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      
       vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
       dist[0][0]=grid[0][0];
       pq.push({grid[0][0],{0,0}});
       while(pq.empty()==false){
           auto it = pq.top();
           pq.pop();
           int dx[4]={1,-1,0,0};
           int dy[4]={0,0,1,-1};
           for(int i=0;i<4;i++){
               int new_x = it.second.first+dx[i];
               int new_y = it.second.second+dy[i];
               if(isValid(new_x,new_y,n,m)){
                   if(it.first + grid[new_x][new_y] < dist[new_x][new_y]){
                       dist[new_x][new_y] = it.first + grid[new_x][new_y];
                       pq.push({dist[new_x][new_y],{new_x,new_y}});
                   }
               }
           }
       }
       return dist[n-1][m-1];
    }
};


//19. Unit Area of largest region of 1's
/*Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).*/

class Solution
{
    public:
    int r;
    int c;
    int row[8]={-1,1,0,0,1,-1,-1,1};
    int col[8]={0,0,-1,1,1,-1,1,-1};
    bool valid(int i,int j){
    return i>=0 && i<r && j>=0 && j<c;
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        r=grid.size();
        c=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int cn = 1;
                    count++;
                    //make all 1 convert to 0
                    q.push({i,j});
                    grid[i][j]=0;
                    while(!q.empty()){
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for(int k=0;k<8;k++){
                if(valid(new_i+row[k],new_j+col[k]) && grid[new_i+row[k]][new_j+col[k]]==1){
                    grid[new_i+row[k]][new_j+col[k]]=0;
                    q.push({new_i+row[k],new_j+col[k]});
                    cn++;
                }
                        }
                    }
                    cnt = max(cnt,cn);
                }
               
            }
        }
        return cnt;
    }
};


//20. Minimum Spanning Tree
/*Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        vector<bool> vis(V,false);
        
        pq.push({0,{0,-1}}); // {wt,{node,parent}};
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            int wt = curr.first;
            int node = curr.second.first;
            int par = curr.second.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            sum += wt;
            
            for(auto it : adj[node]){
                
                int adjnode = it[0];
                int wt = it[1];
                
                if(!vis[adjnode]){
                    pq.push({wt,{adjnode,node}});
                }
            }
        }
        return sum;
    }
};


//21. Dijkstra Algorithm
/*Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.
Note: The Graph doesn't contain any negative weight edge.*/

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int v = adj.size();
        vector<int> dist(v,INT_MAX);
        dist[src] = 0;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        pq.push(src);
        
        while(!pq.empty()){
            
            auto curr = pq.top();
            pq.pop();
            
            for(auto it : adj[curr]){
                
                int u = it.first;
                int wt = it.second;
                
                if(wt + dist[curr] < dist[u]){
                    dist[u] = wt + dist[curr];
                    pq.push(u);
                }
            }
        }
        return dist;
    }
};


//22. Strongly Connected
//Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.

class Solution
{
    private:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, stack<int>& st, int node) {
        vis[node] = 1;
        
        for(const auto& it: adj[node]) {
            if(!vis[it]) {
                dfs(adj, vis, st, it);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> adj[], vector<int>& vis) {
        vis[node] = 1;
        
        for(const auto& it: adj[node]) {
            if(!vis[it]) {
                dfs2(it, adj, vis);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        
       
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, st, i);
            }
        }
        
      
        vector<int> reversedAdj[V];
        
        for(int i = 0; i < V; i++) {
            vis[i] = 0;  
            for(const auto& it : adj[i]) {
                reversedAdj[it].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()) {
            int node = st.top(); st.pop();
            
            if(!vis[node]) {
                dfs2(node, reversedAdj, vis);
                scc++;
            }
        }
        
        return scc;
    }
};


//23. Articulation Point - I
/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.
*/

class Solution {
  private:
    int timer;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &dis, vector<int> &low,
             vector<int> &vis, vector<int> &Apoints, vector<bool> &isArticulation) {
        vis[node] = 1;
        dis[node] = low[node] = timer++;
        int child = 0;
        
        for (const auto &it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                child++;
                dfs(it, node, adj, dis, low, vis, Apoints, isArticulation);
                low[node] = min(low[node], low[it]);
                
                if (low[it] >= dis[node] && parent != -1 && !isArticulation[node]) {
                    Apoints.push_back(node);
                    isArticulation[node] = true;
                }
            } else {
                low[node] = min(low[node], dis[it]);
            }
        }

        if (parent == -1 && child > 1 && !isArticulation[node]) {
            Apoints.push_back(node);
            isArticulation[node] = true;
        }
    }

  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        timer = 0;
        vector<int> dis(V, -1), low(V, -1), vis(V, 0);
        
        vector<int> Apoints;
        vector<bool> isArticulation(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, dis, low, vis, Apoints, isArticulation);
            }
        }
        
        if (Apoints.empty()) {
            return {-1};
        }

        sort(Apoints.begin(), Apoints.end()); 
        return Apoints;
    }
};


//24. Articulation Point - II
/*Given an undirected graph (not necessarily connected) with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components, or in other words, removing which increases the number of connected components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.*/
class Solution {
  private:
  int timer=1;
  void dfs(int node, int parent,vector<int>adj[],vector<int>&visited,int low[], int tn[], vector<int>&mark) {
      visited[node] = 1;
      low[node] = tn[node] = timer;
      timer++;
      int child=0;
      for(auto it:adj[node]) {
          if(it==parent) continue;
          if(!visited[it]) {
              dfs(it,node,adj,visited,low,tn,mark);
              low[node] = min(low[node],low[it]);
              if(low[it] >= tn[node] && parent!=-1) {
                  mark[node] = 1;
              }
              child++;
          }
          else {
              low[node] = min(low[node],tn[it]);
          }
      }
      if(child>1 && parent==-1) {
          mark[node] = 1;
      }
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int>visited(V,0);
        int low[V],tn[V];
        vector<int>mark(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]) {
                dfs(i,-1,adj,visited,low,tn,mark);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++) {
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};



//25. Bridge edge in a graph
//Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.
class Solution
{
    private:
    int timer = 1;
    void dfs(int node,int parent,vector<int>&visited , vector<int>adj[], int c, int d, int low[], int tin[], int& res) {
        visited[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto it: adj[node]) {
            if(it==parent) continue;
            if(visited[it] == 0) {
                dfs(it,node,visited,adj,c,d,low,tin,res);
                low[node] = min(low[it],low[node]);
                if(low[it] > tin[node]) {
                    if((it == c && node == d) || (it==d && node==c)) {
                        res = 1;
                    }
                }
            }
            else {
                low[node] = min(low[it],low[node]);
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
       vector<int>visited(V,0);
       int low[V];
       int tin[V];
       int res=0;
       for(int i=0;i<V;i++) {
           if(!visited[i]) {
               dfs(i,-1,visited,adj,c,d,low,tin,res);
           }
       }
       return res;
    }


//26. Strongly connected component (Tarjans's Algo)
/* Given a Directed Graph with V vertices and E edges, Find the members of strongly connected components in the graph.
Note - Sort both the individual components and array of the components. */
class Solution
{
	public:
	void dfs(int node, vector<int>& visited, vector<int>adj[],stack<int>& st) {
        visited[node] = 1;
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj,st);
            }
        }
        st.push(node);
    }
     void revdfs(int node, vector<int>& visited, vector<int>adj[], vector<int>& res) {
        visited[node] = 1;
        res.push_back(node);
        for(auto it: adj[node]) {
            if(!visited[it]) {
                revdfs(it,visited,adj,res);
            }
        }
        
    }
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
       vector<int>visited(V,0);
       stack<int>st;
       for(int i=0;i<V;i++) {
           if(!visited[i]) {
               dfs(i,visited,adj,st);
           }
       }
       
       vector<int>transpose[V];
       for(int i=0;i<V;i++) {
           visited[i] = 0;
           for(auto it: adj[i]) {
               transpose[it].push_back(i);
           }
       }
       
       vector<int>res;
       vector<vector<int>>ans;
       while(!st.empty()) {
           int top = st.top();
           st.pop();
           if(!visited[top]) {
               revdfs(top,visited,transpose,res);
                sort(res.begin(),res.end());
                ans.push_back(res);
           }
           res.clear();
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};


