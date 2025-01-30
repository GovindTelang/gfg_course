//1. Multiply the matrices

class Solution
{   
    public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        int c1 = A[0].size();
        int r2 = B.size();
        if(c1!=r2) return {{-1}};
        int r1 = A.size();
        int c2 = B[0].size();
        vector<vector<int>> C(r1,vector<int>(c2,0));
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
                C[i][j]=0;
                for(int k=0;k<r2;k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        return C;
        // code here
    }
};


//2.Print Matrix in snake Pattern

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {  vector<int> ans;
       for(int i=0;i<matrix.size();i++){
           if(i%2 == 0) {
               for(int j=0;j<matrix[0].size();j++){
                  ans.push_back(matrix[i][j]);
               }
           }
           else{
               for(int j=matrix[0].size()-1;j>=0;j--){
                  ans.push_back(matrix[i][j]);
               }
           }
       }
       return ans;
        // code here
    }
};


//3. Matrix Boundary Traversal

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> ans;
        if(n==1){
            for(int i=0;i<m;i++){
            ans.push_back(matrix[0][i]);
          }
        }
     else if(m==1){
            for(int i=0;i<n;i++){
              ans.push_back(matrix[i][0]);
            }
     }
     else{
         for(int i=0;i<m;i++){
             ans.push_back(matrix[0][i]);
         }
         for(int i=1;i<n;i++){
             ans.push_back(matrix[i][m-1]);
         }
         for(int i=m-2;i>=0;i--){
             ans.push_back(matrix[n-1][i]);
         }
         for(int i=n-2;i>=1;i--){
             ans.push_back(matrix[i][0]);
         }
     }
     return ans;
        // code here
    }
};


//4. Spirally traversing a matrix

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
    int r=matrix.size();
    int c=matrix[0].size();
    vector<int> ans;
    int top=0,bottom=r-1;
    int left=0,right=c-1;
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
           ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
        ans.push_back(matrix[i][left]);
        }
        left++;
        }
    }
    return ans;
    }
};


//5.Search in a sorted Matrix
/*Given a strictly sorted 2D matrix mat[][] of size n x m and a number x. Find whether the number x is present in the matrix or not.
Note: In a strictly sorted matrix, each row is sorted in strictly increasing order, and the first element of the ith row (i!=0) is greater than the last element of the (i-1)th row.*/

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
     int n = mat.size(), m = mat[0].size();
     int low = 0;
     int high = n*m-1;
     while(low<=high){
         int mid = low + (high-low)/2;
         if(mat[mid/m][mid%m]<x) low = mid + 1;
         else if(mat[mid/m][mid%m]>x) high = mid - 1;
         else return true;
     }
     return false;
    }
};



//6. Determinant of a Matrix

class Solution
{   
    public:
    // Function to get the cofactor matrix
void getCofactor(vector<vector<int>> &matrix, vector<vector<int>> &temp, int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copying into temporary matrix only those elements
            // which are not in given row and column
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
    int D = 0; // Initialize result

    // Base case : if matrix contains single element
    if (n == 1)
        return matrix[0][0];

    vector<vector<int>> temp(n, vector<int>(n)); // To store cofactors

    int sign = 1; // To store sign multiplier

    // Iterate for each element of first row
    for (int f = 0; f < n; f++) {
        // Getting Cofactor of matrix[0][f]
        getCofactor(matrix, temp, 0, f, n);
        D += sign * matrix[0][f] * determinantOfMatrix(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
        
    }
};


//7. Boolean Matrix
/*Given a boolean matrix mat[], where each cell contains either 0 or 1, modify it such that if a matrix cell matrix[i][j] is 1 then all the cells in its ith row and jth column will become 1.*/

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        int row[R]={0};
        int col[C]={0};
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(matrix[i][j]==1){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
          for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=1;
                }
            }
          }
          
        // code here 
    }
};



//8. Make Matrix Beautiful
/*A beautiful matrix is a matrix in which the sum of elements in each row and column is equal. Given a square matrix mat[][]. Find the minimum number of operation(s) that are required to make the matrix beautiful. In one operation you can increment the value of any one cell by 1.*/



class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int maxcol=0;
        int maxrow=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                count += matrix[i][j];
            }
            maxrow=max(maxrow,count);
        }
        for(int j=0;j<n;j++){
            int count=0;
            for(int i=0;i<n;i++){
                count += matrix[i][j];
            }
            maxcol=max(maxcol,count);
        }
        int res=0;
        res=max(maxrow,maxcol);
        int x=res;
        int ans=0;
        if(res == maxrow){
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                   count += matrix[j][i];
                }
                ans+=(res-count);
            }
        }
        else{
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                  count += matrix[i][j];
                }
                ans+=(res-count);
            }
        }
        return ans;
        // code here 
    } 
};
