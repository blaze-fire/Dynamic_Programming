//given a target and an array print all the combinations from array that sum to target

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> ans;                        // to store a combination of numbers temporarily 

void howSum(int l, int target, vector <int> &arr){

  if(target == 0){
      for(int i=0; i<ans.size(); i++){
          cout<<ans.at(i)<<"  ";
      }
      cout<<endl;
      return;
  }

  if(target < 0 ) return ;

  for(int i=l; i<arr.size(); i++ ){
    int remainder = target - arr[i];                
    ans.push_back(arr[i]);
    howSum(i+1,remainder, arr);
    ans.pop_back();
  }

}

int main(){
  vector <int> arr = {2, 7, 11, 15};

  howSum(0,9,arr);

  return 0;
}