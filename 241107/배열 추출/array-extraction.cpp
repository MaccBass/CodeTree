#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;

    while (n){
        int x; cin>>x;
        if (x==0){
            if (pq.empty()){
                cout<<0<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }

        n--;
    }

    return 0;
}