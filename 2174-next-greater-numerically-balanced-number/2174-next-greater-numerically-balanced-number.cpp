class Solution {
public:
    int nextBeautifulNumber(int n)
    {
        vector<int> List;
        vector<int> Count(10);
        Generate(0, Count, List);
        sort(List.begin(), List.end());
        for(int& Num : List)
        {
            if(Num > n)
                return Num;
        }
        return -1;
    }

private:
    void Generate(long Num, vector<int>& Count, vector<int>& List)
    {
        if(Num > 0 && IsBalanced(Count))
        {
            List.push_back((int)Num);
        }
        if(Num > 1224444)
            return;

        for(int D = 1; D <= 7; D++)
        {
            if(Count[D] < D)
            {
                Count[D]++;
                Generate(Num * 10 + D, Count, List);
                Count[D]--;
            }
        }
    }

    bool IsBalanced(const vector<int>& Count)
    {
        for(int D = 1; D <= 7; D++)
        {
            if(Count[D] != 0 && Count[D] != D)
            {
                return false;
            }
        }
        return true;
    }
};