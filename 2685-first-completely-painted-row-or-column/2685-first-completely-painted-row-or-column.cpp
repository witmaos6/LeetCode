class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        const int ArrSize = static_cast<int>(arr.size());
        const int Rows = static_cast<int>(mat.size());
        const int Cols = static_cast<int>(mat[0].size());

        unordered_map<int, int> NumToIndex;
        for(int i = 0; i < ArrSize; i++)
        {
            NumToIndex[arr[i]] = i;
        }
        
        int MinIndex = ArrSize - 1;
        for(int Row = 0; Row < Rows; Row++)
        {
            int MaxIndex = 0;
            for(int Col = 0; Col < Cols; Col++)
            {
                int Num = mat[Row][Col];
                MaxIndex = max(MaxIndex, NumToIndex[Num]);
            }
            MinIndex = min(MinIndex, MaxIndex);
        }

        for(int Col = 0; Col < Cols; Col++)
        {
            int MaxIndex = 0;
            for(int Row = 0; Row < Rows; Row++)
            {
                int Num = mat[Row][Col];
                MaxIndex = max(MaxIndex, NumToIndex[Num]);
            }

            MinIndex = min(MinIndex, MaxIndex);
        }

        return MinIndex;
    }
};