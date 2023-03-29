class Solution {
public:
    int reverse(int x) {
        int reverseNo = 0;
        
        // To handle negative cases condition x!=0 , not x>0
        while(x!=0){
            int lastDigit = x%10;

        //If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
            if(reverseNo>INT_MAX/10 || reverseNo<INT_MIN/10){
                return 0;
            }

            reverseNo = reverseNo *10 + lastDigit;
            x=x/10;
        }
        return reverseNo;
    }
};