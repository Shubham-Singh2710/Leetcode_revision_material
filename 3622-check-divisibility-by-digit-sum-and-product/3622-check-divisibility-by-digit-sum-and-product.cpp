class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int prod=1;
        string str= to_string(n);
        for(int i=0;i<str.size();i++){
            int digit=str[i]-'0';
             sum=sum+digit;
            prod=prod*digit;
        }
            int total=sum+prod;
            if(n%total==0){
                return true;
            
        }
        return false;
    }
};