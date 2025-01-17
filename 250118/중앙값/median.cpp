#include <iostream>
#include <queue>

using namespace std;

int t;
int m;
priority_queue<int> small_max;
priority_queue<int, vector<int>, greater<int>> big_min;

/*
아이디어: pq 두개를 두고, 반갈라서 작은 수들 중 제일 큰게 top인 small_max,
큰 수중 제일 작은게 top인 big_min을 둔다.
총 입력받은 숫자가 홀수개면 무조건 small_max가 홀수개, big_min이 짝수개(3/2 등)

숫자가 들어올 때, big_min보다 크면 big_min에 push
홀수번째일 때 big_min에 들어가면 big_min top을 small_max에 push
짝수번째일 때 small_max에 들어가면 small_max top을 big_min에 push

이후 small_max의 top을 출력해주면 중앙값이 된다.
*/
int main() {
    cin >> t;
    while (t){
        cin >> m;
        for (int i=1; i<=m; i++){
            int num;
            cin>>num;
            
            // 첫번째
            if (i==1) {
                small_max.push(num);
                cout<<num<<' ';
            }
            // 짝수번째일 때 -> small_max는 n+1개, big_min에는 n개
            else if (i%2 == 0){
                if (num > small_max.top()){
                    big_min.push(num);
                }
                else{
                    small_max.push(num);
                    big_min.push(small_max.top());
                    small_max.pop();
                }
            }
            // 홀수번째일 때 -> small_max와 big_min 개수 같음.
            else if (i%2 == 1){
                if (num < big_min.top()){
                    small_max.push(num);
                }
                else {
                    big_min.push(num);
                    small_max.push(big_min.top());
                    big_min.pop();
                }
                cout<<small_max.top()<<' ';
            }
        }

        small_max = {};
        big_min = {};
        cout<<'\n';
        t--;
    }

    return 0;
}
