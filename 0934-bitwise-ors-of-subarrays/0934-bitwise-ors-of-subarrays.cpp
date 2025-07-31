class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        unordered_set<int> Result;
        unordered_set<int> Curr;

        for(int& Num : arr)
        {
            unordered_set<int> Next;

            Next.insert(Num);
            for(int C : Curr)
            {
                Next.insert(Num | C);
            }

            Result.insert(Next.begin(), Next.end());

            Curr = Next;
        }
        return Result.size();
    }
};