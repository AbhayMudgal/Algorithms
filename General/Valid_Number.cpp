/*  For example, all the following are valid numbers:
 ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789", ".0e7"],
 while the following are not valid numbers:
 ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53", "e0.2"].
*/
#include<bits/stdc++.h>
using namespace std;

bool valid(string s){
  /* A moderate solution to the probem can be obtained by understanding the
  conditions that make up a number from the example and then using a brute force
  approach to rule out everything that is not a number. The solution is acceptable
  and runs with O(n) time complexity. It s fairly diffiult to improve upon this
  time complexity but the code that is presented below can be further modified to
  achieve better space complexity and methodology.
  */
  int n = s.length();

  int pos = 0, neg = 0; //represents the positive and negative signs in a number.
  // These are only accepatable at the start of the string and the power of e.

  int e = 0, poi = 0; //represent the count of e and decimal in the string. A
  //decimal point is only acceptable before a e in the string. E is necessarily
  // followed by an integer

  int num = 0; //represents the count of integers in the string. A valid number
  //needs to have this value > 0.

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
