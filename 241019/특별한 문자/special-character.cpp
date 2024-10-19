#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> um;
int main() {
    string str;
    char first_alphabet = ' ';
    cin>>str;

    for (const auto& i: str){
        if (um.find(i) == um.end()){
            if (first_alphabet == ' ') first_alphabet = i;
            um[i]++;
        }
        else {
            if (i==first_alphabet){
                first_alphabet = ' ';
            }
        }
    }

    if (first_alphabet == ' ') cout<<"None";
    else cout<<first_alphabet;
    return 0;
}