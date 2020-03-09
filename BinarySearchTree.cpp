// Wyatt Applebay 004973341

#include "Set.h"
#include "Random.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
  int x;
  Set<int> BST;
  Vector<int> newnumber;

  for(int i = 0; i <= 25; i++)
  {
    BST.insert(rand_int(1,100));
  }
  BST.printTree();
  cout << endl;
  for(int j = 0; j < 5; j++)
  {
    cout << "Type an integer from the list to remove: " << endl;
    cin >> x;
    BST.remove(x);
    newnumber.push_back(x);
  }
  for(int k = 0; k < newnumber.size(); k++)
  {
    cout << newnumber[k];
  }
  cout << " are to be removed from the list";
  cout << endl << endl;

  cout << "The reduced tree is: " << endl;
  BST.printTree();
  cout << endl << endl;

  BST.printInternal();

  for(int z = 0; z < newnumber.size(); z++)
  {
    BST.insert(newnumber[z]);
  }

  cout << endl << endl;

  BST.printTree();
  cout << endl << endl;

  BST.printInternal();

   return 0;
}
