#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int d[101][101] = {0, };
    int map[101][101] = {0, };
    
    for(int i=0; i<puddles.size(); i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    //주어지는 좌표가 첫칸이 (1,1)이므로 맞추기
    d[1][0] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == -1){
                d[i][j] = 0;
            }else{
                //괄호 중요!! : 효율성
                d[i][j] = (d[i-1][j] + d[i][j-1]) % 1000000007;
                //up, left, 첫줄 예외 나눠서 하지 않아도 에러 안났음.
            }
        }
    }
    return d[n][m];
}