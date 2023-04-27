class Solution {
public:
    int pivotInteger(int n)
    {
        int OnePivot = 1;
        int PivotN = 0;
        
        for(int i = 1; i <= n; i++)
        {
            PivotN += i;
        }
        
        int Pivot = 2;
        while(OnePivot < PivotN)
        {
            OnePivot += Pivot;
            PivotN -= Pivot - 1;
            Pivot++;
        }
        
        if(OnePivot == PivotN)
        {
            return Pivot - 1;
        }
        return -1;
    }
};