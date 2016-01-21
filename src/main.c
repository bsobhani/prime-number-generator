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

int* prime_list;
int pl_size;

int prime_number_list(int n){
  int i;
  int cur;
  if(n<pl_size)
    return prime_list[n];
  prime_list=realloc(prime_list,(n+1)*sizeof(int));
  if(pl_size==0){
    prime_list[0]=2;
    pl_size=1;
  }
  //cur=3;
  cur=prime_list[pl_size-1]+1+prime_list[pl_size-1]%2;
  while(pl_size<n+1){
    for(i=0; i<pl_size; ++i){
      if(cur%prime_list[i]==0){
	break;
      }
    }
    if(i==pl_size){
      prime_list[i]=cur;
      pl_size+=1;
    }
    cur+=2;
    //printf("%d %d\n",cur,pl_size);
  }
  return prime_list[n];
}
  

int main(int argc, char** argv){
  int i;
  if(argc!=2){
    printf("usage: %s index", argv[0]);
    return 1;
  }
  pl_size=0;
  sscanf(argv[1],"%d",&i);
  printf("%d\n",prime_number_list(i));
  return 0;
}
