#include<iostream>

using namespace std;
int diff=INT16_MAX;
int temp_ans=INT16_MIN;
int temp_left;
int temp_right;
int final_left,final_right;
int solve(int a[],int l,int r)
{
     
    if(l == r) 
    {
        if(a[l] >temp_ans || (a[l]==temp_ans && diff>0))
        {
            temp_ans = a[l];
            final_left=l;
            final_right=l;
            diff=0;
        }
        return a[l];
    }
    
    int mid = (l+r)/2;
    int b = solve(a,l,mid);

    int c = solve(a,mid+1,r);

    int m_l=0;
    int s_l=INT32_MIN;


    for(int i=mid;i>=l;i--)
    {
        m_l+=a[i];
        if(m_l>s_l) 
        {
            s_l = m_l;
            temp_left = i;
        }
    }
    int  m_r=0;
    int s_r=INT32_MIN;
    for(int i=mid+1;i<=r;i++)
    {
        m_r+=a[i];
        if(m_r>s_r) 
        {
            s_r = m_r;
            temp_right = i;
        }
    }
    int cross= s_l+s_r;
    
    if(cross>temp_ans) 
    {
        temp_ans = cross;
        diff = temp_right - temp_left ;
        final_left = temp_left;
        final_right = temp_right;
        
    }

    if(cross == temp_ans)
    {
        if((temp_right - temp_left ) < diff) 
        {
            final_left = temp_left;
            final_right = temp_right;
            diff =temp_right - temp_left ; 
            
        }
    }

    int z=max(b,cross);
    
    if(max(z,c) > temp_ans) temp_ans = max(z,c);
    return max(z,c);
}

int main()
{

    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++) cin>>a[i];
    
    int max_sum=INT32_MIN;
    int ans = solve(a,0,size-1);
    
    
    if(ans > 0){
    cout<<"[";
    for(int i=final_left;i<=final_right;i++)
    {
        if(i==final_right) cout<<a[i];
        else cout<<a[i]<<", ";
    }
    cout<<"] with a sum ";
    

    cout<<ans<<endl;
    }
    else cout<<"[] with a sum 0\n";




}