class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int Left = 1;
        int Right = 100000;
        
        while(Left < Right)
        {
            int Mid = (Left + Right) / 2;
            if(IsValid(quantities, n, Mid))
            {
                Left = Mid + 1;
            }
            else
            {
                Right = Mid;
            }
        }
        
        return Left;
    }
    
private:
    bool IsValid(const vector<int>& Quantities, int N, int M)
    {
        int Sum = 0;
        for(const int& Quantity : Quantities)
        {
            Sum += (Quantity + M - 1) / M;
        }
        
        return Sum > N;
    }
};