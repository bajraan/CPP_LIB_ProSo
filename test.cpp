#include "60_Tests_Unit_Level/pbaProSoTests.hpp"

void TEST_ALL(void);

int main(int argc, char* argv[]) {

    std::cout << std::endl << std::endl;
    std::cout << "=============================="<< std::endl;
    std::cout << "pbaProSo library Test Program"<< std::endl;
    std::cout << "=============================="<< std::endl;
    std::cout << "Flags:" << std::endl;
    for(int i=0; i<argc; i++)
    std::cout <<i<<" : "<< argv[i] << std::endl;
    std::cout << "============================"<< std::endl;

    checkDebFlag(argc,argv);


    //TEST__ALL();
    TEST__primes_EratostenesSieve();


    return 0;
}


void TEST__ALL()
{
    TEST__decode_cipherVigenere();
    TEST__decode_cipherBacon();
    TEST__missingNumbers();
    TEST__intigerToDigitsVector();
    TEST__minimumDistances();
    TEST__intigerToIntigerReversed();
    TEST__saveThePrisoner();
    TEST__circularArrayRotation();
    TEST__beautifulTriplets();
    TEST__makeaDifrence();
    TEST__bigNumStringSort();
}