class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        
        int len = str.length();
        int i=0;
        int sign = 1;
        
        while( i<len && str[i] == ' ')
            i++;
        
        if(i==len) return 0;
        
        if(str[i] == '-'){
            sign = -1;
            i++;
        }
        else if(str[i] == '+')
            i++;
        
       
        
        /**
            '0' = 48
            '1' = 49
            .
            .
            .
            .
            '9' = 57
        **/
        long int res = 0;
        while(str[i] >= '0' && str[i] <= '9'){
            int a = str[i] - '0';
            if(res <= INT_MIN || res >= INT_MAX)
                break;
            res = res*10 + a;
            i++;
        }
        
        if(sign == -1)
            res = -1 * res;
        if(res <= INT_MIN)
            return INT_MIN;
        if(res >= INT_MAX)
            return INT_MAX;
        
        return (int)res;
    }
};