#ifndef PBAPROSO_HPP
#define PBAPROSO_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

void test(void);

std::vector<int> intigerToDigitsVector(int n);
std::vector<int> missingNumbers(std::vector<int> arr, std::vector<int> brr);
int              minimumDistances__PBA_1(std::vector<int> a);
int              minimumDistances__GPT_1(std::vector<int> a);

std::string decode_cipherVigenere(std::string, std::string);
std::string decode_cipherBacon(std::string cipher, char A, char B);
std::string decode_cipherBacon(std::string cipher);
std::string decode_cipherCezar(std::string cipher, int shift);
std::string decode_cipherCezar(std::string cipher);
std::string decode_brute_cipherXOR(std::string cipher);
std::string decode_cipherXOR(std::string cipher, uint8_t key);
void brute(void);

#endif