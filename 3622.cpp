class Solution {
public:
    int sum_of_digit(int n){
        if (n==0) return 0;
        return (n%10)+sum_of_digit(n/10);
    }
     int product_of_digit(int n){
        if (n<10) return n;
        return (n%10)* product_of_digit(n/10);
    }
    bool checkDivisibility(int n) {
    if (n%(sum_of_digit(n)+ product_of_digit(n))==0)
    { 
        return true;
        }
    return false;
        
    }
};
