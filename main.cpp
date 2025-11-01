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

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows) {
  int ** table = new int * [rows];
  size_t pos = 0;

  for (size_t i = 0; i < rows; ++i) {
    table[i] = new int[lns[i]];
    for (size_t j = 0; j < lns[i]; ++j) {
      table[i][j] = t[pos];
      ++pos;
    }
}
return table;
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

  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t n = 12;
  size_t lns[] = {4, 2, 5, 1};
  size_t rows = 4;

  int ** table = convert(t, n, lns, rows);
  for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < lns[i]; ++j) {
            std::cout << table[i][j] << ' ';
        }
        std::cout << '\n';
  }

  for (size_t i = 0; i < rows; ++i) {
    delete[] table[i];
  }

  delete[] table;

  return 0;




}





