#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
int dy[8]={-1, 0, 1,-1, 1,-1, 0, 1};

int fill(vector<vector<bool> >& map, int y, int x){
  // falseのます＝海or探索済みは処理しない
  if(!map[y][x]) return 0;
  // 探索済みにする
  map[y][x] = false;
  for(int i=0; i<8; i++){
    // 8方向にずらして探索（この際マスの外に出ることがあるがmapは2マス分拡張されており、out_of_rangeはでない）
    fill(map, y+dy[i], x+dx[i]);
  }
  // 処理された回数分1が返る＝島の数になる
  return 1;
}
        
int main(){
  while(1){
    int w,h;
    cin >> w >> h;
    if(w==0) break;

    // w×hのますを2マス分延長して初期化する
    vector<vector<bool> > map(h+2, vector<bool>(w+2, false));
    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++){
        int tmp;
        cin >> tmp;
        // 陸のますのみtrueに変えておく
        if(tmp==1) map[i][j]=true;
      }
    }

    int count=0;
    // w×hのます分のループ
    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++){
          count+= fill(map, i,j);
      }
    }
    cout << count << endl;
  }   
  return 0;
}