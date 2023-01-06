class Solution {
public:
    int trailingZeroes(int n) {
//         int count=0;
//         if(n<=4) return 0;
//         if(n==5) return 1;
      
//         for(int i=1; i<=n; i++){
//             if(i%5==0) {
//                 count++;
//             }else if(i%5==0 && i%2==0){
//                 count++;
//             }
            
           
//         }
//         return count;
        
         int result = 0;
    for(long long i=5; n/i>0; i*=5){
        result += (n/i);
    }
    return result;
    }
};