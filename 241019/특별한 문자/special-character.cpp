#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<char, int> um;
queue<char> q;
int main() {
    string str;
    char ans = ' ';
    cin>>str;

    for (const auto& i: str){
        if (um.find(i) == um.end()){
            q.push(i);
        }
        um[i]++;
    }

    while(!q.empty()){
        if (um[q.front()] == 1){
            ans = q.front();
            break;
        }
        else{
            q.pop();
        }
    }


    if (ans == ' ') cout<<"None";
    else cout<<ans;
    return 0;
}