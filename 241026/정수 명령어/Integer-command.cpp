#include <iostream>
#include <set>
using namespace std;

int main() {
    
    set<int> s;
    int t, k;
    cin>>t;

    while(t){

        cin>>k;
        while(k){

            char op; int n; cin>>op;
            if (op == 'I'){
                cin>>n;
                s.insert(n);
            }
            if (op == 'D'){
                cin>>n;
                if (s.empty()){
                }
                else if (n == 1){
                    s.erase(*s.rbegin());
                }
                else if (n == -1){
                    s.erase(*s.begin());
                }
            }
            --k;
        }
        if (s.empty()){
            cout<<"EMPTY"<<'\n';
        }
        else{
            cout<<*s.rbegin()<<' '<<*s.begin()<<'\n';
        }
        s.clear();
        --t;
    }


    return 0;
}