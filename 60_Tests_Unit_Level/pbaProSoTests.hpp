#ifndef PBATIMETESTS_HPP
#define PBATIMETESTS_HPP

#include <iostream>
#include <string>
#include <cstring>

enum class TRes
{
    fail
    ,pass,
    unknown
};
enum class OTyp
{
    _int_,
    _string_,
    _stringcharchar_
};
template <typename T>
TRes assertTrue(const T& actual, const T& expected);
int checkDebFlag(int, char* []);

void TEST__decode_cipherVigenere(void);
void PRTRE_decode_cipherVigenere(TRes, int, std::string, std::string, std::string, std::string);
void TEST__decode_cipherBacon(void);
void PRTRE_decode_cipherBacon(TRes, int, std::string, std::string, std::string);

#endif





//wihitespace