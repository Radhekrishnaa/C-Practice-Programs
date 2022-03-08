/* 
==========================================================================================
   Subject= DS Lab     Practical No_9  Course code: CSL 301
   Roll NO- 21         Name- Radhekrishna Mishra
   AIM: Write a program to search an element using Binary Search
==========================================================================================
*/

//===============***Program on Binary Search***========================
#include <stdio.h>
int main()
{
  int i, first, last, middle, num, search, array[100];
//i is for forloop running and to start the loop from 0th position
//first is for starting the search from first position
//last and middle are for their respective position according to their name
//num is for storing the number of inputs user want to add or elements number
//search variable is for storing the number which we have to find
//array variable array is to store the elements 

  printf("Enter number of elements\n");
  scanf("%d", &num);  //taking the input of number to be added

  printf("Enter %d integers\n", num);

  for (i = 0; i < num; i++)
    scanf("%d", &array[i]);  // taking inputs of n elements

  printf("Enter value to find\n");
  scanf("%d", &search); //asking for the element to searched 

  first = 0;  //initiating it from 0th positon
  last = num - 1;
  middle = (first+last)/2;

  while (first <= last) {
    if (array[middle] < search)
      first = middle + 1; 
      //if the number being searched is greater than number in middle than the first 
      //position is increased till middle+1
    else if (array[middle] == search) {
      printf("%d found at location %d.\n", search, middle+1);
      break;
      //if we got the element directly at the middle place we have to just notedown
      //the position and break from the loop
    }
    else
      last = middle - 1;
    //if element is less than the middle then we decrease the last element from 
    //middle -1 
    middle = (first + last)/2;
    //after decreasing the value of last we again reset the midddle position
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);
    //if the element is not present we display the error message

  return 0;
}