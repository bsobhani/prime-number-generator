#include "stdio.h"
#include "stdlib.h"

int is_prime(int n){
  int i;
  if(n==1 || n==0){
    return 0;
  }
  if(n==2){
    return 1;
  }
  if(n%2==0){
    return 0;
  }
  for(i=3; i<n; i+=2){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}

int prime_number(int n){
  int i;
  int j;
  int count=0;
  for(i=0; i<=n; i+=is_prime(count)){
    count++;
  }
  return count;
}

int main(int argc, char** argv){
  int i;
  if(argc!=2){
    printf("usage: %s index", argv[0]);
    return 1;
  }
  sscanf(argv[1],"%d",&i);
  printf("%d\n",prime_number(i));
  return 0;
}
