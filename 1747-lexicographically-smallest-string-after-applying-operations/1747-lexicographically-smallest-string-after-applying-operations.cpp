class Solution {
public:
    string findLexSmallestString(string s, int a, int b)
    {
        unordered_set<string> Visited;
        string Smallest = s;
        queue<string> Q;
        Q.push(s);
        Visited.insert(s);

        while(!Q.empty())
        {
            string Curr = Q.front();
            Q.pop();

            if(Curr < Smallest)
                Smallest = Curr;

            string Added = Curr;
            for(int i = 1; i < Added.size(); i += 2)
            {
                Added[i] = ((Added[i] - '0' + a) % 10) + '0';
            }
            if(!Visited.count(Added))
            {
                Visited.insert(Added);
                Q.push(Added);
            }

            string Rotated = Curr.substr(Curr.size() - b) + Curr.substr(0, Curr.size() - b);
            if(!Visited.count(Rotated))
            {
                Visited.insert(Rotated);
                Q.push(Rotated);
            }
        }
        return Smallest;
    }
};