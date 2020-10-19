#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool check[10000000];//중복 방지

//소수찾기 알고리즘***
bool primeNumber(int a){
    for(int i=2; i<=sqrt(a); i++){
        if(a%i == 0)    return false;//소수 아님
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    int max = 0;
    int temp = 0;
    
    //greater사용
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    //내림차순으로 만들어서 통째로 가장 큰 수 만들기
    max = stoi(numbers);

    //max찾았으니까 다시 오름차순 정렬
    sort(numbers.begin(), numbers.end());
    
    do{
        string str = "";
        temp = 0;
        for(int i=0; i<numbers.size(); i++){
            str += numbers[i];
            temp = stoi(str);
            if(check[temp] == false && temp > 1 && primeNumber(temp) == true){
                answer++;
                cout<<'*'<<temp;
                check[temp] = true;
            }
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    
    return answer;
}