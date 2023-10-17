class Solution {
    const int NoChild = -1;
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild)
    {
        vector<int> Table(n);
        for(int i = 0; i < n; i++)
        {
            if(leftChild[i] != NoChild)
            {
                Table[leftChild[i]]++;
            }
            if(rightChild[i] != NoChild)
            {
                Table[rightChild[i]]++;
            }
        }
        
        int Root = -1;
        for(int i = 0; i < n; i++)
        {
            if(Table[i] == 0)
            {
                if(Root == -1)
                {
                    Root = i;
                }
                else
                {
                    return false;
                }
            }
        }
        if(Root == -1)
        {
            return false;
        }
        
        vector<bool> Visited(n, false);
        queue<int> BFS;
        BFS.push(Root);
        
        while(!BFS.empty())
        {
            int Node = BFS.front();
            BFS.pop();
            
            if(Visited[Node])
            {
                return false;
            }
            Visited[Node] = true;
            
            if(leftChild[Node] != NoChild)
            {
                BFS.push(leftChild[Node]);
            }
            if(rightChild[Node] != NoChild)
            {
                BFS.push(rightChild[Node]);
            }
        }
        
        for(bool Visit : Visited)
        {
            if(!Visit)
            {
                return false;
            }
        }
        return true;
    }
};