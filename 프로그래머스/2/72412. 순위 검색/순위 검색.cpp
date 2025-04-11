#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> vec[4][3][3][3];
int infosize,querysize;


void init(vector<string> info){
    int a,b,c,d,e;
    string st;
    for(string i: info){
        stringstream str(i);
        for(int j=0;j<5;j++){
            str>>st;
            if(j==0){
                if(st=="cpp") a=0;
                else if(st=="java") a=1;
                else a=2;
            }
            else if(j==1){
                if(st=="backend") b=0;
                else b=1;
            }
            else if(j==2){
                if(st=="junior") c=0;
                else c=1;
            }
            else if(j==3){
                if(st=="chicken") d=0;
                else d=1;
            }
            else if(j==4){
                vec[a][b][c][d].push_back(stoi(st));
                vec[a][b][c][2].push_back(stoi(st));
                vec[a][b][2][d].push_back(stoi(st));
                vec[a][b][2][2].push_back(stoi(st));
                vec[a][2][c][d].push_back(stoi(st));
                vec[a][2][c][2].push_back(stoi(st));
                vec[a][2][2][d].push_back(stoi(st));
                vec[a][2][2][2].push_back(stoi(st));
                vec[3][b][c][d].push_back(stoi(st));
                vec[3][b][c][2].push_back(stoi(st));
                vec[3][b][2][d].push_back(stoi(st));
                vec[3][b][2][2].push_back(stoi(st));
                vec[3][2][c][d].push_back(stoi(st));
                vec[3][2][c][2].push_back(stoi(st));
                vec[3][2][2][d].push_back(stoi(st));
                vec[3][2][2][2].push_back(stoi(st));
            }
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    sort(vec[i][j][k][l].begin(),vec[i][j][k][l].end(),greater<int>());
                }
            }
        }
    }
}

int binary_search(int value, vector<int> vec1){
    if(vec1.size()==0)return 0;
    int st=0;
    int en = vec1.size()-1;
    //cout<<en;
    int mid;
    while (st<en){
        mid = (st+en)/2;
        if(vec1[mid]>=value) st=mid+1;
        else en=mid-1;
    }
    //cout<<vec1[st];
    if(vec1[st]>=value)return st+1;
    else return st;
    return 0;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string st;
    infosize=info.size();
    querysize=query.size();
    int a,b,c,d,e,counta;
    //cout<<"1\n";
    init(info);
    //cout<<"2\n";
    int countb=0;
    for(string i : query){
        stringstream str(i);
        for(int j=0;j<8;j++){
            str>>st;
            if(j==0){
                if(st=="cpp") a=0;
                else if(st=="java") a=1;
                else if(st=="python") a=2;
                else a=3;
            }
            else if(j==2){
                if(st=="backend") b=0;
                else if(st=="frontend") b=1;
                else b=2;
            }
            else if(j==4){
                if(st=="junior") c=0;
                else if (st=="senior") c=1;
                else c=2;
            }
            else if(j==6){
                if(st=="chicken") d=0;
                else if (st=="pizza")d=1;
                else d=2;
            }
            
            else if(j==7){
                //cout<<a<<b<<c<<d;
                counta=binary_search(stoi(st),vec[a][b][c][d]);
                //cout<<counta;
                answer.push_back(counta);
            }
        }
        cout<<'\n';
    }
    return answer;
}