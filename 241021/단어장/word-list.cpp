#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> dict;
int main() {
    int n; cin>>n;
    for (int i=0;i<n;++i){
        string word;
        cin>>word;
        dict[word]++;
    }

    for (const auto& p: dict){
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}