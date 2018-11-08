#include <iostream>
#include <fstream>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char* argv[]) {
  int a = 0;
  int sum = 0;
  int avg = 0;
  int arraySize = 1;
  int numbersAdded = 0;
  int* numbers = new int[arraySize];

  std::ifstream myReadFile(argv[1]);

  if (!myReadFile.is_open()) return 2;

  while (myReadFile >> a) {
    /* Expand array if numbers added is greater or equals size of array */ 
    if (numbersAdded >= arraySize) {
      int *tmp = new int[arraySize + 1];

      for (int i = 0; i < arraySize; i++) {
        tmp[i] = numbers[i];
      }

      delete[] numbers;
      numbers = tmp;
      tmp = nullptr;

      arraySize += 1;
    }

    numbers[numbersAdded] = a;
    sum += a;
    numbersAdded++;
  }

  myReadFile.close();

  avg = sum / arraySize;

  std::cout << "Input: "; 
  for (int i = 0; i < arraySize; i++) {
    std::cout << numbers[i] << '\t';
  }

  std::cout << "\tOutput: ";
  for (int i = 0; i < arraySize; i++) {
    (numbers[i] > avg) ? std::cout << numbers[i] << '\t': std::cout << "";
  }

  return 0;
}

/* vim: set ts=2 sw=2 tw=79 ft=cpp et :*/
