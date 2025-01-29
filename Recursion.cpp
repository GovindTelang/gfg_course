//Q1. Power Of Numbers
// Given a number n, find the value of n raised to the power of its own reverse.
// Note: The result will always fit into a 32-bit signed integer.

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int N,int R)
    {   long long mod =1e9+7;
        if(R==0)  return 1;
        
        if(R==1)  return N%mod;
        
        long long ans = 1;
        long long k = power(N, R/2)%mod;
        if(R%2){
            ans = (ans*N) % mod;
        }
        return (ans*((k*k)%mod)%mod);
    }
       //Your code here
};


//Q2. Power Using Recursion
//You are given two numbers n and p. You need to find np.

class Solution{
  public:
    //Complete this function
    int RecursivePower(int n,int p)
    {   if ( p == 0 ) return 1;
        if ( n == 1 ) return 1;
        int temp = RecursivePower(n,p/2);
        if (p % 2 == 0) return (temp*temp);
        return (temp*temp*n);
        //Your code here
    }
};


//Q3. Fibonacci Using Recursion
// You are given a number n. You need to find nth Fibonacci number.
// F(n)=F(n-1)+F(n-2); where F(1)=1 and F(2)=1

class Solution{
    public:
    //Complete this function
    int fibonacci(int n)
    {   if ( n == 0 || n == 1)  return n;
        return fibonacci(n-1) + fibonacci(n-2);
        //Your code here
    }
};



//Q4. Print 1 To N Without Loop
class Solution{
    public:
    //Complete this function
    void printNos(int N)
    { 
        if(N > 0)
	{
		printNos(N - 1);
		cout << N << " ";
	}
	return;
        //Your code here
    }
};


//Q5. Sum of Digits of a Number
class Solution{
  public:
    // Complete this function
    int sumOfDigits(int n)
    {
        if ( n < 10 ) return n;
        return (n%10)+sumOfDigits(n/10);
        //Your code here
    }
};


//Q6. Count Total Digits in a Number
class Solution{
  public:
    //Complete this function
    int countDigits(int n)
    {
        if ( n<10 ) return 1;
        return 1 + countDigits(n/10);
       //Your code here
    }
};


//Q7. Power Set Using Recursion

//Function to return the lexicographically sorted power-set of the string.
 void solve(string &s, int index, string current, vector<string> &result) {
        // Base case: if we've reached the end of the string
        if (index == s.length()) {
            result.push_back(current);
            return;
        }
        
        // Exclude the current character and move to the next character
        solve(s, index + 1, current, result);
        
        // Include the current character and move to the next character
        solve(s, index + 1, current + s[index], result);
    }

    // Function to return the power set
   
        
vector <string> powerSet(string s)
{
     vector<string> result;
        string current = "";
        
        // Start generating power set from index 0
        solve(s, 0, current, result);
        
        // Sort the result (required by some GFG problems)
        sort(result.begin(), result.end());
        
        // Remove the empty string as GFG typically expects non-empty subsets
        //result.erase(result.begin());
        
        return result;
   //Your code here
}


//Q8. Tower Of Hanoi
/*In the Tower of Hanoi puzzle, you are given n disks stacked in ascending order (smallest at the top) on the first of three rods. The goal is to move all disks to the third rod following two rules: only one disk can be moved at a time, and a disk can only be placed on top of a larger disk. Given the number of disks n and three rods labeled as from, to, and aux (starting rod, target rod, and auxiliary rod, respectively),  returns the total number of moves needed to transfer all disks from the starting rod to the target rod.*/
class Solution {
  public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int n, int from, int to, int aux) {
        //note you need to add a base case otherwise you will be caught in a infinite loop
        if(n==1){
            cout<<"move disk "<<1<<" from rod "<<from<< " to rod "<< to <<endl;
            return 1;
        }
        long long count = 0;
        count = toh(n-1,from,aux,to);
        cout<<"move disk "<<n<<" from rod "<<from<< " to rod "<< to <<endl;
        count++;
        count += toh(n-1,aux,to,from);
        return count;
    }
};


//Q9. Digital Root
//You are given a number n. You need to find the digital root of n. DigitalRoot of a number is the recursive sum of its digits until we get a single digit number.

class Solution{
  public:
    //Complete this function
    int digitalRoot(int n)
    { 
        if (n<10)
        return n;
        return digitalRoot(n%10 + digitalRoot(n/10));
        //Your code here
    }
};


//Q10. Josephus problem
/*A total of n people are standing in a circle, and you are one of them playing a game. Starting from a person, k persons will be counted in order along the circle, and the kth person will be killed. Then the next k persons will be counted along the circle, and again the kth person will be killed. This cycle will continue until only a single person is left in the circle.
If there are 5 people in the circle in the order A, B, C, D, and E, you will choose k=3. Starting from A, you will count A, B and C. C will be the 3rd person and will be killed. Then you will continue counting from D, E and then A. A will be third person and will be killed. 
You will be given an array where the first element is the first person from whom the counting will start and the subsequent order of the people. You want to be the last one standing. Determine the index at which you should stand to survive the game. Return an integer denoting safe position.
Input: n = 5, k = 3
Output: 4
Explanation: There are 5 persons so skipping 2 person i.e 3rd person will be killed. Thus the safe position is 4.*/

class Solution
{
    public:
    int josephus(int n, int k)
    {
        if(n==1) return 1;
        return (josephus(n - 1, k) + k-1) % n + 1;
       //Your code here
    }
};


//Q11. Lucky Numbers
/*Lucky numbers are subset of integers. Process of arriving at lucky numbers is:
Take the set of integers 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.
You are given a number N, you need to tell whether the number is lucky or not. If the number is lucky return 1 otherwise 0.*/

class Solution{
public:
    int i=2;
    bool isLucky(int n) {
        if(i>n) return 1;
        if(n%i == 0) return 0;
        
        int nextpos=n-(n/i);
        i++;
       return isLucky(nextpos);
        
        // code here
    }
};


//Q12.Possible Words From Phone Digits
//Given a keypad as shown in the diagram, and an array arr[ ], your task is to list all possible words in any order which can be generated by pressing numbers from array.

class Solution
{
    public:
    void solve(unordered_map<char,string> &mp,int i,string temp,string &digits,vector<string> &ans){
        if(i==digits.size()){
            ans.push_back(temp);
            return;
        }
        string str = mp[digits[i]];
        for(int x=0;x<str.length();x++){
            temp.push_back(str[x]);
            solve(mp,i+1,temp,digits,ans);
            temp.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
      string st = "";
      if(N==0) return {};
      for(int i=0;i<N;i++){
          st += to_string(a[i]);
      }
      unordered_map<char,string> mp;
      mp['2'] = "abc";
      mp['3'] = "def";
      mp['4'] = "ghi";
      mp['5'] = "jkl";
      mp['6'] = "mno";
      mp['7'] = "pqrs";
      mp['8'] = "tuv";
      mp['9'] = "wxyz";
      vector<string> ans;
      string temp;
      solve(mp,0,temp,st,ans);
      return ans;  
        //Your code here
    }
};

