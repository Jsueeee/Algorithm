#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> a){
    int n = a.size(); //행 길이
    int m = a[0].size(); //열 길이
    vector<vector<int> > result(n, vector<int>(m));//결과 리스트
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            result[j][n-i-1] = a[i][j];
        }
    }
    return result;
}

//배열의 중앙에 있는 자물쇠의 더한 값이 모두 1인지 확인하기
bool check(vector<vector<int> > newLock){
    int lockLength = newLock.size()/3;
    
    //배열의 중앙 위치 접근//lockLength에서 lockLength만큼
    for(int i=lockLength ; i<lockLength*2; i++){
        for(int j=lockLength; j<lockLength*2; j++){
            if(newLock[i][j] != 1){
                return false;
            }
        }
    }
    return true;//모두 1이므로 열쇠가 다 들어맞는다
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();
    
    //자물쇠의 크기를 기존의 3배로
    vector<vector<int> > newLock(n*3, vector<int>(n*3));
    
    //새로운 자물쇠의 중앙 부분에 기존 자물쇠 넣기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            newLock[i+n][j+n] = lock[i][j];
        }
    }
    
    //4방향 확인
    for(int rotation=0; rotation<4; rotation++){
        key = rotate(key); //열쇠 회전하면서 확인
        
        for(int x=0; x<n*2; x++){
            for(int y=0; y<n*2; y++){
                //자물쇠에 열쇠 끼워넣기
                for(int i=0; i<m; i++){
                    for(int j=0; j<m; j++){
                        newLock[x+i][y+j] += key[i][j];
                    }
                }
	
	//1이 다 채워지는지 체크 후 맞으면 답 반환
                if(check(newLock))  return true;
                
                //안맞으면 다시 돌려야 하니까 열쇠 다시 빼기
                for(int i=0; i<m; i++){
                    for(int j=0; j<m; j++){
                        newLock[x+i][y+j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}