#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

void bfs(int **g,int vertex,int visited_bfs[],int n)
{
    
    visited_bfs[vertex]++;
    queue<int> q;
    q.push(vertex);
    while(!q.empty())
    {
        int a=q.front();
        for(int i=1;i<=n;i++)
        {
            if(g[a][i]==1 && !visited_bfs[i]) 
            {
                visited_bfs[i]=1;
                q.push(i);
            }
        }
        q.pop();
    }
}


int main()
{
    int n,m;
    cin>>n>>m;

    //bfs
    int **g=new int*[n+1];
    for(int i=0;i<=n;i++) g[i]=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++) g[i][j]=0;
    }

    
    

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        g[a][b]=1;
        g[b][a]=1;
    } 

    int count_bfs=0;
    int visited_bfs[n+1]={};
    vector<int> ans_bfs;
    for(int i=1;i<=n;i++)
    {
        if(visited_bfs[i] == 0) 
        {
            bfs(g,i,visited_bfs,n);
            //cout<<"count inc "<<i<<endl;
            ans_bfs.push_back(i);

            count_bfs++;
        }
    }
    cout<<count_bfs-1<<endl;
    for(int i=1;i<ans_bfs.size();i++) cout<<ans_bfs[i-1]<<" "<<ans_bfs[i]<<endl;

    for(int i=0;i<=n;i++)
    {
        delete [] g[i];
    }
    delete g;


    

}

/*
10 10
4 8
5 9
4 9
2 7
6 7
7 10
1 5
6 9
8 9
2 4
*/

/*
10 10
3 9
6 8
9 10
7 8
8 10
7 10
1 9
8 9
6 9
2 7
*/