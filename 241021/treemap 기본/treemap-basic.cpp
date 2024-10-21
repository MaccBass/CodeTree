#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    
    map<int, int> m;

    int n; cin>>n;
    while(n){

        string op; int k, v;
        cin>>op;
        if (op == "print_list"){
            if (m.empty()){
                cout<<"None"<<'\n';
                continue;
            }
            for (const auto& p: m){
                cout<<p.second<<' ';
            }
            cout<<'\n';
        }
        if (op == "add"){
            cin>>k>>v;
            m[k]=v;
        }
        if (op == "remove"){
            cin>>k;
            m.erase(k);
        }
        if (op == "find"){
            cin>>k;
            if (m.find(k) == m.end()){
                cout<<"None"<<'\n';
            }
            else {
                cout<<m[k]<<'\n';
            }
        }

        --n;
    }


    return 0;
}