#include "pbaProSoTests.hpp"
#include "../00_pbaProSo/pbaProso.hpp"

#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define TEST_PASS   SetConsoleTextAttribute(hConsole,10);std::cout<<"PASS";SetConsoleTextAttribute(hConsole,7);
#define TEST_FAIL   SetConsoleTextAttribute(hConsole,12);std::cout<<"FAIL";SetConsoleTextAttribute(hConsole,7);
#define TEST_UNKN   SetConsoleTextAttribute(hConsole,14);std::cout<<"UNKNOWN";SetConsoleTextAttribute(hConsole,7);


template <typename T>
TRes assertTrue(const T& actual, const T& expected) {
    if (actual == expected) {
        return TRes::pass;
    } else {
        return TRes::fail;
    }
}

bool checkDebFlag(int argc, char* argv[])
{

    char* tmp = argv[1];
    for (int i = 1; i < argc; i++) {
        
        if (strcmp(tmp , "-deb") == 0) {
            return true;
        }
    }
    return false;
}

void printResult(TRes TestResult, std::string inp, std::string out, std::string exp, bool debFlag)
{   
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }
    if(debFlag)
        std::cout << " " << inp << " -> " 
                         << out << " -> " 
                         << exp;
    std::cout << std::endl;
}


void TEST__decode_cipherVigenere( void )
{
    
}
void TEST__timeConversion(bool debFlag)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: timeConversion    " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 3;

    struct tt
    {
        std::string input;
        std::string exp_output;
    };

    tt TestTab[t_cnt]
{
//==============================|
// TEST TABLE                   |
//==============================|
//    INPUT    |    EXPECTED    |
  "12:01:00PM" ,   "12:01:00",
  "12:01:00AM" ,   "00:01:00",
  "07:05:45PM" ,   "19:05:45"
};
    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::string out = timeConversion(TestTab[i].input);
        std::string exp = TestTab[i].exp_output;

        TestResult = assertTrue(out,exp);

        printResult(TestResult,TestTab[i].input, out,exp,debFlag);

    }
}