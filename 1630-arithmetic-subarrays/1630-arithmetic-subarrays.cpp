class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r)
    {
        const int M = static_cast<int>(l.size());
        
        vector<bool> Arithmetic;
        for(int i = 0; i < M; i++)
        {
            vector<int> Temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
            
            if(Temp.size() >= 3)
            {
                if(bIsArithmetic(Temp, r[i] - l[i] + 1))
                {
                    Arithmetic.push_back(true);
                }
                else
                {
                    Arithmetic.push_back(false);
                }
            }
            else 
            {
                Arithmetic.push_back(true);
            }
        }
        
        return Arithmetic;
    }
    
private:
    bool bIsArithmetic(vector<int>& Array, int Size)
    {
        sort(Array.begin(), Array.end());
                
        int Diff = Array[1] - Array[0];
        
        for(int i = 2; i < Size; i++)
        {
            if(Array[i] - Array[i - 1] != Diff)
                return false;
        }
        
        return true;
    }
};