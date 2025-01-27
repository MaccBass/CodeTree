#include <iostream>
#include <queue>
using namespace std;

// compare 구조체 연습
// pair 특징 이용해서 first를 절대값, second를 음수면 -1 이렇게 넣어고 오름차순 pq 쓰면 더 쉽긴 하다.
// compare 시 true면 우선순위가 낮다. 즉 a>b로 정의한 경우, a가 b보다 크면 true니까 a가 우선순위가 더 낮아짐.(오른쪽)
struct compare{
    bool operator()(int a, int b){
        if (abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

priority_queue<int, vector<int>, compare> pq;

int n;
int main() {

    cin>>n;
    for (int i=0; i<n; i++){
        int x; cin>>x;
        if (x != 0){
            pq.push(x);
        }
        else {
            if (pq.empty()){
                cout<<0<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
    }

    return 0;
}