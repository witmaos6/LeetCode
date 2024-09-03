class Solution {
public:
    int getLucky(string s, int k)
    {
        vector<int> StoInt;
        for(char C : s)
        {
            int CtoInt = (C - 'a') + 1;
            
            SetDigitVector(StoInt, CtoInt);
        }
        
        int Result = 0;
        while(k > 0)
        {
            Result = 0;
            for(int Num : StoInt)
            {
                Result += Num;
            }
            
            StoInt.clear();
            SetDigitVector(StoInt, Result);
            k--;
        }
        
        return Result;
    }
    
private:
    void SetDigitVector(vector<int>& V, int Num)
    {
        while(Num > 0)
        {
            V.push_back(Num % 10);
            Num /= 10;
        }
    }
};