class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int Count = 0;
        const int RowSize = static_cast<int>(matrix.size());
        const int ColSize = static_cast<int>(matrix[0].size());
        
        for(int i = 0; i < RowSize; i++)
        {
            vector<int> PrefixSum(ColSize);
            
            for(int Row = i; Row < RowSize; Row++)
            {
                for(int Col = 0; Col < ColSize; Col++)
                {
                    PrefixSum[Col] += matrix[Row][Col];
                }
                Count += SubArrSum(PrefixSum, target);
            }
        }
        return Count;
    }
    
private:
    int SubArrSum(vector<int>& Nums, int Target)
    {
        const int N = static_cast<int>(Nums.size());
        int Count = 0;
        int Sum = 0;
        map<int, int> Table;
        
        for(int i = 0; i < N; i++)
        {
            Sum += Nums[i];
            if(Sum == Target)
            {
                Count++;
            }
            if(Table.find(Sum - Target) != Table.end())
            {
                Count += Table[Sum - Target];
            }
            Table[Sum]++;
        }
        return Count;
    }
};