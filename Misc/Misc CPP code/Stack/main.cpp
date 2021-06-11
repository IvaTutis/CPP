#include <iostream>
#include <stdio.h>


using namespace std;

int MAXSIZE = 100000;
int stack[100000];
int top = -1;

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}

int pop() {
   int data;

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
   return;
}


int main()
{
    int n, ai, tmin, tmax, tas, l, r, i, j;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf ("%d", &ai);

    };
    return 0;
}
