#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq;

int main() {

    int n,m; cin>>n>>m;
    while (n){
        int num; cin>>num; pq.push(num);

        n--;
    }

    while (m){
        int num = pq.top();
        pq.pop();
        pq.push(num-1);

        m--;
    }

    cout<<pq.top();
    return 0;
}