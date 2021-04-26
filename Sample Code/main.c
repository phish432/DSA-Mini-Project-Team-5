#include <stdio.h>
#include <stdlib.h>
#include "node.h"


int main()
{
  //n is number of nodes to be taken as input
  int n;
  scanf("%d",&n);

  //created an array to store pointers to the nodes.
  node *arr[n];

  //taking input from the user.
  for(int i = 0; i < n; i++)
    {
      arr[i] = (node *)malloc(sizeof(node));

      if(arr[i] == NULL)
        {
          printf("Sorry Memory could not be allocated\n");
          return 0;
        }
      else
        {
          input_node(arr[i]);
        }
    }
    
    //printing the input so as to confirm the code
  for(int i = 0; i < n; i++)
    printf("%d %d %d\n",arr[i]->state_number, arr[i]->value, arr[i]->parent);
  //make_tree(arr, n);


  return 0;
}
