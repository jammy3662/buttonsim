src/main.cpp: In function 'int main()':
src/main.cpp:29:17: error: lvalue required as unary '&' operand
   29 |  int &t = &timer(5);
      |            ~~~~~^~~
src/main.cpp:30:9: error: invalid type argument of unary '*' (have 'int')
   30 |  while (*t != 0) {
      |         ^~
