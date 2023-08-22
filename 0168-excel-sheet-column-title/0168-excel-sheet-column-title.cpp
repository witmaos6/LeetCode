class Solution {
    const int Coefficient = 26;
public:
    string convertToTitle(int columnNumber)
    {
        string Result;
        columnNumber--;
        
        while(columnNumber >= 0)
        {
            Result += ('A' + (columnNumber % Coefficient));
            columnNumber /= Coefficient;
            columnNumber--;
        }
        reverse(Result.begin(), Result.end());
        return Result;
    }
};