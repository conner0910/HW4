#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//change for github
int main(int argc, char **argv){
  int N = atoi(argv[1]);
  int block = atoi(argv[2]);  
  float *input = malloc(N * N * sizeof(float));
  float *output = malloc(N * N * sizeof(float));
  float multiplier;
  float randNum;
  srand(time(NULL));
  for (int i = 0; i < N * N; i++){
    multiplier = rand() / (float) RAND_MAX;
    randNum = -100 + multiplier *  (100 + 100);
    input[i] = randNum;
  }
  
  free(input);
  free(output);
}
