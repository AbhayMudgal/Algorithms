#include<bits/stdc++.h>
using namespace std;

int isMatch(string s, string p){
  int n = p.size();
  int m = s.size();

  int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1; i<=n; i++){
    for(int j = 0; j<=m; j++){
      if(p[i]==s[j]||p[i]=='.'){
        if(j>0) dp[i][j] |= dp[i-1]dp[j-1];
      }

      else if(p[i]=='*'){
        dp[i][j] |= dp[i-2][j];
        dp[i][j] |= dp[i-1][j];
        if(s[j]==p[i-1]||p[i-1]=='.'){
          if(j>0) dp[i][j] |= dp[i][j-1];
        }
      }
    }
  }

  return dp[n][m];


}

int main(){
  string s, p;
  cout<<"Enter string: ";
  getline(cin,s);
  cout<<"Enter pattern: ";
  getline(cin, p);

  if(isMatch(s, p)) cout<<"true";
  else cout<<"false";

  return 0;

}
