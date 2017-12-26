#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string encode(string s){
    string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string result, binStr; bool p;

    for(int i = 0; i < s.length(); i++)
        binStr += bitset<8>(s[i]).to_string();

    for(int i = 0; i < binStr.length() % 6; i++)
        binStr += '0', p = true;

    for(int i = 0; i < binStr.length(); i+=6)
        result += Base64[bitset<6>(binStr.substr(i, 6)).to_ulong()];

    if(p) result += '=';

    return result;
}

string decode(string s){
    string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    string result, binStr;

    int j(0);
    for(int i = 0; i < s.length(); i++){
        while((j < 64)&&(s[i]) != Base64[j])j++;
        if(j != 64) binStr += bitset<6>(j).to_string();
        j = 0;
    }

    for(int i = 0; i < binStr.length() % 8; i++)
        binStr += '0';

    for(int i = 0; i < binStr.length(); i+=8)
        result += (char)(bitset<8>(binStr.substr(i, 8)).to_ulong());

    return result;
}

int main(){
    string input = "My name is Uchiha Sasuke. I hate a lot of things, and I really do not like anything. I have no dreams or plans for the future. There is only a purpose. I'm going to revive my clan, and besides this, kill one person.";
    string msg = encode(input);
    cout << msg << endl;
    cout << "Decode: " << decode(msg) << endl;
}
