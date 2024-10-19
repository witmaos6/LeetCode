class Solution {
    const char Begin = '0';
public:
    char findKthBit(int n, int k)
    {
        string BinaryStr(1, Begin);
        
        for(int i = 0; i < n; ++i)
        {
            string InvertReverseStr = MakeInvertReverseStr(BinaryStr);
            BinaryStr += '1' + InvertReverseStr;
        }
        
        return BinaryStr[k - 1];
    }
    
private:
    string MakeInvertReverseStr(const string& Str)
    {
        const int N = static_cast<int>(Str.size());
        string Result(N, '0');
        
        for(int i = 0; i < N; ++i)
        {
            if(Str[i] == '0')
            {
                Result[i] = '1';
            }
        }
        
        reverse(Result.begin(), Result.end());
        return Result;
    }
};