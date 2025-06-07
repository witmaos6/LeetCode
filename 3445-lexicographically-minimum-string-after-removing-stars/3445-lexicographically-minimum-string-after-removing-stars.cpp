class Solution {
public:
    string clearStars(string s)
    {
        const int N = static_cast<int>(s.size());
        priority_queue<char, vector<char>, greater<char>> MinHeap;
        unordered_map<char, vector<int>> Table;
        vector<bool> Visited(N, true);

        for(int i = 0; i < N; i++)
        {
            if(s[i] == '*')
            {
                char Temp = MinHeap.top();
                MinHeap.pop();

                int Last = Table[Temp].back();
                Table[Temp].pop_back();

                Visited[i] = false;
                Visited[Last] = false;
            }
            else
            {
                MinHeap.push(s[i]);
                Table[s[i]].push_back(i);
            }
        }

        string Result;
        for(int i = 0; i < N; i++)
        {
            if(Visited[i])
            {
                Result += s[i];
            }
        }
        return Result;
    }
};