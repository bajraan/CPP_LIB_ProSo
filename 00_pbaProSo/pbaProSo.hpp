#ifndef PBAPROSO_HPP
#define PBAPROSO_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>

void test(void);

int          tt(int,int);
bool         isPrime                         (const int number);
void         primes_EratostenesSieve__ACC    (std::vector<long long>& isprime, std::vector<long long>& prime, std::vector<long long>& SPF);
void         primes_EratostenesSieve__BASE   (std::vector<bool>& sieve);
void         primes_EratostenesSieve__SIMPLE (std::vector<bool>& sieve);
void         primes_EratostenesSieve_SSIMPLE (unsigned long long);
void         primes_EratostenesSieve__NAIVE  (int n);

int              makeaDifrence              (std::string, std::string);
int              saveThePrisoner            (int, int, int);
std::vector<int> circularArrayRotation      (std::vector<int>, int, std::vector<int>);
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

std::vector<std::string> bigNumStringSort(std::vector<std::string>);

std::string decode_cipherVigenere(std::string, std::string);
std::string decode_cipherBacon(std::string cipher, char A, char B);
std::string decode_cipherBacon(std::string cipher);
std::string decode_cipherCezar(std::string cipher, int shift);
std::string decode_cipherCezar(std::string cipher);
std::string decode_brute_cipherXOR(std::string cipher);
std::string decode_cipherXOR(std::string cipher, uint8_t key);
void brute(void);

#endif