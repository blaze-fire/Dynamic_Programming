#include <iostream>
#include <map>

using namespace std;

typedef pair<int,int> Pair; 

bool canSum(int target, int arr[], int size, map<int,bool> &memo){
  if(memo.count(target) > 0) return memo[target];
  if(target == 0) return true;
  if(target < 0 ) return false;

  for(int i=0; i < size; i++){
    
    int remainder = target - arr[i];

    if(canSum(remainder, arr, size,memo)){
      memo[target] = true;
      return true;
    }  
  }
  memo[target] = false;
  return false;
}

int main(){
  int arr[3] = {7,14,0};
  map <int,bool> memo;
  cout<<canSum(100,arr,3,memo)<<endl;    
  
    return 0;
}