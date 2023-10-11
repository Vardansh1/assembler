#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream f;
    fstream example;
    fstream output;

    output.open("ans.txt",ios::out);
    f.open("SIC.txt",ios::in);
    example.open("assembly.txt",ios::in);
    string s;
    unordered_map<string,string> sic;
    while(!f.eof()){
        getline(f,s);
        stringstream ss(s);
        string word;
        ss >> word;
        string a = word;
        ss >> word;
        sic[a] = word;
    }
    unordered_map<string,int> symbol_table;
    int loc = -1;
    while(!example.eof()){
        if(loc != -1) loc += 3;
        getline(example,s);
        stringstream ss(s);
        string word;
        vector<string> line;
        while(ss >> word) line.push_back(word);
        if(line[0] == "START") loc = stoi(line[1]);
        string temp = "";
        for(auto &it : line){
            if(sic.find(it) != sic.end()) temp += sic[it] + " ";
            else temp += it + " ";
        }
        if(line.size() == 3) symbol_table[line[0]] = loc;
        output<<temp<<endl;
    }
    cout<<" SYMBOL TABLE "<<endl<<endl;
    for(auto &it : symbol_table) cout<<it.first<<" --> "<<it.second<<endl;
    cout<<endl;
    output.close();
    example.close();
    f.close();
   return 0;
}