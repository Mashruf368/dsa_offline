#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
{

      //cout<<i<<" "<<j<<endl;
      if(i<0 && j<0) return true;
      if(j<0) return false;
      if(i<0) {
            if(s2[j]!='*') return false;
            for(int k=0,r=0;k<=j;k++)
            {
                  if(s2[k]=='+') return false;
                  if(s2[k]=='*') continue;
                  else if(s2[k+1]!='*') return false;

            }
            return true;
      }
      if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];


      if(s1[i] == s2[j] || s2[j] == '.') //{cout<<"case 1\n";return solve(i-1,j-1,s1,s2);}
            {

                  return dp[i+1][j+1] = solve(i-1,j-1,s1,s2,dp);
            }
      if(s2[j] == '*') //{cout<<"case 2\n";return (solve(i,j-2,s1,s2) ||  solve(i-1,j,s1,s2));}
      {
            //cout<<"case 2\n";
            bool g = solve(i,j-2,s1,s2,dp);     //zero rep
            bool h =false;
            if(s1[i] == s2[j-1] || s2[j-1]=='.') h = solve(i-1,j,s1,s2,dp);
            return dp[i+1][j+1] = g||h;

      }
      if(s2[j] == '+') //{cout<<"case 3\n";return (solve(i-1,j-2,s1,s2) && solve(i-1,j,s1,s2));}
            {
                  //cout<<"case 3\n";
                  bool h=false;
                  bool g=false;
                  if(s1[i] == s2[j-1] || s2[j-1]=='.') h = solve(i-1,j-2,s1,s2,dp);    //one repeate
                  if((s1[i] == s2[j-1] && s1[i-1]==s2[j-1]) || s2[j-1]=='.') g = solve(i-1,j,s1,s2,dp);
                  return dp[i+1][j+1] = g||h;
            }

      return dp[i+1][j+1] = false;
}

int main()
{
      string a;
      string b;
      getline(cin,a);
      getline(cin,b);

      vector<vector<int>> dp (a.size()+1,vector<int> (b.size()+1,-1));

      if(solve(a.length()-1,b.length()-1,a,b,dp)) cout<<"true\n";
      else cout<<"false\n";
}

















































































































































/*
1. Input: aaa
   Pattern: a*
   Output: True

2. Input: abb
   Pattern: a.*
   Output: True

3. Input: aabbcc
   Pattern: a*c*b*
   Output: False

4. Input: bbcc
   Pattern: a+bbcc
   Output: False

5. Input: bbcc
   Pattern: a*bbc.
   Output: True

6. Input:
   Pattern: a*b*c*
   Output: True

7. Input: aac
   Pattern: a*aac
   Output: True

8. Input: atels
   Pattern: a.+f*
   Output: True

9. Input: abc
   Pattern: abc
   Output: True

10. Input: abc
    Pattern: a.c
    Output: True

11. Input: abc
    Pattern: ab*d
    Output: False

12. Input: aaaa
    Pattern: a*aa
    Output: True

13. Input: ab
    Pattern: a+b
    Output: True

14. Input: aaab
    Pattern: a+b
    Output: True

15. Input: abbbbb
    Pattern: a+b*
    Output: True

16. Input:
    Pattern:
    Output: True

17. Input: abc
    Pattern: def
    Output: False

18. Input: aaabc
    Pattern: a*b*c*
    Output: True

19. Input: a
    Pattern: ab*c
    Output: False

20. Input: abcde
    Pattern: abc
    Output: False

21. Input: abbbbcc
    Pattern: a.*c+
    Output: True
    */



