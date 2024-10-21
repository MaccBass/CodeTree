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
        else {
            cin>>k;
            if (op == "add"){
                cin>>v;
                m[k]=v;
            }
            if (op == "remove"){
                m.erase(k);
            }
            if (op == "find"){
                if (m.find(k) == m.end()){
                    cout<<"None"<<'\n';
                }
                else {
                    cout<<m[k]<<'\n';
                }
            }
        }
        
        --n;
    }
    return 0;
}