class Solution {
public:
    int helper(int n , int k ) // sovled using 0 based index . 
    {
        if(n == 1 ) 
         return 0 ;  // 1 student left then return winer 

        return  (helper(n-1,k)+k)%n; // n-1 solution k poistion move then its answer to n 
    }
    int findTheWinner(int n, int k) {

        return helper(n,k)+1;  // 1 based indeex answer return 
        
    }
};