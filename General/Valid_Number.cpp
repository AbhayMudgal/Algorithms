/*  For example, all the following are valid numbers:
 ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", ".0e7"],
 while the following are not valid numbers:
 ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "e0.2"].
*/
#include<bits/stdc++.h>
using namespace std;

bool valid(string s){
  int n = s.length();
  int pos = 0, neg = 0;
  int e = 0, poi = 0;
  int num = 0;
  for(int i = 0; i<n; i++){
    if(s[i]=='e'||s[i]=='E'){
      if(num == 0) return false;
      pos = 0; neg = 0; e++; num = 0;
    }

    else if(s[i]=='.'){
      if(e==1) return false;
      poi++;
      pos = 1;
      neg = 1;
    }

    else if(s[i]=='+'){
      if(i==0) pos++;
      else if(s[i-1]=='e'||s[i-1]=='E') pos++;
      else return false;
    }
    else if(s[i]=='-'){
      if(i==0) neg++;
      else if(s[i-1]=='e'||s[i-1]=='E') neg++;
      else return false;
    }

    else if(s[i]-'0'>9||s[i]-'0'<0)
      return false;

    else if(s[i]-'0'<=9&&s[i]-'0'>=0) num = 1;

    if(pos>1||neg>1||poi>1||e>1) return false;
  }
  if(num<1) return false;
  return true;
}


int main(){
  string s;
  cout<<"Enter string: ";
  cin>>s;

  cout<<endl;
  if(valid(s)) cout<<"String forms a valid number."
  else cout<<"String does not represent an rational number."

  return 0;
}
