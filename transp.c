#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
//change for github
int main(int argc, char **argv){
  int matrixWidth = atoi(argv[1]);
  int blockWidth = atoi(argv[2]);  
  float *input = malloc(matrixWidth * matrixWidth * sizeof(float));
  float *output = malloc(matrixWidth * matrixWidth * sizeof(float));
  float multiplier;
  float randNum;
  srand(time(NULL));
  for (int i = 0; i < matrixWidth * matrixWidth; i++){
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
  for (int block = 0; block < (matrixWidth * matrixWidth) / (blockWidth * blockWidth); block++){ //fastest of the three
    rStart = (block / (matrixWidth / blockWidth)) * blockWidth; //Beginning row of each block
    for (int row = rStart; row < rStart + blockWidth; row++){
      cStart = (block % (matrixWidth / blockWidth)) * blockWidth; //Beginning column of each block
      for (int col = cStart; col < cStart + blockWidth; col++){
	output[col * matrixWidth + row] = input[row * matrixWidth + col]; //transposes the number
	//printf("%i %i\n", row, col);
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
