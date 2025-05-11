class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        for(int i = 0; i < N - 2; i++)
        {
            if(IsOddNumber(arr[i]) && IsOddNumber(arr[i + 1]) && IsOddNumber(arr[i + 2]))
                return true;
        }
        return false;
    }

private:
    bool IsOddNumber(const int Num)
    {
        if((Num & 1) == 1)
        {
            return true;
        }
        return false;
    }
};