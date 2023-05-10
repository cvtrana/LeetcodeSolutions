class Solution 
{
    
public:
    int findNthDigit(int n) 
    {
        
        long base = 9, digits = 1;
        while (n - base * digits > 0)
        {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

  
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};