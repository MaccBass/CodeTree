#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n, m;
    cin>>n>>m;
    
    for (int i=1;i<=m;i++){
        s.insert(i);
    }

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp; s.erase(tmp);
        cout<<*s.rbegin()<<'\n';
    }

    return 0;
}