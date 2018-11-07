#include <iostream>
#include <fstream>

void realloc(int[], int);

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char * argv[]) {
    int a = 0;
    int sum = 0;
    int arraySize = 1;
    int numbersAdded = 0;
    int* numbers = new int[arraySize];

    std::ifstream myReadFile(argv[1]);

    while (myReadFile >> a) {
        sum += a;
        numbersAdded++;

        /* If array is full and not at EOF, expand by 1 */
        if (numbersAdded == arraySize) {
          realloc(numbers, arraySize);
          arraySize++;
        }
    }

    myReadFile.close();

    std::cout << sum << "\n";

    return 0;
}

/**
 * Expand the passed dynamically allocated array by arraySize + 1
 */
void realloc(int numbers[], int arraySize) {
  int *tmp = new int[arraySize + 1];

  for (int i = 0; i < (arraySize - 1); i++) {
    tmp[i] = numbers[i];
  }

  delete[] numbers;

  numbers = tmp;
  tmp = nullptr;
}

/* vim: set ts=2 sw=2 tw=79 ft=cpp et :*/
