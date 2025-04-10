#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers,int sum, int ind, int sign,int target){
    int answer=0;
    if(ind==numbers.size()){
        if(sum==target)
            return 1;
        else
            return 0;
    }
    else{
        sum+=numbers[ind]*sign;
        answer+=dfs(numbers,sum,ind+1,1,target);
        answer+=dfs(numbers,sum,ind+1,-1,target);
    }
    return answer;
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer+=dfs(numbers,0,0,1,target);
    answer+=dfs(numbers,0,0,-1,target);
    return answer/2;
}