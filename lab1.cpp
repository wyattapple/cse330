#include <iostream>
#include <vector>
#include <iomanip>
#include <cassert>
using namespace std;


int compute_median(vector<int> nums)
{
assert(nums.size()/2 != 0);
int half = nums.size()/2;
for (int i = 0; i < nums.size(); i++)
{
 int k = 0;
 for (int j =0; j < nums.size(); j++)
{
   if (nums[j] < nums[i])
   k++;
}
if (k == half)
 return nums[i];
}
 return -1;
}


int main()
{
  vector<int> nums;

  cout << "Enter how many elements you want (must be odd) " << endl;
  int values;
  int next;
  cin >> values;
  cout << "Enter your numbers: " << endl;
  for (int i = 0; i < values; i++)
  {
    cin >> next;
    nums.push_back(next);
  }
  cout << endl;
  int med = compute_median(nums);
  cout << endl << endl;
  for (int i = 0; i < nums.size(); i++)
     cout << nums[i] << " ";
  cout << endl << endl;
  cout << "Your median is: " << med << endl << endl;

  return 0;
}
