#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

int main(int argc, char **argv){
  int matrixHeight = atoi(argv[1]);
  int matrixWidth = atoi(argv[2]);
  int blockWidth = atoi(argv[3]);
  float *input = malloc(matrixHeight * matrixWidth * sizeof(float));
  float *output = malloc(matrixWidth * matrixHeight * sizeof(float));
  float multiplier;
  float randNum;
  srand(time(NULL));
  for (int i = 0; i < matrixWidth * matrixHeight; i++){
    multiplier = rand() / (float) RAND_MAX;
    randNum = -100 + multiplier * (100 + 100);
    input[i] = randNum;
  }
  struct timeval before;
  struct timeval after;
  time_t beforeSec;
  time_t afterSec;
  suseconds_t beforeMicro;
  suseconds_t afterMicro;
  gettimeofday(&before, NULL);
  beforeSec = before.tv_sec;
  beforeMicro = before.tv_usec;
  int rStart;
  int cStart;
  for (int block = 0; block < (int) ceil(matrixWidth / (float) blockWidth) * ceil(matrixHeight / (float) blockWidth); block++){
    rStart = (block / (int) ceil(matrixWidth / (float) blockWidth)) * blockWidth;
    for (int row = rStart; row < rStart + blockWidth; row++){
      cStart = (block % (int) ceil(matrixWidth / (float) blockWidth)) * blockWidth;
      for (int col = cStart; col < cStart + blockWidth; col++){
	if(row < matrixHeight && col < matrixWidth){
	  output[col * matrixHeight + row] = input[row * matrixWidth + col];
	}
      }
    }
  }
  gettimeofday(&after, NULL);
  afterSec = after.tv_sec;
  afterMicro = after.tv_usec;
  double seconds = (after.tv_sec - before.tv_sec) + ((after.tv_usec - before.tv_usec) / (float) 1000000);
  printf("Seconds: %f\n", seconds);
  free(input);
  free(output);
}
