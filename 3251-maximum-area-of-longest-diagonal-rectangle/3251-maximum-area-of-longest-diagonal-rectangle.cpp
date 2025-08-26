class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions)
    {
        pair<int, int> MaxLength = {0,0};
        int MaxDiagonal = 0;

        for(vector<int>& Dimension : dimensions)
        {
            int Diagonal = (Dimension[0] * Dimension[0]) + (Dimension[1] * Dimension[1]);
            if(MaxDiagonal <= Diagonal)
            {
                if(MaxDiagonal == Diagonal)
                {
                    if(MaxLength.first * MaxLength.second < Dimension[0] * Dimension[1])
                    {
                        MaxDiagonal = Diagonal;
                        MaxLength = {Dimension[0], Dimension[1]};
                    }
                }
                else
                {
                    MaxDiagonal = Diagonal;
                    MaxLength = {Dimension[0], Dimension[1]};
                }
            }
        }

        return MaxLength.first * MaxLength.second;
    }
};