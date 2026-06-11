class Solution {
    typedef pair<int, int> Person;
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<Person> Table(n + 1);

        for(vector<int>& person : trust)
        {
            Table[person[0]].first++;
            Table[person[1]].second++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(Table[i].first == 0 && Table[i].second == n - 1)
            {
                return i;
            }
        }

        return -1;
    }
};