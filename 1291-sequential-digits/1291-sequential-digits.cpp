class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> Result;

        for(int Length = 2; Length <= 9; Length++)
        {
            for(int First = 1; First + Length <= 10; First++)
            {
                int Value = 0;

                for(int Digit = First; Digit < First + Length; Digit++)
                {
                    Value = Value * 10 + Digit;
                }

                if(Value >= low && Value <= high)
                {
                    Result.push_back(Value);
                }
            }
        }
        return Result;
    }
};