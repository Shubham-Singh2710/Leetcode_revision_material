class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;
        int count=0;
        for(int i=1; ;i++){
            if(i%2!=0){
             sumodd+=i;
             count++;
            }
             
            if(count==n)
            break;
        
        }

       count=0;
       for(int i=2; ;i++){
            if(i%2==0 ){
                sumeven+=i;
                count++;
    }

      if(count==n)
            break;
       
       }
        return gcd(sumodd,sumeven);
    }
};