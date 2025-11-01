#include <iostream>
#include <cstddef>

void destroy(int ** mtx, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

void construct(int ** mtx, int init, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      mtx[i][j] = init;      
    }
  }
}

int ** create(size_t rows, size_t cols) {
  int ** mtx = new int * [rows];
  size_t created = 0;
  try {
    for (; created < rows; ++created) {
      mtx[created] = new int[cols];
    }
  } catch (const std::bad_alloc & e) {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

void input(int ** mtx, size_t rows, size_t cols) {

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << "enter " << i << ":" << j << ' ';
      std::cin >> mtx[i][j];
    }
  }
}


void output(int ** mtx, size_t rows, size_t cols) {
  for (size_t i = 0; i < rows; ++i) {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j) {
      std::cout << ' ' << mtx[i][j];
    }
    std::cout << "\n";
  }
}

int main() {
  size_t r = 0, c = 0;
  std::cin >> r >> c;
  if (!std::cin) {
    std::cerr << "Bad input" << "\n";
    return 2;
  }
  int ** mtx = nullptr;
  try {
    mtx = create(r, c);
  }
  catch(const std::bad_alloc & e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << "created\n";
  construct(mtx, 0, r, c);
  // std::cout << mtx[0][0] << "\n";
  input(mtx, r, c);
  if (!std::cin) {
    std::cerr << "Bad input" << "\n";
    return 2;
  }

  output(mtx, r, c);
  // std::cout << mtx[0][0] << "\n";
  destroy(mtx, r);
}





