#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    //key값 string, 그 뒤에 string 여러개 저장할 벡터
    unordered_map<string, vector<string>> m;
    
    //greater< vector<string> >()없이 통과 불가
    sort(tickets.begin(), tickets.end(), greater< vector<string> >());
    
    for(int i=0; i<tickets.size(); i++){
        //연결정보 저장
        //unordered_map 사용하여 도시 이름으로.
        m[tickets[i][0]].push_back(tickets[i][1]);
    }
    
    //스택 역할하는 벡터
    vector<string> s;
    s.push_back("ICN");
    //vector<string> s = vector<string> {"ICN"};
    
    while(!s.empty()){
        string airport = s.back();
        //스택이니까 back사용
        //스택->최상단 원소부터, vector에서는 맨 뒤 원소부터
        
        if(m.find(airport) == m.end() || m[airport].size() == 0){
            //더이상 갈 수 있는 곳이 없거나 다 방문했으면
            answer.push_back(airport);
            s.pop_back();//스택에서 빼기
        }else{
            //아직 더 가야되면
            s.push_back(m[airport].back());
            m[airport].pop_back();
        }
    }
    //뒤집어줘야함
    reverse(answer.begin(), answer.end());
    return answer;
}