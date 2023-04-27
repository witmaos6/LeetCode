class Solution {
public:
    int pivotInteger(int n)
    {
        int OnePivot = (n * (n + 1)) / 2;
        int PivotN = n;
        
        while(OnePivot > PivotN)
        {
            OnePivot -= n;
            n--;
            PivotN += n;
        }
        
        if(OnePivot == PivotN)
        {
            return n;
        }
        
        return -1;
    }
};