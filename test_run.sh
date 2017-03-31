echo "Test starts..."
# clang -c set.c
# clang++ -lgtest -std=c++11 -pthread -g -Wall -Wextra -o unit_test.o -c test.cpp
# clang++ -std=c++11 -g -Wall -Wextra -o unit_test set.o unit_test.o -lgtest -pthread
g++ -pthread ./numpycppTest.cpp -I./eigen/ -lpthread -lgtest_main -lgtest -std=c++0x && ./a.out
exit $result
