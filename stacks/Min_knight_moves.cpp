
#include <bits/stdc++.h>
using namespace std;
int x[8] = {1, 2, -1, 2, 1, -2, -2, -1};
int y[8] = {2, 1, 2, -1, -2, 1, -1, -2};

bool check(int n, int m, int c, int d){
  //function to check if the current jump is within the limits of the board
  if (c<0||c>=n) return false;
  if (d<0||d>=m) return false;
  return true;
}

int capture(int n, int m, int a, int b, int c, int d){
  /* A stack of plausible moves is created and then checked in order if further moves
  generate the desired outcome.*/
  stack<vector<int>> s;
  s.push({c-1, d-1, 0});
  while (!s.empty()){

    vector<int> e = s.top();
    s.pop();

    for(int i = 0; i<8; i++){
      int k = e[0] + x[i];
      int l = e[1] + y[i];

      if(k == a-1 && l==b-1){
        return e[2] + 1;
      }
      else if(check(n, m, k, l)){
        s.push({k, l, e[2]+1});
      }
    }
  }
}


int main(){
  int n, m, a, b, c, d;

  cout<<"Enter the dimensions of the chess board: ";
  cin>>n>>m;

  cout<<"Enter the coordinates of the capturing square: ";
  cin>>a>>b;

  cout<<"Enter the starting coordinates: ";
  cin>>c>>d;

  cout<<"Number of moves required to capture: "<<capture(n, m, a, b, c, d);

  return 0;
}
