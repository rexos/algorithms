#include <iostream>
using namespace std;

int sol(int tab[5][5], int cost[5][5], int i, int j){
  cout << "cazzo" << endl;
  if( i==5 )
    return 0;
  else{
    if( tab[i][j] != -1 )
      return tab[i][j];
    else
      return tab[i][j] = min( sol(tab,cost,i+1,j)+cost[j][i+1], sol( tab, cost, i+1, i ) + cost[i][i+1] );
  }
}


int main(){
  int tab[5][5];
  int cost[5][5];
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      tab[i][j] = -1;
      cost[i][j] = 0;
    }
  }

  cost[0][1] = 3;
  cost[0][2] = 5;
  cost[0][3] = 7;
  cost[0][4] = 4;
  cost[1][1] = 2;
  cost[1][2] = 2;
  cost[1][3] = 2;
  cost[1][4] = 8;
  cost[2][2] = 3;
  cost[2][3] = 7;
  cost[2][4] = 5;
  cost[3][3] = 5;
  cost[3][4] = 4;
  //  cost[4][4] = 2;

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      cout << cost[i][j] << " ";
    }
    cout << endl;
  }


  int value = sol(tab,cost,0,0);
  cout << value << endl;
  

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }


  return 0;
}
