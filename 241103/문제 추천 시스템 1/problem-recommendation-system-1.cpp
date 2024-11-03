#include <iostream>
#include <set>
#include <string>
using namespace std;

set<pair<int, int>, greater<pair<int, int>>> s;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    for (int i=0;i<n;i++){
        int P, L; cin>>P>>L;
        s.insert(make_pair(L, P));
    }

    int m; cin>>m;
    while (m){

        string op; cin>>op;
        if (op == "rc"){
            int num; cin>>num;
            set<pair<int, int>>::iterator it;

            if (num == -1){
                it = prev(s.end());
            }
            if (num == 1){
                it = s.begin();
            }
            cout<<it->second<<'\n';
        }
        if (op == "ad"){
            int P, L; cin>>P>>L;
            s.insert(make_pair(L, P));
        }
        if (op == "sv"){
            int P, L; cin>>P>>L;
            s.erase(make_pair(L, P));
        }
        m--;
    }

    return 0;
}