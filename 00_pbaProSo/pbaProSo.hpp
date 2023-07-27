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

std::vector<int> circularArrayRotation      (std::vector<int>, int, std::vector<int>);
int              saveThePrisoner            (int, int, int);
std::vector<int> intigerToDigitsVector      (int);
int              intigerToIntigerReversed   (int);
std::vector<int> missingNumbers             (std::vector<int>, std::vector<int>);
int              minimumDistances__PBA_1    (std::vector<int>);
int              minimumDistances__GPT_1    (std::vector<int>);
int              beautifulTriplets__PBA_1   (int, std::vector<int>);
int              beautifulTriplets__GPT_1   (int, std::vector<int>); // MAP BASED    O(nlogn) O(n) O(n)
int              beautifulTriplets__GPT_2   (int, std::vector<int>); // VECTOR BASED O(nlogn) O(nlogn) O(n)
int              beautifulTriplets__OTH_1   (int, std::vector<int>);
int              beautifulTriplets__OTH_2   (int, std::vector<int>);

std::string decode_cipherVigenere(std::string, std::string);
std::string decode_cipherBacon(std::string cipher, char A, char B);
std::string decode_cipherBacon(std::string cipher);
std::string decode_cipherCezar(std::string cipher, int shift);
std::string decode_cipherCezar(std::string cipher);
std::string decode_brute_cipherXOR(std::string cipher);
std::string decode_cipherXOR(std::string cipher, uint8_t key);
void brute(void);

#endif