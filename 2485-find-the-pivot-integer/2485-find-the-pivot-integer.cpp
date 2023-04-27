class Solution {
public:
    int pivotInteger(int n)
    {
        int OnePivot = 1;
        int PivotN = (n * (n + 1)) / 2;
        
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