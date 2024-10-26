#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n, m; cin>>n>>m;
    for (int i; i<n; i++){
        int tmp; cin>>tmp; s.insert(tmp);
    }

    for (int i; i<m; i++){
        int tmp; cin>>tmp;
        if (s.find(tmp) != s.end()){
            cout<<tmp<<'\n';
        }
        else{
            if (s.upper_bound(tmp) == s.end()){
                cout<<-1<<'\n';
            }
            else{
                cout<<*s.upper_bound(tmp)<<'\n';
            }
        }
    }
    return 0;
}