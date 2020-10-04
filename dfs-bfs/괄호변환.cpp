#include <string>
#include <vector>

using namespace std;

int is_balance(string p){
    int left_cnt = 0;
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            left_cnt += 1;
        }else left_cnt -= 1;
        if(left_cnt == 0)   return i;
    }
    return -1;
}
bool is_correct(string p){
    int left_cnt = 0;
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            left_cnt += 1;
        }else{
            //올바른 문자열이 아닐 경우
            if(left_cnt == 0){
                return false;
            }
            left_cnt -= 1;
        }
    }
    return true;
}

string solution(string p) {
    string answer = "";
    if(p == "") return answer;
    
    int index = is_balance(p);
    
    string u = p.substr(0, index+1);
    string v = p.substr(index+1);
    
    if(is_correct(u)){
        answer = u + solution(v);
    }else{
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1, u.size()-2);//첫번째와 마지막 문자 제거
        for(int i=0; i<u.size(); i++){
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        answer += u;
    }
    return answer;
}