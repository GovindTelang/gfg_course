//Given a positive integer N. The task is to find factorial of N.
class Solution{
    public:
        // Complete this function
    long long factorial(int N) {
        if(N==0||N==1) return 1;
        return N*factorial(N-1);
        // Your code here
    }

};
