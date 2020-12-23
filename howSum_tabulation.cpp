// given a target and an array print all the combinations from array that sum to target using tabulation

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/*
vector<int> canSum(int target, vector <int> &arr){
  unordered_map <int,vector<int>> table;
  for(int i=1; i<target+1;i++){
      table[i].push_back(-1);
  }
  table[0].push_back(0);
  
  for(int i=0; i<arr.size();i++){
    table[arr[i]].clear() ;
    table[arr[i]].push_back(arr[i]);
  }

  for(int i=0; i< target+1; i++ ){
    for(int j=0; j<arr.size(); j++){
        if(i + arr[j] <= target && (arr[i] + table->at(arr[i]) == target)){
            
            table[i].push_back(arr[j]);
        }
    }
  } 
  return table[target];
}*/

int main(){
  vector<int> arr = {4,2,5,3};
  /*
  vector<int> ans = canSum(7,arr);
  vector<int>::iterator itr = ans.begin();
  for(; itr != ans.end(); itr++){
     // cout<<*itr;
  }*/
int target = 7;
unordered_map <int,vector<int>> table;
  for(int i=1; i<target+1;i++){
      table[i].push_back(-1);
  }
  table[0].push_back(0);
  
  for(int i=0; i<arr.size();i++){                                       
    table[arr[i]].clear() ;                //here as map store vector<int> as value , therefore can perform vector operations on table[i]
    table[arr[i]].push_back(arr[i]);        // same here can perform vector operations on table[i] as it is vector                              
  }

  for(int i=0; i< target+1; i++ ){
    vector<int>::iterator itr = table[i].begin();
    if(*itr != -1){
        for(int j=0; j<arr.size(); j++){
            
            if(*itr + arr[j] <= target){
                if(*table[*itr+arr[j]].begin() == -1)
                  table[*itr+arr[j]].clear();
                table[*itr+arr[j]].push_back(arr[j]);
            }
        }
    }
  } 
  
  vector<int>::iterator itr = table[target].begin();
  for(; itr != table[target].end(); itr++){
      cout<<*itr<<"     ";
  }
 

  return 0;
}