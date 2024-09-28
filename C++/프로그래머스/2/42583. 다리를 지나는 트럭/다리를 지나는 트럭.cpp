#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int count=0;
    int lowcount=0;
    int len=size(truck_weights);
    vector<int> time(len);
    int curweight=0;
    while(lowcount<len){
        answer++;
        if (count<len){
            if (curweight+truck_weights[count]<=weight){
                curweight+=truck_weights[count];
                count++;
            }
        }
        for (int i=lowcount;i<count;i++){
            time[i]++;
        }
        
        if(time[lowcount]==bridge_length){
            curweight-=truck_weights[lowcount];
            lowcount++;
        }
        
    }
    for(int i=0;i<len;i++){
        cout<< time[i]<<" ";
    }
    cout<<count;
    return answer;
}