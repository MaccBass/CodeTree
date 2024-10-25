#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    
    set<int> s;
    int n; cin>>n;
    for (int i=0;i<n;i++){
        string op;
        int tmp;
        cin>>op;

        if (op == "add"){
            cin>>tmp;
            s.insert(tmp);
        }
        if (op == "remove"){
            cin>>tmp;
            s.erase(tmp);
        }
        if (op == "find"){
            cin>>tmp;
            if (s.find(tmp) != s.end()){
                cout<<"true"<<'\n';
            }
            else{
                cout<<"false"<<'\n';
            }
        }
        if (op == "lower_bound"){
            cin>>tmp;
            if (s.lower_bound(tmp) != s.end()){
                cout<<*s.lower_bound(tmp)<<'\n';
            }
            else{
                cout<<"None"<<'\n';
            }
        }
        if (op == "upper_bound"){
            cin>>tmp;
            if (s.upper_bound(tmp) != s.end()){
                cout<<*s.upper_bound(tmp)<<'\n';
            }
            else{
                cout<<"None"<<'\n';
            }
        }
        if (op == "largest"){
            if (s.empty()){
                cout<<"None"<<'\n';
            }
            else{
                cout<<*s.rbegin()<<'\n';
            }
        }
        if (op == "smallest"){
            if (s.empty()){
                cout<<"None"<<'\n';
            }
            else{
                cout<<*s.begin()<<'\n';
            }
        }
    }

    return 0;
}