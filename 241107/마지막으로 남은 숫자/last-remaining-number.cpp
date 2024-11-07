#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    for (int i=0;i<n;i++){
        int x; cin>>x; pq.push(x);

    }

    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();
        int diff = a-b;
        if (a-b == 0) continue;
        else pq.push(a-b);
    }

    if (pq.empty()) cout<<-1;
    else cout<<pq.top();

    return 0;
}