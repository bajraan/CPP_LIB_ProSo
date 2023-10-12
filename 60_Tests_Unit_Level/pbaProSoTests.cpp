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

float Glob_testTimeResult_ms;
Timer::Timer()
{
    m_StartTimePoint = std::chrono::high_resolution_clock::now();
}
Timer::~Timer()
{
    stop();
}
void Timer::stop()
{
    m_EndTimePoint = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(m_EndTimePoint - m_StartTimePoint).count();
    Glob_testTimeResult_ms = duration;
}




int checkDebFlag(int argc, char* argv[])
{
    char* tmp = argv[1];
    for (int i = 1; i < argc; i++) {
        if (strcmp(tmp , "-deb") == 0) {
            debFlag = 1;return 1;
        }
    }
    debFlag=0;
    return 0;
}



void TEST__primes_EratostenesSieve (void)
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "TEST: primes_EratostenesSieve         " << std::endl;
    std::cout << "                             __SIMPLE " << std::endl;
    std::cout << "                             __ACC    " << std::endl;
    std::cout << "                             __NAIVE  " << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    struct tt
    {
        int       Test_id;
        int       sieveSize;
    }tmp;


    std::vector<tt> TestTab;
    //======================================//
    // TEST OWN                             //
    //======================================//
    tmp.Test_id   =  0;
    tmp.sieveSize =  1000000;
    TestTab.push_back(tmp);
    //======================================//
    // TEST OWN                             //
    //======================================//
    tmp.Test_id    =  1;
    tmp.sieveSize  =  98765432;
    TestTab.push_back(tmp);


    for(int i=0; i<(int)TestTab.size(); i++){
       
        long long MAX_SIZE = TestTab[i].sieveSize;

        std::vector<long long>isprime(MAX_SIZE , true);
        std::vector<long long>prime;
        std::vector<long long>SPF(MAX_SIZE);

        auto start = std::chrono::high_resolution_clock::now();

        primes_EratostenesSieve__ACC
        (
            isprime,
            prime,
            SPF
        );

        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> duration = end - start; 

        std::string funcVariant = "__ACC";
        PRTRE_primes_EratostenesSieve
        (   
            funcVariant,
            TestTab[i].Test_id,
            TestTab[i].sieveSize,
            duration
        );


        std::vector<bool>sieve(MAX_SIZE, true);

        start = std::chrono::high_resolution_clock::now();
        primes_EratostenesSieve__SIMPLE(sieve);
        end = std::chrono::high_resolution_clock::now(); 
        duration = end - start; 

        funcVariant = "__SIMPLE";
        PRTRE_primes_EratostenesSieve
        (   
            funcVariant,
            TestTab[i].Test_id,
            TestTab[i].sieveSize,
            duration
        );

        int n = MAX_SIZE;

        start = std::chrono::high_resolution_clock::now();
        primes_EratostenesSieve__NAIVE  (n);
        end = std::chrono::high_resolution_clock::now(); 
        duration = end - start; 

        funcVariant = "__NAIVE";
        PRTRE_primes_EratostenesSieve
        (   
            funcVariant,
            TestTab[i].Test_id,
            TestTab[i].sieveSize,
            duration
        );
    }     
}     



void TEST__bigNumStringSort(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TEST: bigNumStringSort           " << std::endl;
    std::cout << "---------------------------------" << std::endl;

    struct tt
    {
        int                       Test_id;
        std::vector<std::string>  unsorted;
        std::vector<std::string>  obs_out;
        std::vector<std::string>  exp_out; 
    }tmp;

    std::vector<tt> TestTab;
    //======================================//
    // TEST own                             //
    //======================================//
    tmp.Test_id  =  0;
    tmp.unsorted =  {"1","11","111","2","22","222"};
    tmp.exp_out  =  {"1","2","11","22","111","222"};
    TestTab.push_back(tmp);
    //======================================//
    // TEST own                             //
    //======================================//
    tmp.Test_id  =  0;
    tmp.unsorted =  {"1","1542659854848579132648577741","11","111","2","22","222"};
    tmp.exp_out  =  {"1","2","11","22","111","222","1542659854848579132648577741"};
    TestTab.push_back(tmp);

    for(int i=0; i<(int)TestTab.size(); i++){
       
        TRes TestResult = TRes::unknown;
        TestTab[i].obs_out = bigNumStringSort(TestTab[i].unsorted);
        TestResult = assertTrue(TestTab[i].obs_out,TestTab[i].exp_out);

        PRTRE_bigNumStringSort 
        (   
            TestResult,
            TestTab[i].Test_id,
            TestTab[i].unsorted,
            TestTab[i].obs_out,
            TestTab[i].exp_out 
        );
    }     
}



void TEST__makeaDifrence(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TEST: makeaDifrence              " << std::endl;
    std::cout << "---------------------------------" << std::endl;

    struct tt
    {
        int          Test_id;
        std::string  s1;
        std::string  s2;
        int          exp_out; //expected
        int          obs_out; //observed
    }tmp;

    std::vector<tt> TestTab;
    //======================================//
    // TEST own                             //
    //======================================//
    tmp.Test_id     =  0;
    tmp.s1          =  "abba";
    tmp.s2          =  "abba";
    tmp.exp_out  =  0;
    TestTab.push_back(tmp);
    //======================================//
    // TEST 15 From HackerRank page          //
    //======================================//
    tmp.Test_id     =  1;
    tmp.s1          =  "absdjkvuahdakejfnfauhdsaavasdlkj";
    tmp.s2          =  "djfladfhiawasdkjvalskufhafablsdkashlahdfa";
    tmp.exp_out  =  19;
    TestTab.push_back(tmp);

    for(int i=0; i<(int)TestTab.size(); i++){
       
        TRes TestResult = TRes::unknown;
        TestTab[i].obs_out = makeaDifrence(TestTab[i].s1,TestTab[i].s2) ;
        TestResult = assertTrue(TestTab[i].obs_out,TestTab[i].exp_out);

        PRTRE_beautifulTriplets 
        (   
            TestResult,
            TestTab[i].Test_id,
            TestTab[i].s1,
            TestTab[i].s2,
            TestTab[i].obs_out,
            TestTab[i].exp_out 
        );
    }     
}

void TEST__beautifulTriplets(void)
{
    std::cout << "---------------------------------" << std::endl;
    std::cout << "TEST: beautifulTriplets          " << std::endl;
    std::cout << "                      __OTH_1    " << std::endl;
    std::cout << "                      __PBA_1    " << std::endl;
    std::cout << "                      __GPT_1    " << std::endl;
    std::cout << "                      __GPT_2    " << std::endl;
    std::cout << "---------------------------------" << std::endl;

    typedef int(*FunctionPtr)(int, std::vector<int>);

    struct tt
    {
        int               Test_id;
        int               d;
        std::vector<int>  arr;
        int               exp_output;
    }tmp;

    std::vector<std::pair<FunctionPtr,std::string>> FunctionVariant;
    FunctionVariant.push_back(std::make_pair(&beautifulTriplets__OTH_1,"__OTH_1"));
    FunctionVariant.push_back(std::make_pair(&beautifulTriplets__PBA_1,"__PBA_1"));
    FunctionVariant.push_back(std::make_pair(&beautifulTriplets__GPT_1,"__GPT_1"));
    FunctionVariant.push_back(std::make_pair(&beautifulTriplets__GPT_2,"__GPT_2"));

    std::vector<tt> TestTab;
    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    tmp.Test_id     =  0;
    tmp.d           =  3;
    tmp.arr         = { 7, 7, 10, 13 };
    tmp.exp_output  =  2;
    TestTab.push_back(tmp);
    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    tmp.Test_id    =  1;
    tmp.d          =  1;
    tmp.arr        = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100 };
    tmp.exp_output =  98;
    TestTab.push_back(tmp);
    // space for reading test from files




    for(int i=0; i<(int)TestTab.size(); i++){
        for(int j=0; j<(int)FunctionVariant.size(); j++){

            std::string testedVersionText = FunctionVariant[i].second;
            TRes TestResult = TRes::unknown;
            std::string jacek;
            int out, exp;
            
            std::chrono::time_point<std::chrono::high_resolution_clock> start;
            std::chrono::time_point<std::chrono::high_resolution_clock> end;
            {
                Timer Time;
            
            start = std::chrono::high_resolution_clock::now();
            out = FunctionVariant[j].first(TestTab[i].d, TestTab[i].arr);
            end = std::chrono::high_resolution_clock::now();
            
            }

                std::time_t start_time = std::chrono::system_clock::to_time_t(start);
                std::time_t end_time = std::chrono::system_clock::to_time_t(end);
                std::cout << std::endl;
                std::cout << "Start time: " << std::ctime(&start_time);
                std::cout << "End time: " << std::ctime(&end_time);
                std::cout << std::endl;
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
            std::cout << std::endl;
            std::cout << "classtimer:" << Glob_testTimeResult_ms << std::endl;
            std::cout << "Czas trwania: " << duration << " mikrosekund." << std::endl;

            exp = TestTab[i].exp_output;
            TestResult = assertTrue(out,exp);

            PRTRE_beautifulTriplets 
                (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].d,
                TestTab[i].arr.size(),
                FunctionVariant[j].second,
                out, 
                exp,
                TestTab[i].arr,
                Glob_testTimeResult_ms
                );
        }
    }     
}



void TEST__circularArrayRotation(void)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: circularArrayRotation " << std::endl;
    std::cout << "----------------------------" << std::endl;

    const int t_cnt = 2;

    struct tt
    {
        int              Test_id;
        std::vector<int> a;
        int              k;
        std::vector<int> queries;            
        std::vector<int> exp_output;
    };


    tt TestTab[t_cnt];

    //======================================//
    // TEST 0 From HackerRank page          //
    //======================================//
    TestTab[0].Test_id = 0;
    TestTab[0].a.insert(TestTab[0].a.end(), {1, 2, 3,});
    TestTab[0].k = 2;
    TestTab[0].queries.insert(TestTab[0].queries.end(), {0, 1, 2,});
    TestTab[0].exp_output.insert(TestTab[0].exp_output.end(), {2, 3, 1});

    //======================================//
    // TEST 1 From HackerRank page          //
    //======================================//
    TestTab[1].Test_id = 1;
    TestTab[1].a.insert(TestTab[1].a.end(), {8, 2, 7, 3, 3, 1, 9, 7});
    TestTab[1].k = 18;
    TestTab[1].queries.insert(TestTab[1].queries.end(), {7, 2, 0});
    TestTab[1].exp_output.insert(TestTab[1].exp_output.end(), {1, 8, 9});


    for(int i=0; i<t_cnt; i++)
    {
        TRes TestResult = TRes::unknown;
        std::vector<int> out = circularArrayRotation(TestTab[i].a, TestTab[i].k, TestTab[i].queries);
        std::vector<int> exp = TestTab[i].exp_output;
        TestResult = assertTrue(out,exp);

        PRTRE_circularArrayRotation 
            (   
                TestResult,
                TestTab[i].Test_id,
                TestTab[i].a,
                TestTab[i].k,
                TestTab[i].queries,
                out, 
                exp
            );
    }    
}

void TEST__saveThePrisoner(void)
{
    std::cout << "----------------------------" << std::endl;
    std::cout << "TEST: saveThePrisoner       " << std::endl;
    std::cout << "----------------------------" << std::endl;

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


void PRTRE_primes_EratostenesSieve
(
    std::string                   functionVariant,
    int                           Test_id,
    int                           size, 
    std::chrono::duration<double> duration
)
{   
    if(debFlag)
    {   
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "F_var :" << functionVariant  << std::endl;
        std::cout << "T_id  :" << Test_id          << std::endl;
        std::cout << "size  :" << size             << std::endl;
        std::cout << "time  :" << duration.count() << std::endl;
    }   
}





void PRTRE_bigNumStringSort 
(   
    TRes                     TestResult,
    int                      Test_id,
    std::vector<std::string> unsorted,
    std::vector<std::string> obs_out,
    std::vector<std::string> exp_out 
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
    std::cout << "unsorted :"; std::cout<<std::endl; for(auto el : unsorted) std::cout<<el<<std::endl;
    std::cout << "obs :";      std::cout<<std::endl; for(auto el : obs_out ) std::cout<<el<<std::endl;
    std::cout << "exp :";      std::cout<<std::endl; for(auto el : exp_out ) std::cout<<el<<std::endl;
    }    
}



void PRTRE_beautifulTriplets 
(   
    TRes        TestResult,
    int         Test_id,
    std::string s1,
    std::string s2,
    int         obs,
    int         exp 
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
        std::cout << "s1  :"; std::cout << s1  << " "  ; std::cout << std::endl;
        std::cout << "s2  :"; std::cout << s2  << " "  ; std::cout << std::endl;
        std::cout << "out :"; std::cout << obs << " "  ; std::cout << std::endl;
        std::cout << "exp :"; std::cout << exp << " "  ; std::cout << std::endl;
    }   
}



void PRTRE_beautifulTriplets 
(   
    TRes                TestResult,
    int                 Test_id,
    int                 d,
    int                 arrSize,
    std::string         testedVersionText,
    int                 out, 
    int                 exp,
    std::vector<int>    arr,
    float               timeRes_ms
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
    std::cout << "d    :";                   std::cout << d          << " "  ; std::cout << std::endl;
    std::cout << "arr  :"; for(int el : arr) std::cout << el         << " "  ; std::cout << std::endl;
    std::cout << "out  :";                   std::cout << out        << " "  ; std::cout << std::endl;
    std::cout << "exp  :";                   std::cout << exp        << " "  ; std::cout << std::endl;
    std::cout << "time :";                   std::cout << std::fixed << std::setprecision(6) << timeRes_ms << " ms"; std::cout << std::endl;
    }
}



void PRTRE_circularArrayRotation 
(   
    TRes             TestResult,
    int              Test_id,
    std::vector<int> a,
    int              k,
    std::vector<int> queries,
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
    std::cout << "a      :"; for(int el : a      ) std::cout << el   << " "; std::cout << std::endl;
    std::cout << "k      :";                       std::cout << k    << " "; std::cout << std::endl;
    std::cout << "queries:"; for(int el : queries) std::cout << el   << " "; std::cout << std::endl;
    std::cout << "out    :"; for(int el : out    ) std::cout << el   << " "; std::cout << std::endl;
    std::cout << "exp    :"; for(int el : exp    ) std::cout << el   << " "; std::cout << std::endl;
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
    std::cout << "n  : ";   std::cout << n    << " "; std::cout << std::endl;
    std::cout << "m  : ";   std::cout << m    << " "; std::cout << std::endl;
    std::cout << "s  : ";   std::cout << s    << " "; std::cout << std::endl;
    std::cout << "out: ";   std::cout << out  << " "; std::cout << std::endl;
    std::cout << "exp: ";   std::cout << exp  << " "; std::cout << std::endl;
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