//given a target and an array print the shortest length of combination from array that sum to target

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> local;                        // to store a combination of numbers temporarily 
vector<int> ans;                          // to store the shortest combination

int min_length=10000;                     // initialize min length to a really high value

void canSum(int l, int target, vector <int> &arr, map<int,vector<int>> &memo){

  if(target == 0){
      if(local.size() < min_length){                                        //check for minimum length
          memo[target] = ans;     
          min_length = local.size();                                        //change min length
          ans.erase(ans.begin(),ans.end());                                 //empty the vector to fill with the shortest combination
          vector<int>::iterator itr = local.begin();                        //iterator pointing to the start of the vector
          for(; itr != local.end(); itr++){
              ans.push_back(*itr);                                          //dereferencing and pushing the value at the end of vector
          }
      }
      return;
  }

  if(target < 0 ) return ;

  for(int i=l; i<arr.size(); i++ ){
    if(memo.count(target) > 0)  continue;                                   // if already in hashmap skip

    int remainder = target - arr[i];                
    local.push_back(arr[i]);
    canSum(i+1,remainder, arr, memo);
    local.pop_back();
  }

}

int main(){
  vector <int> arr = {1,4,2,5,3,4,3,4};
  map <int,vector<int>> memo;                                             //memoization

  canSum(0,7,arr,memo);
  vector<int>::iterator itr = ans.begin();

  for(; itr != ans.end(); itr++){
     cout<<*itr<<"   ";
  }
  return 0;
}