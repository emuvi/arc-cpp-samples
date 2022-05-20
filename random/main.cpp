#include <iostream>
#include <stdlib.h>
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
  int total = 100;
  if (argc > 1) {
    total = atoi(argv[1]);
  }
  srand((unsigned int)time(0));
  for (int i = 0; i < total; ++i) {
    std::cout << gen_random(45) << std::endl;
  }
  return 0;
}