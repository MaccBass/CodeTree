#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main() {
    set<pair<int, int>> s;
    int n, m; cin>>n>>m;

    for (int i;i<n;i++){
        int x, y; cin>>x>>y;
        s.insert(make_pair(x, y));
    }

    for (int i;i<m;i++){
        int x, y; cin>>x>>y;
        if (s.find(make_pair(x, y)) != s.end()){
            cout<<x<<' '<<y<<'\n';
        }
        else{
            set<pair<int, int>>::iterator it = s.upper_bound(make_pair(x, y));
            if (it==s.end()){
                cout<<-1<<' '<<-1<<'\n';
            }
            else{
                cout<<it->first<<' '<<it->second<<'\n';
            }
        }
    }
    return 0;
}