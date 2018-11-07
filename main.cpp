#include <iostream>
#include <fstream>

void realloc(size_t[], size_t);

/**
 * The program reads numbers from a file and prsize_ts the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char* argv[]) {
  size_t a = 0;
  size_t sum = 0;
  size_t avg = 0;
  size_t arraySize = 1;
  size_t numbersAdded = 0;
  size_t* numbers = new size_t[arraySize];

  std::ifstream myReadFile(argv[1]);

  if (!myReadFile.is_open()) return 2;

  while (myReadFile >> a) {
    /* Expand array if numbers added is greater or equals size of array */ 
    if (numbersAdded >= arraySize) {
      size_t *tmp = new size_t[arraySize + 1];

      for (size_t i = 0; i < arraySize; i++) {
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
  for (size_t i = 0; i < arraySize; i++) {
    std::cout << numbers[i] << '\t';
  }

  std::cout << "\tOutput: ";
  for (size_t i = 0; i < arraySize; i++) {
    (numbers[i] > avg) ? std::cout << numbers[i] << '\t': std::cout << "";
  }

  return 0;
}

/* vim: set ts=2 sw=2 tw=79 ft=cpp et :*/
