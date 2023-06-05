#ifndef PBATIMETESTS_HPP
#define PBATIMETESTS_HPP

#include <iostream>
#include <string>
#include <cstring>

enum class TRes{fail,pass,unknown};

template <typename T>
TRes assertTrue(const T& actual, const T& expected);
void printResult(TRes, std::string, std::string, bool);
bool checkDebFlag(int, char* []);

void TEST__timeConversion(bool);
void TEST__decode_cipherVigenere( void );

#endif