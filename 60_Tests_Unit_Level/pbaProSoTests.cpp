#include "pbaProSoTests.hpp"
#include "../00_pbaProSo/pbaProso.hpp"

#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define TEST_PASS   SetConsoleTextAttribute(hConsole,10);std::cout<<"PASS";SetConsoleTextAttribute(hConsole,7);
#define TEST_FAIL   SetConsoleTextAttribute(hConsole,12);std::cout<<"FAIL";SetConsoleTextAttribute(hConsole,7);
#define TEST_UNKN   SetConsoleTextAttribute(hConsole,14);std::cout<<"UNKNOWN";SetConsoleTextAttribute(hConsole,7);

bool debFlag;
bool printRaport2htmlFlag;
std::vector<std::string> containerFlag;
std::stringstream raportHtmlBuf;

template <typename T>
TRes assertTrue(const T& actual, const T& expected) {
    if (actual == expected) {
        return TRes::pass;
    } else {
        return TRes::fail;
    }
}

void setFlags(int argc, char* argv[])
{
    // branch test
    debFlag=0;
    printRaport2htmlFlag=0;

    for (int i = 1; i < argc; i++) 
    {
        containerFlag.push_back(argv[i]);
        if (strcmp(argv[i] , "-deb") == 0) debFlag = 1;
        if (strcmp(argv[i] , "-print") == 0) printRaport2htmlFlag = 1;
    }
}


void preConditions(void)
{
    std::cout << std::endl << std::endl;
    std::cout << "=============================="<< std::endl;
    std::cout << "pbaProSo library Test Program "<< std::endl;
    std::cout << "=============================="<< std::endl;
    std::cout << "Flags:" << std::endl;
    for(std::string Flag : containerFlag)
    std::cout << "   -> "<< Flag << std::endl;
    std::cout << "=============================="<< std::endl;


    if(printRaport2htmlFlag)
    {
        raportHtmlBuf << "<html>"                       << std::endl;
        raportHtmlBuf << "<head>"                       << std::endl;
        raportHtmlBuf << "  <title>TITLE</title>"       << std::endl;
        raportHtmlBuf << "  <style>"                    << std::endl;
        raportHtmlBuf << "  body {"                     << std::endl;
        raportHtmlBuf << "    background-color: #111;"  << std::endl;
        raportHtmlBuf << "    color: #fff;"             << std::endl;
        raportHtmlBuf << "  }"                          << std::endl;
        raportHtmlBuf << "  </style>"                   << std::endl;
        raportHtmlBuf << "</head>"                      << std::endl;
        raportHtmlBuf << "<body>"                       << std::endl;
        raportHtmlBuf << "<h1>Test Raport</h1>"         << std::endl;
        raportHtmlBuf << "<p>"                          << std::endl;
        raportHtmlBuf << "==============================</br>" << std::endl;
        raportHtmlBuf << "pbaProSo library Test Program </br>" << std::endl;
        raportHtmlBuf << "==============================</br>" << std::endl;
        raportHtmlBuf << "Flags:                        </br>" << std::endl;
        for(std::string Flag : containerFlag)
        raportHtmlBuf << "   -> "<< Flag <<            "</br>" << std::endl;
        raportHtmlBuf << "==============================</br>" << std::endl;
        raportHtmlBuf << "</p>" << std::endl;
        raportHtmlBuf << "</body></html>" << std::endl;
    }

}

void postConditions(void)
{
    if(printRaport2htmlFlag)
    {

        std::ofstream outputFile("output.html");
        outputFile << raportHtmlBuf.str();
        outputFile.close();
    }
}



void TEST__saveThePrisoner(void)
{
    const int t_cnt = 4;

    struct tt
    {
        int     Test_id;
        int     n;
        int     m;
        int     s;            
        int     exp_output;
    };


    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    TestTab[0].Test_id = 0;
    TestTab[0].n = 5;
    TestTab[0].m = 2;
    TestTab[0].s = 1;
    TestTab[0].exp_output = 2;

    //======================================//
    // TEST 1 Own test                      //
    //======================================//
    TestTab[1].Test_id = 1;
    TestTab[1].n = 5;
    TestTab[1].m = 2;
    TestTab[1].s = 2;
    TestTab[1].exp_output = 3;

    //======================================//
    // TEST 2 Own test                      //
    //======================================//
    TestTab[2].Test_id = 2;
    TestTab[2].n = 3;
    TestTab[2].m = 7;
    TestTab[2].s = 3;
    TestTab[2].exp_output = 3;

    //======================================//
    // TEST 3 Own test                      //
    //======================================//
    TestTab[3].Test_id = 3;
    TestTab[3].n = 7;
    TestTab[3].m = 19;
    TestTab[3].s = 2;
    TestTab[3].exp_output = 6;

    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        int out = saveThePrisoner(TestTab[i].n, TestTab[i].m, TestTab[i].s);
        int exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_saveThePrisoner 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].n,
                TestTab[i].m,
                TestTab[i].s,
                out, 
                exp
            );
    } 
}



void TEST__minimumDistances(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TEST: minimumDistances           " << std::endl;
    std::cout << "                      __PBA_1    " << std::endl;
    std::cout << "                      __GPT_1    " << std::endl;
    std::cout << "---------------------------------" << std::endl;

    const int t_cnt = 5;

    struct tt
    {
        int               Test_id;
        std::vector<int>  a;
        int               exp_output;
    };

    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    TestTab[0].Test_id                     =  0;
    TestTab[0].a.insert(TestTab[0].a.end(), { 7, 1, 3, 4, 1, 7 });
    TestTab[0].exp_output                  =  3;

    //======================================//
    // TEST 1 Own Test                      //
    //======================================//
    TestTab[1].Test_id                     =  1;
    TestTab[1].a.insert(TestTab[1].a.end(), { 0, 1, 3, 4, 1, 7, 9, 2, 3, 1, 0, 6, 7, 8, 9, 0, 6, 7, 8, 9, 0 });
    TestTab[1].exp_output                  =  3;

    //======================================//
    // TEST 2 Own Test                      //
    //======================================//
    TestTab[2].Test_id                     =  2;
    TestTab[2].a.insert(TestTab[2].a.end(), { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 });
    TestTab[2].exp_output                  =  1;

    //======================================//
    // TEST 3 Own Test                      //
    //======================================//
    TestTab[3].Test_id                     =  3;
    TestTab[3].a.insert(TestTab[3].a.end(), {  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 
                                              22,23,24,25,26,27,28,29 });
    TestTab[3].exp_output                  =  -1;

    //======================================//
    // TEST 4 Own Test                      //
    //======================================//
    TestTab[4].Test_id                     =  4;
    TestTab[4].a.insert(TestTab[4].a.end(), { -1,-2,-4, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 
                                              22,23,24,25,26,27,28,29 });
    TestTab[4].exp_output                  =  -1;


    for(int i=0; i<t_cnt; i++)
    {
        int out,exp;
        TRes TestResult;
        std::string testedVersionText;

        testedVersionText = "__PBA_1";
        TestResult = TRes::unknown;
        out = minimumDistances__PBA_1(TestTab[i].a);
        exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_minimumDistances 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].a,
                testedVersionText,
                out, 
                exp
            );

        testedVersionText = "__GPT_1";
        TestResult = TRes::unknown;
        out = minimumDistances__GPT_1(TestTab[i].a);
        exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_minimumDistances 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].a,
                testedVersionText,
                out, 
                exp
            );
    }     
}



void TEST__intigerToDigitsVector(void)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: intigerToDigitsVector " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 2;

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

    //======================================//
    // TEST 1 Own test                      //
    //======================================//
    TestTab[1].Test_id = 1;
    TestTab[1].n = 1;
    TestTab[1].exp_output.insert(TestTab[1].exp_output.end(), {1});

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



void TEST__intigerToIntigerReversed(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TEST: intigerToIntigerReversed   " << std::endl;
    std::cout << "---------------------------------" << std::endl;

    const int t_cnt = 7;

    struct tt
    {
        int Test_id;
        int n;
        int exp_output;
    };

    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 Own test                      //
    //======================================//
    TestTab[0].Test_id = 0;
    TestTab[0].n = 12345;
    TestTab[0].exp_output = 54321; 

    //======================================//
    // TEST 1 From HackerRank page          //
    //======================================//
    TestTab[1].Test_id = 1;
    TestTab[1].n = 987654;
    TestTab[1].exp_output = 456789;  

    //======================================//
    // TEST 2 Own test                      //
    //======================================//
    TestTab[2].Test_id = 2;
    TestTab[2].n = 1219;
    TestTab[2].exp_output = 9121;

    //======================================//
    // TEST 3 Own test                      //
    //======================================//
    TestTab[3].Test_id = 3;
    TestTab[3].n = 1;
    TestTab[3].exp_output = 1;   

    //======================================//
    // TEST 4 Own test                      //
    //======================================//
    TestTab[4].Test_id = 4;
    TestTab[4].n = 0;
    TestTab[4].exp_output = 0;   

    //======================================//
    // TEST 5 Own test                      //
    //======================================//
    TestTab[5].Test_id = 5;
    TestTab[5].n = 10000;
    TestTab[5].exp_output = 1;   

    //======================================//
    // TEST 6 Own test                      //
    //======================================//
    TestTab[6].Test_id = 6;
    TestTab[6].n = -479;
    TestTab[6].exp_output = -974;  



    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        int out = intigerToIntigerReversed (TestTab[i].n);
        int exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_intigerToIntigerReversed 
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



void PRTRE_saveThePrisoner 
(   
    TRes    TestResult,
    int     Test_id,
    int     n,
    int     m,
    int     s,
    int     out, 
    int     exp
)
{
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }   std::cout << std::endl;

    if(debFlag)
    {
        std::cout << "n  : " << n    <<  std::endl;
        std::cout << "m  : " << m    <<  std::endl;
        std::cout << "s  : " << s    <<  std::endl;
        std::cout << "out: " << out  <<  std::endl;
        std::cout << "exp: " << exp  <<  std::endl;
    }
    if(printRaport2htmlFlag)
    {
        raportHtmlBuf << "----------------------------</br>" << std::endl;
        raportHtmlBuf << "TEST: saveThePrisoner       </br>" << std::endl;
        raportHtmlBuf << "----------------------------</br>" << std::endl;
        raportHtmlBuf << "Test_id: " << Test_id << " ";
        if(TestResult == TRes::pass) raportHtmlBuf << "TEST_PASS</br>" << std::endl;
        if(TestResult == TRes::fail) raportHtmlBuf << "TEST_FAIL</br>" << std::endl;
        raportHtmlBuf << "n  : " << n    << "</br>" <<  std::endl;
        raportHtmlBuf << "m  : " << m    << "</br>" <<  std::endl;
        raportHtmlBuf << "s  : " << s    << "</br>" <<  std::endl;
        raportHtmlBuf << "out: " << out  << "</br>" <<  std::endl;
        raportHtmlBuf << "exp: " << exp  << "</br>" <<  std::endl;
    }
}



void PRTRE_intigerToIntigerReversed 
(   
    TRes    TestResult,
    int     Test_id,
    int     in,
    int     out, 
    int     exp
)
{
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }   std::cout << std::endl;

    if(debFlag)
    {
    std::cout << "in  :";   std::cout << in   << " "; std::cout << std::endl;
    std::cout << "out :";   std::cout << out  << " "; std::cout << std::endl;
    std::cout << "exp :";   std::cout << exp  << " "; std::cout << std::endl;
    }
}


void PRTRE_minimumDistances
(
    TRes             TestResult,
    int              Test_id,
    std::vector<int> a,
    std::string      testedVersionText,
    int              out, 
    int              exp
)
{
    std::cout << "Test_id: " << Test_id << " ";
    switch(TestResult)
    {
        case TRes::pass:    TEST_PASS break;
        case TRes::fail:    TEST_FAIL break;
        default:            TEST_UNKN break;
    }
    std::cout << " Ver: " << testedVersionText << std::endl;

    if(debFlag)
    {
    std::cout << "a   :"; for(int el : a  ) std::cout << el   << " "; std::cout << std::endl;
    std::cout << "out :";                   std::cout << out  << " "; std::cout << std::endl;
    std::cout << "exp :";                   std::cout << exp  << " "; std::cout << std::endl;
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
    }   std::cout << std::endl;

    if(debFlag)
    {
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
    }   std::cout << std::endl;

    if(debFlag)
    {
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
    }   std::cout << std::endl;

    if(debFlag)
         
    std::cout     << "Cipher  : " << inp    << std::endl
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
    }   std::cout << std::endl;

    if(debFlag)

    std::cout << "Cipher  : " << inp    << std::endl
              << "out     : " << out    << std::endl
              << "exp_out : " << exp    << std::endl;
}