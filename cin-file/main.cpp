#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string>

std::string gen_random(const int len) {
  static const char set[] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz";
  std::string tmp_s;
  tmp_s.reserve(len);
  for (int i = 0; i < len; ++i) {
    tmp_s += set[rand() % (sizeof(set) - 1)];
  }
  return tmp_s;
}

int main(int argc, char *argv[]) {
  srand((unsigned int)time(0));
  FILE *file;
  auto random_file = gen_random(36);
  const char *file_name = argc > 1 ? argv[1] : random_file.c_str();
  errno_t error = fopen_s(&file, file_name, "w");
  if (error > 0) {
    std::cerr << "Could not open the output file.\n";
    return 1;
  }
  std::string line;
  while (std::getline(std::cin, line)) {
    fprintf(file, "Line: %s\n", line.c_str());
    fflush(file);
  }
  fclose(file);
  return 0;
}