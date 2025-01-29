// Q. Digits In Factorial

class Solution{
    public:
    int digitsInFactorial(int N)
    { if(N==1) return 1;
    double digit=0;
    for(int i=2;i<=N;i++)
    {
        digit+=log10(i);
    }
    return floor(digit) + 1;
        // code here
    }
};


// Q. Primality Test
class Solution{
    public:
        bool isPrime(int N)
    {
       if(N==1) 
       return false;
      
       for(int i = 2; i<=sqrt(N); i++)
       if (N % i == 0) 
        return false;
       
     return true;
        //Your code here
        
    }

};


// Q. Exactly 3 Divisors
 class Solution{
    public:
    bool isPrime(int n){
        if(n<=1) return false;
        if(n==2) return true;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i == 0) return false;

        }
        return true;
    }
    int exactly3Divisors(int N)
    {   int count=0;
      for(int i=1;i*i<=N;i++)
      {
        if(isPrime(i)) count++;}
      return count;
        //Your code here
    }
};


// Q. GP Term
// Given the first 2 terms A and B of a Geometric Series. The task is to find the Nth term of the series.
class Solution{
    public:
        //Complete this function
    double termOfGP(int A,int B,int N)
    {
        double r = double(B)/double(A);
        double last = A*pow(r,N-1);
        return last;
    }
};


// Q.Addition Under Modulo
//Given two numbers a and b, find the sum of a and b. Since the sum can be very large, find the sum modulo 109+7.
class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
        long long M=1000000007;
        return ((a%M)+(b%M))%M;
        // code here
    }
};


// Q.Multiplication Under Modulo
// You are given two numbers a and b. You need to find the multiplication of a and b under modulo M (M as 109+7).
class Solution{
    public:
        int multiplicationUnderModulo(long long a,long long b)
    {
        long long M=1000000007;
        return ((a%M)*(b%M))%M;
        //your code here
    }
};


// Q.Modular Inverse
//  Given two integers ‘a’ and ‘m’. The task is to find the smallest modular multiplicative inverse of ‘a’ under modulo ‘m’. if it does not exist then return -1.
class Solution{
    public:
    //Complete this function
    int modInverse(int a, int m)
    {
        for(int i=1; i<=m; i++)
        if((a*i)%m==1) return i;
            
        return -1;
        //Your code here
    }
};
