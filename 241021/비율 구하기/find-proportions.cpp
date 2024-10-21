#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

map<string, int> dict;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    for (int i=0;i<n;++i){
        string tmp; cin>>tmp;
        ++dict[tmp];
    }

    for (const auto& p: dict){
        cout<<p.first<<' '<<fixed<<setprecision(4)<<(float)p.second/(float)n * 100<<'\n';
    }

    return 0;
}