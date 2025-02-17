#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<int> v[],int vertex,int visited_dfs[])
{
    if(visited_dfs[vertex]) return;
    visited_dfs[vertex]++;
    for(auto child : v[vertex])
    {
        dfs(v,child,visited_dfs);
    }
} 


int main()
{
    int n,m;
    cin>>n>>m;
    vector <int> v[n+1];
    int visited_dfs[n+1]={};
    vector <int> ans;
    int a[2];


    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);



    } 
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(visited_dfs[i] == 0) 
        {
            dfs(v,i,visited_dfs);
            //cout<<"count inc "<<i<<endl;
            ans.push_back(i);
            count++;
        }
    }


    cout<<count-1<<endl;
    for(int i=1;i<ans.size();i++) cout<<ans[i-1]<<" "<<ans[i]<<endl;

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