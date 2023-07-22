#include "60_Tests_Unit_Level/pbaProSoTests.hpp"

int main(int argc, char* argv[]) {


    setFlags(argc,argv);

    preConditions();



    postConditions();

    TEST__decode_cipherVigenere();
    TEST__decode_cipherBacon();
    TEST__missingNumbers();
    TEST__intigerToDigitsVector();
    TEST__minimumDistances();
    TEST__intigerToIntigerReversed();
    TEST__saveThePrisoner();

    return 0;
}