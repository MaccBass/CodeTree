#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>> points;

int main() {
    int n, m; cin>>n>>m;

    for (int i=0;i<n;i++){
        int x, y; cin>>x>>y;
        points.insert(make_pair(x, y));
    }

    for (int i=0;i<m;i++){
        int k; cin>>k;
        auto it = points.lower_bound(make_pair(k, 0));
        if (it == points.end()){
            cout<<-1<<' '<<-1<<'\n';
        }
        else {
            cout << it->first << ' ' << it->second << '\n';
            // cout << (*it).first << ' ' << (*it).second << '\n';
            points.erase(it);
        }
    }

}