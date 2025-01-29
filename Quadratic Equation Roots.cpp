/* Given a quadratic equation ax2 + bx + c = 0, find its roots. If the roots are imaginary, return only one integer -1. Always return the roots as the greatest integers less than or equal to the actual roots, with the maximum root first followed by the minimum root.

Note: If roots are imaginary, the generated output will display "Imaginary".*/

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        vector<int> ans;
        int an = b*b-4*a*c;
        if(an<0) return {-1};
       // if(an==0) return {-b/(2*a),-b/(2*a)};
        int one = (floor)((-b+sqrt(an))/(2*a));
        int two = (floor)((-b-sqrt(an))/(2*a));
        ans.push_back(max(one,two));
        ans.push_back(min(one,two));
        return ans;
        // code here
    }
};
