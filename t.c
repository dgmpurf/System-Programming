#include<stdio.h>
#include<stdlib.h>

//global variables
int *FP

int A(int x, int y);
int B(int x, int y);
int C(int x, int y);

int main (int argc, char *argv[], char *env[])
{
  int a,b,c;
  
  printf("enter main\n");
  
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&a=%8x &b=%8x &c=%8x\n", &a, &b, &c);
  
  //(1) Write C code to print values of argc and argv[] entries
  printf("***argc: %d***\n",argc);
  printf("argv:");
  int i=0;
  for(i=0;i<argc;i++){
    printf("%s",argv[i]);cd
  }
  printf("***\n");
  
  a=1; b=2; c=3;
  A(a,b);
  printf("exit main\n");
}

int A(int x, int y)
{
  int d,e,f;
  printf("enter A\n");
  
  //print address of d,e,f
  d=4; e=5; f=6;
  printf("&d=%x &e=%x &f=%x\n",&d,&e,&f);
  //end print address
  B(d,e);
  printf("exit A\n");
}

int B(int x, int y)
{
  int g,h,i;
  
  printf("enter B\n");

  //print address of g,h,i
  g=7; h=8; i=9;
  printf("&g=%x &h=%x &i=%x\n",&g,&h,&i);
  //end print address  //
 
  C(g,h);
  printf("exit B\b");
}

int C(int x, int y)
{
  int u,v,w,i,*p;
  
  printf("enter C\n");

  //print address of u,v,w,i,p
  u=10; v=11; w=12; i=13;
  printf("&u=%x &v=%x &w=%x &i=%x p=%x\n",&u,&v,&w,&i,p);
  //end print address  //

  //(2) Write C code to print the stack frame link list
  FP=(int *)getebp();
  printf("***Stack frame link list***\n");
  //stack frame link list end in 0
  while(FP){
    printf("%x->",FP);
    //FP print at the next FP and set it to different value
    FP=*FP;
  }
  printf("%x\n",FP);
  printf("\n");
  //end pritn stack frame linked list

  //Print the stack contents from p to the frame of main()
  //YOU MAY JUST PRINT 128 ENTRIES OF THE STACK CONTENTS
  //p now contains the address of itself
  p=(int *)&p;
  printf("***Stack contents***\n");
  int j=0;
  //stack frame link list end with 0, but not print more than 128 entries
  while(j<128 && p){
    printf("%x(value: %d)->",p,*p);
    p++;
    j++;
  }
  printf("%x->...->0\n",p);
  printf("***\n");
}


