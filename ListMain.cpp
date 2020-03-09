// Wyatt Applebay

#include <iostream>
#include "List.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void rand_seed()
{
	int seed = static_cast<int>(time(0));
	srand(seed);
}

// random integer between a and b;
int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

template <typename T>
void print_list(List<T> lst)
{
  typename List<T>::iterator itr;
  for(itr = lst.begin(); itr != lst.end(); ++itr)
    cout << *itr << " ";
  cout << endl;
}

int main()
{
  List<int> rlist;
  rand_seed();

  for(int i = 1; i<20; i++)
  {
    int num = rand_int(1,50);
    rlist.push_back(num);
  }


  cout << endl;
  print_list(rlist);
  cout << endl;


  return 0;
}
