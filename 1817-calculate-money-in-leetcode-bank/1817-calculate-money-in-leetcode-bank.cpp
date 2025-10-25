class Solution {
public:
    int totalMoney(int n) 
    {
        int Money = 1;
        int Total = 0;
        while(n > 0)
        {
            int LastMoney = (n >= 7) ? Money + 6 : n - 1 + Money;
            int Week = (n >= 7) ? 7 : n;
            Total += (Money + LastMoney) * Week / 2;
            Money++;
            n -= 7;
        }
        return Total;
    }
};