#include "pbaProSoTests.hpp"
#include "../00_pbaProSo/pbaProso.hpp"

#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define TEST_PASS   SetConsoleTextAttribute(hConsole,10);std::cout<<"PASS";SetConsoleTextAttribute(hConsole,7);
#define TEST_FAIL   SetConsoleTextAttribute(hConsole,12);std::cout<<"FAIL";SetConsoleTextAttribute(hConsole,7);
#define TEST_UNKN   SetConsoleTextAttribute(hConsole,14);std::cout<<"UNKNOWN";SetConsoleTextAttribute(hConsole,7);

bool debFlag;

template <typename T>
TRes assertTrue(const T& actual, const T& expected) {
    if (actual == expected) {
        return TRes::pass;
    } else {
        return TRes::fail;
    }
}

int checkDebFlag(int argc, char* argv[])
{
    char* tmp = argv[1];
    for (int i = 1; i < argc; i++) 
    {
        if (strcmp(tmp , "-deb") == 0) {
            debFlag = 1;return 1;
        }
    }
    debFlag=0;return 0;
}


void TEST__intigerToDigitsVector(void)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: intigerToDigitsVector " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 1;

    struct tt
    {
        int              Test_id;
        int              n;
        std::vector<int> exp_output;
    };


    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    TestTab[0].Test_id = 0;
    TestTab[0].n = 123456;
    TestTab[0].exp_output.insert(TestTab[0].exp_output.end(), {6,5,4,3,2,1});

    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::vector<int> out = intigerToDigitsVector(TestTab[i].n);
        std::vector<int> exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_intigerToDigitsVector 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].n,
                out, 
                exp
            );
    } 
}

void TEST__missingNumbers(void)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: missingNumbers        " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 3;

    struct tt
    {
        int              Test_id;
        std::vector<int> arr;
        std::vector<int> brr;
        std::vector<int> exp_output;
    };


    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 Own test                      //
    //======================================//
    TestTab[0].Test_id = 0;
    TestTab[0].arr.insert(TestTab[0].arr.end(), {203, 204, 205, 206, 207, 208, 203, 204, 205, 206});
    TestTab[0].brr.insert(TestTab[0].brr.end(), {203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204});
    TestTab[0].exp_output.insert(TestTab[0].exp_output.end(), {204, 205, 206});

    //======================================//
    // TEST 1 From HackerRank page          //
    //======================================//
    TestTab[1].Test_id = 1;
    TestTab[1].arr.insert(TestTab[1].arr.end(), {11, 4, 11, 7, 13, 4, 12, 11, 10, 14});
    TestTab[1].brr.insert(TestTab[1].brr.end(), {11, 4, 11, 7, 3, 7, 10, 13, 4, 8, 12, 11, 10, 14, 12});
    TestTab[1].exp_output.insert(TestTab[1].exp_output.end(), {3, 7, 8, 10, 12});

    //======================================//
    // TEST 2 Own test                      //
    //======================================//
    TestTab[2].Test_id = 2;
    TestTab[2].arr.insert(TestTab[2].arr.end(), {1, 1, 2, 2, 100});
    TestTab[2].brr.insert(TestTab[2].brr.end(), {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 100});
    TestTab[2].exp_output.insert(TestTab[2].exp_output.end(), {1, 2, });   

    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::vector<int> out = missingNumbers (TestTab[i].arr, TestTab[i].brr);
        std::vector<int> exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_missingNumbers 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].arr,
                TestTab[i].brr,
                out, 
                exp
            );
    } 
}



void TEST__decode_cipherVigenere( void )
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: decode_cipherVigenere " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 1;

    struct tt
    {
        int         Test_id;
        std::string cipher;
        std::string key;
        std::string exp_output;
    };

    tt TestTab[t_cnt]
    {
    //======================================//
    // TEST TABLE                           //
    //======================================//==TEST1==
    1,
    "gwox{RgqssihYspOntqpxs}",              //cipher
    "blorpy",                               //key
    "flag{CiphersAreAwesome}"               //ex_output
    };

    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::string out = decode_cipherVigenere(TestTab[i].cipher, TestTab[i].key);
        std::string exp = TestTab[i].exp_output;

        TestResult = assertTrue(out,exp);

        PRTRE_decode_cipherVigenere 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].cipher,
                TestTab[i].key, 
                out, 
                exp
            );
    }    
}



void TEST__decode_cipherBacon(void)
{
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "TEST: decode_cipherBacon (string,char,char)     " << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    const int t_cnt = 2;

    struct tt
    {
        int           Test_id;
        OTyp          Overload_type;
        std::string   cipher;
        char          A;
        char          B;
        std::string   exp_output;
    };

    tt TestTab[t_cnt]
    {
    //=========================================================================================//
    // TEST TABLE                                                                              //
    //=========================================================================================//==TEST1==
    1,
    OTyp::_stringcharchar_,
    "ABAAAABABAABBABBAABBAABAAAAAABAAAAAAAABAABBABABBAAAAABBABBABABBAABAABABABBAABBABBAABB",   //cipher
    'A',
    'B',
    "ilouebacondontyou",                                                                       //ex_output
    //=========================================================================================//==TEST2==
    2,
    OTyp::_string_,
    "ABAAAABABAABBABBAABBAABAAAAAABAAAAAAAABAABBABABBAAAAABBABBABABBAABAABABABBAABBABBAABB",   //cipher
    'x',
    'x',
    "ilouebacondontyou"                                                                        //ex_output
    };

    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::string out, exp;

        switch(TestTab[i].Overload_type)
        {
            case(OTyp::_stringcharchar_) : 
                out = decode_cipherBacon(TestTab[i].cipher, TestTab[i].A ,TestTab[i].B);
                break;

            case(OTyp::_string_) :
                out = decode_cipherBacon(TestTab[i].cipher);
                break;

            default :
                std::cout << "error" << std::endl;
                break;
        }

        out = decode_cipherBacon(TestTab[i].cipher);

        exp = TestTab[i].exp_output;

        TestResult = assertTrue(out,exp);

        PRTRE_decode_cipherBacon 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].cipher,
                out, 
                exp
            );
    }    
}


void PRTRE_intigerToDigitsVector 
(   
    TRes             TestResult,
    int              Test_id,
    int              n,
    std::vector<int> out, 
    std::vector<int> exp
)
{
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }

    if(debFlag)
    {
    std::cout <<                                                                     std::endl;
    std::cout << "n       :";                   std::cout << n  << " "; std::cout << std::endl;
    std::cout << "out     :"; for(int el : out) std::cout << el << " "; std::cout << std::endl;
    std::cout << "exp_out :"; for(int el : exp) std::cout << el << " "; std::cout << std::endl;
    }
}



void PRTRE_missingNumbers 
(   
    TRes             TestResult,
    int              Test_id,
    std::vector<int> arr,
    std::vector<int> brr,
    std::vector<int> out, 
    std::vector<int> exp
)
{
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }

    if(debFlag)
    {
    std::cout <<                                                                     std::endl;
    std::cout << "arr     :"; for(int el : arr) std::cout << el << " "; std::cout << std::endl;
    std::cout << "brr     :"; for(int el : brr) std::cout << el << " "; std::cout << std::endl;
    std::cout << "out     :"; for(int el : out) std::cout << el << " "; std::cout << std::endl;
    std::cout << "exp_out :"; for(int el : exp) std::cout << el << " "; std::cout << std::endl;
    }
    std::cout << std::endl;
}
//===========================================================
// Print Result of decode_cipherVigenere function
//===========================================================
void PRTRE_decode_cipherVigenere
(   
        TRes        TestResult,
        int         Test_id, 
        std::string inp,
        std::string key, 
        std::string out, 
        std::string exp
)
{   
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }

    if(debFlag)
        std::cout                           << std::endl
                  << "Cipher  : " << inp    << std::endl
                  << "Key     : " << key    << std::endl
                  << "out     : " << out    << std::endl
                  << "exp_out : " << exp    << std::endl;

    std::cout << std::endl;
}



//===========================================================
// Print Result of decode_cipherBacon function
//===========================================================
void PRTRE_decode_cipherBacon
(   
        TRes        TestResult,
        int         Test_id, 
        std::string inp,
        std::string out, 
        std::string exp
)
{   
    std::cout << "Test_id: " << Test_id << " ";

    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }

    if(debFlag)
        std::cout                           << std::endl
                  << "Cipher  : " << inp    << std::endl
                  << "out     : " << out    << std::endl
                  << "exp_out : " << exp    << std::endl;

    std::cout << std::endl;
}