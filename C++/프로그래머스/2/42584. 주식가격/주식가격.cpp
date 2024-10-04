#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<size(prices);i++){
        int count=0;
        for(int j=i+1;j<size(prices);j++){
            count++;
            if(prices[i]<=prices[j]){
            }
            else{
                break;
            }
        }
        answer.push_back(count);
    }
    return answer;
}