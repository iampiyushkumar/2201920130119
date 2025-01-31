class Solution {
public:
int rows[4]={-1,1,0,0};
int cols[4]={0,0,-1,1};
bool valid(int i, int j, int n)
{
    return i>=0&&j>=0&&i<n&&j<n;
}
  void bfs(vector<vector<int>>&grid,int i, int j, unordered_map<int,int>&mp, int index)
  {
    int n=grid.size();
      queue<pair<int,int>>q;
      int size=1;
      q.push({i,j});
     while(!q.empty())
     {
        int x=q.front().first;
        int y=q.front().second;
        grid[x][y]=index;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int nx=x+rows[k];
            int ny=y+cols[k];
            if(valid(nx,ny,n)&&grid[nx][ny]==1)
            { size++;
              q.push({nx,ny});
              grid[nx][ny]=index;
            }
        }  
     }
     mp[index]=size;
  }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        int index=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(grid[i][j]==1)
                 {
                  bfs(grid,i,j,mp,index);
                  index++;
                 }
            }
        }
        int area=0;

       /*  this is just for checking whether our island successfully classified or not
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   unordered_set<int>islands;
                if(grid[i][j]==0)
                {  int size=1;  //because 0 ko 1 me convert karne se bhi to ek count hoga na area
                    //now check on four sides whether after changing this zero how many islands are available
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+rows[k];
                        int ny=j+cols[k];
                        if(valid(nx,ny,n)&&grid[nx][ny]!=0)
                        {
                            islands.insert(grid[nx][ny]);  //now hamne jo bhi distinct islands ko index diya tha usko set me insert kar diya
                        }
                    }
                    for(auto x:islands)
                    {
                        size+=mp[x];
                    }
                    area=max(area,size);
                }
            }
        }

        return area==0?n*n:area;
        
    }
};