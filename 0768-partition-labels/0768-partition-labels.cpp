class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<vector<int>> Memo(26, vector<int>(2));
        for(vector<int>& Arr : Memo)
        {
            Arr[0] = INT_MAX;
            Arr[1] = INT_MIN;
        }

        const int N = static_cast<int>(s.size());
        for(int i = 0; i < N; i++)
        {
            int Index = s[i] - 'a';
            Memo[Index][0] = min(Memo[Index][0], i);
            Memo[Index][1] = max(Memo[Index][1], i);
        }

        vector<pair<int, int>> P;
        for(vector<int>& Arr : Memo)
        {
            if(Arr[0] != INT_MAX)
            {
                P.push_back({Arr[0], Arr[1]});
            }
        }
        sort(P.begin(), P.end());

        int Begin = P[0].first;
        int End = P[0].second;
        vector<int> Result;

        const int M = static_cast<int>(P.size());
        for(int i = 1; i < M; i++)
        {
            if(P[i].first <= End)
            {
                End = max(End, P[i].second);
            }
            else
            {
                Result.push_back(End - Begin + 1);
                Begin = P[i].first;
                End = P[i].second;
            }
        }
        Result.push_back(End - Begin + 1);
        return Result;
    }
};