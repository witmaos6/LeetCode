class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        const int M = static_cast<int>(l.size());
        
        vector<bool> Arithmetic(M);
        
        for(int i = 0; i < M; i++)
        {
            int Size = r[i] - l[i] + 1;
            if(Size >= 3)
            {
                if(bIsArithmetic(nums, l[i], r[i]))
                {
                    Arithmetic[i] = true;
                }
                else
                {
                    Arithmetic[i] = false;
                }
            }
            else 
            {
                Arithmetic[i] = true;
            }
        }
        
        return Arithmetic;
    }
    
private:
    bool bIsArithmetic(vector<int>& Array, int Begin, int End)
    {
        pair<int, int> MinMaxElement = GetMinMaxElement(Array, Begin, End);
        int MinInt = MinMaxElement.first;
        int MaxInt = MinMaxElement.second;
        
        if(MinInt == MaxInt)
            return true;
        
        if((MaxInt - MinInt) % (End - Begin) != 0)
            return false;
        
        int Diff = (MaxInt - MinInt) / (End - Begin);
        
        vector<bool> Temp(End - Begin + 1);
        
        for(int i = Begin; i <= End; i++)
        {
            if((Array[i] - MinInt) % Diff != 0)
                return false;
            
            int Index = (Array[i] - MinInt) / Diff;
            
            if(Temp[Index])
                return false;
            
            Temp[Index] = true;
        }
        
        return true;
    }
    
    pair<int, int> GetMinMaxElement(const vector<int>& Array, int Begin, int End)
    {
        int MinElement = INT_MAX;
        int MaxElement = INT_MIN;
        
        for(int i = Begin; i <= End; i++)
        {
            MinElement = min(MinElement, Array[i]);
            MaxElement = max(MaxElement, Array[i]);
        }
        
        return {MinElement, MaxElement};
    }
};