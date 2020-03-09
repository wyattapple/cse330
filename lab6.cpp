// Wyatt Applebay 004973341

#include <iostream>
#include <vector>

using namespace std;

bool binsearch(vector<int> v, int x, int& count) //& pass by reference so instead of getting rid of the count number it keeps it as a copy by pointing to it
{
  int low = 0;
  int high = v.size() - 1;

  while (low < high)
  {
    int mid = (low + high) / 2;
    int midval = v[mid];
    count = count + 1;
    if (midval == x)
      return true;
    if (midval < x)
      low = mid + 1;
    if (midval > x)
      high = mid - 1;
  }
  return false;
}

int main()
{
  int input;
  int count = 0; //declare value here so we can use it in the bool function
  vector<int> int_list = {5, 11, 36, 41, 49, 72, 93};

  cout << "Enter a value to search: ";
  cin >> input;
  if (binsearch(int_list, input, count))
   cout << "Number is in the list!! :)))" << endl << "Searched the list: " << count << " times" << endl;
  else
   cout << "Number not found :(" << endl << "Searched the list: " << count << " times" << endl;
   return 0;
}
