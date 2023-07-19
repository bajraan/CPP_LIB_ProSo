#include "60_Tests_Unit_Level/pbaProSoTests.hpp"

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
    TEST__decode_cipherVigenere();
    TEST__decode_cipherBacon();
    TEST__missingNumbers();
    TEST__intigerToDigitsVector();
    TEST__minimumDistances();
    TEST__intigerToIntigerReversed();
    return 0;
}