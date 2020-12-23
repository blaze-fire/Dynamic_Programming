// Same CanSum problem but now with tabulation

#include <iostream>
#include <vector>

using namespace std;
vector<int> ans;

bool canSum(int target, vector <int> &arr){

  bool table[target+1] ={false};                    // tabulation   process
  table[0] = true;                                  // set table[0] as true as take null to get sum of 0 

  for(int i=0; i<target+1; i++){
    if(table[i] == true){
        
        for(int j=0; j<arr.size(); j++){
            if(i+arr[j] < target+1){
                table[i+arr[j]] = true;
            }
        }
    }
  }
  return table[target];
}

int main(){
  vector <int> arr = {3,4,2};
  
  if(canSum(7,arr)){
    cout<<endl<<"Yes !!"<<endl;
  }    
  else
  {
    cout<<endl<<"No"<<endl;
  }
    return 0;
}