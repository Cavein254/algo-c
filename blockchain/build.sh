set -xe
clang main.c -o main -Wall -Wextra -lcrypto
./main
