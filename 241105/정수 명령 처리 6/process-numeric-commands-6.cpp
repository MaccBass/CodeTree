#include <iostream>
#include <queue>
#include <string>

using namespace std;
priority_queue<int> pq;

int main() {
    
    int n; cin>>n;
    while (n){

        string op; cin>>op;
        if (op == "push"){
            int num; cin>>num;
            pq.push(num);
        }
        if (op == "pop"){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        if (op == "size"){
            cout<<pq.size()<<'\n';
        }
        if (op == "empty"){
            if (pq.empty()){
                cout<<1<<'\n';
            }
            else{
                cout<<0<<'\n';
            }
        }
        if (op == "top"){
            cout<<pq.top()<<'\n';
        }

        n--;
    }
}