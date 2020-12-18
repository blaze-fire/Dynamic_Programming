#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> ans;

void canSum(int l, int target, vector <int> &arr){

  if(target == 0){
      for(int i=0; i<ans.size(); i++){
          cout<<ans.at(i)<<"  ";
      }
      cout<<endl;
      return;
  }

  if(target < 0 ) return ;

  for(int i=l; i<arr.size(); i++ ){
    int remainder = target - arr[i];                //get value and increment at the same time
    ans.push_back(arr[i]);
    canSum(i+1,remainder, arr);
    ans.pop_back();
  }

}

int main(){
  vector <int> arr = {1,4,2,5,7,3};

  canSum(0,7,arr);

  return 0;
}