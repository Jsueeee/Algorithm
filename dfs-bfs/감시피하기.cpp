#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
char map[6][6];
//선생님 위치 정보 저장
vector<pair<int, int> > teachers;
//빈 공간 위치 정보 저장
vector<pair<int, int> > spaces;


bool watch(int x, int y, int direction){
  //왼쪽 방향 검사
  if(direction == 0){
    while(y>=0){
      if(map[x][y] == 'S'){
        return true;//학생 찾음
      }
      if(map[x][y] == 'O'){
        return false;//장애물 만나서 어차피 더이상 못찾음.
      }
      y -= 1; //왼쪽 방향 전진
    }
  }
  //오른쪽 방향 검사
  if(direction == 1){
    while(y < n){
      if(map[x][y] == 'S'){
        return true;//학생 찾음
      }
      if(map[x][y] == 'O'){
        return false;//장애물 만나서 어차피 더이상 못찾음.
      }
      y += 1; //오른쪽 방향 전진
    }
  }
  //위쪽 방향 검사
  if(direction == 2){
    while(x >= 0){
      if(map[x][y] == 'S'){
        return true;//학생 찾음
      }
      if(map[x][y] == 'O'){
        return false;//장애물 만나서 어차피 더이상 못찾음.
      }
      x -= 1; //위쪽 방향 전진
    }
  }
  //아래쪽 방향 검사
  if(direction == 3){
    while(x < n){
      if(map[x][y] == 'S'){
        return true;//학생 찾음
      }
      if(map[x][y] == 'O'){
        return false;//장애물 만나서 어차피 더이상 못찾음.
      }
      x += 1; //아래쪽 방향 전진
    }
  }
  return false;//못찾았다
}

//장애물 설치 이후, 학생 감지 되는지 검사
bool process(){
  //선생 한명씩 차례대로 위치 확인
  for(int i=0; i<teachers.size(); i++){
    int x = teachers[i].first;
    int y = teachers[i].second;

    //4가지 방향으로 학생 감지
    for(int i=0; i<4; i++){
      if(watch(x, y, i)){
        return true;//찾았다
      }
    }
  }
  return false;//못 찾았다
}

bool found;

int main(){
  cin>>n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin>>map[i][j];

      if(map[i][j] == 'T'){
        teachers.push_back({i, j}); //선생님 위치 정보 저장
      }

      if(map[i][j] == 'X'){
        spaces.push_back({i, j}); //빈 공간 위치 정보 저장
      }
    }
  }
  //장애물 설치하기 -> 빈 공간 중 3개 설치하기 -> 최대 36C3
  //10,000 이하이므로 모든 조합 고려
  vector<bool> binary(spaces.size());//n만큼 //nCk
  fill(binary.end()-3, binary.end(), true); //3개(k개) 원소에 1, 나머지 원소에 0 (true/false)
  do{
    //장애물 3개 설치
    for(int i=0; i<spaces.size(); i++){
      if(binary[i]){
        int x = spaces[i].first;
        int y = spaces[i].second;
        map[x][y] = 'O';//장애물 설치
      }
    }

    //학생이 한 명도 감지되지 않는 경우
    if(!process()){
      found = true;
      break; //조합 그만
    }

    //이번 조합에서 못찾았다면, 다음 조합으로 넘어가기 전에 설치된 장애물 다시 없애주기
    for(int i=0; i<spaces.size(); i++){
      if(binary[i]){
        int x = spaces[i].first;
        int y = spaces[i].second;
        map[x][y] = 'X'; //장애물 제거. 다시 빈 공간으로
      }
    }
  }while(next_permutation(binary.begin(), binary.end()));

  if(found) cout<<"YES";
  else cout<<"NO";
}