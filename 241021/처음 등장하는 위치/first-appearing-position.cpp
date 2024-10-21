#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;

    for (int i=0;i<n;++i){
        int tmp; cin>>tmp;
        if (m.find(tmp) == m.end()){
            m[tmp]=i+1;
        }
    }

    for (const auto& p: m){
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}