#ifndef PBATIMETESTS_HPP
#define PBATIMETESTS_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>

extern float Glob_testTimeResult_ms;

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
class Timer
{
public:
    Timer();
    ~Timer();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTimePoint;
    void stop();
};

template <typename T>
TRes assertTrue(const T& actual, const T& expected);
int checkDebFlag(int, char* []);

void TEST__acceleratedEratostenesSieve(void);
void PRTRE_acceleratedEratostenesSieve(int, int, std::chrono::duration<double>);
void TEST__simpleEratostenesSieve(void);
void PRTRE_simpleEratostenesSieve(int, int, std::chrono::duration<double>);
void TEST__bigNumStringSort(void);
void PRTRE_bigNumStringSort(TRes, int, std::vector<std::string>, std::vector<std::string>, std::vector<std::string>);
void TEST__makeaDifrence(void);
void PRTRE_beautifulTriplets (TRes, int, std::string, std::string, int, int );
void TEST__beautifulTriplets(void);
void PRTRE_beautifulTriplets (TRes, int, int, int, std::string, int, int, std::vector<int>, float);
void TEST__circularArrayRotation(void);
void PRTRE_circularArrayRotation (TRes, int, std::vector<int>, int, std::vector<int>, std::vector<int>, std::vector<int>);
void TEST__saveThePrisoner(void);
void PRTRE_saveThePrisoner(TRes, int, int, int, int, int, int);
void TEST__minimumDistances(void);
void TEST__minimumDistances(void);
void PRTRE_minimumDistances(TRes, int, std::vector<int>, std::string, int, int);
void TEST__missingNumbers(void);
void PRTRE_missingNumbers(TRes, int, std::vector<int>, std::vector<int>, std::vector<int>, std::vector<int>);
void TEST__intigerToDigitsVector(void);
void PRTRE_intigerToDigitsVector(TRes, int, int, std::vector<int>, std::vector<int>);
void TEST__intigerToIntigerReversed(void);
void PRTRE_intigerToIntigerReversed(TRes, int, int, int, int);
void TEST__decode_cipherVigenere(void);
void PRTRE_decode_cipherVigenere(TRes, int, std::string, std::string, std::string, std::string);
void TEST__decode_cipherBacon(void);
void PRTRE_decode_cipherBacon(TRes, int, std::string, std::string, std::string);

#endif





//wihitespace