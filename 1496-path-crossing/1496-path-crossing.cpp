typedef pair<int, int> Point;
class Solution {
public:
    bool isPathCrossing(string path)
    {
        Point Begin = {0,0};
        set<Point> Table;
        Table.insert(Begin);
        
        for(char C : path)
        {
            if(C == 'N')
            {
                Begin.second++;
            }
            else if(C == 'S')
            {
                Begin.second--;
            }
            else if(C == 'W')
            {
                Begin.first--;
            }
            else if(C == 'E')
            {
                Begin.first++;
            }
            
            if(Table.find(Begin) != Table.end())
            {
                return true;
            }
            Table.insert(Begin);
        }
        
        return false;
    }
};