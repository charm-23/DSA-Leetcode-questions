class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits; 
        while(n){
            int digit= n%10;
            digits.push_back(digit); 
            n=n/10;
        }
        sort(digits.rbegin(), digits.rend());
        return digits[0]* digits[1];
    }
};