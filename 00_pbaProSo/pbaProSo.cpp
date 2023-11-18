#include "pbaProSo.hpp"

void    test(void)
{
    std::cout << "Library compilation - PASS" << std::endl;
}

bool    isPrime
(
    const int n
)
{
    if(n<2) return false;

    if(n==2 || n==3) return true;

    if(n%2==0 || n%3==0) return false;
    
    for(int i =5; i*i < n; i+=6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}



void    primes_EratostenesSieve__BASE
(
    std::vector<bool>& sieve
)
{

}



void    simpleSieve
(
    int              limit, 
    std::vector<int> &prime
)
{
	using namespace std;
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    vector<bool> mark(limit + 1, true);
 
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            //cout << p << " ";
        }
    }
}

void    primes_EratostenesSieve__NAIVE(int n)
{
	using namespace std;
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        if (high >= n)
           high = n;
         
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < (int)prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        //for (int i = low; i<high; i++)
         //   if (mark[i - low] == true)
          //      cout << i << " ";
 
        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}


void primes_EratostenesSieve_SSIMPLE   (unsigned long long size )
{
	std::vector<bool>sieve(size, true);
	sieve[0] = false;
	sieve[1] = false;
	for(unsigned long long i=2; i<size; i++){
		if(sieve[i] != false ){
			for(unsigned long long j=2*i; j<size; j+=i){
					sieve[j] = false;
			}
		}
	}
}


void primes_EratostenesSieve__SIMPLE   (std::vector<bool>& sieve)
{
	long long size = sieve.size();
	sieve[0] = false;
	sieve[1] = false;
	
	for(long long i=2; i<size; i++){
		if(sieve[i] != false ){
			for(long long j=2*i; j<size; j+=i){
					sieve[j] = false;
			}
		}
	}
}

void primes_EratostenesSieve__ACC
(
	std::vector<long long>& isprime,
	std::vector<long long>& prime,
	std::vector<long long>& SPF
)
{
	int N = isprime.size();

    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++)
    {
        if (isprime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
 
        for 
        (	
        	long long int j=0;
            j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i];
            j++
        )
        {
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}



/**
 * 
 * Solution for Big Sorting problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/big-sorting/problem?isFullScreen=true
 * 
 * @param  vector<string> unsorted 	array of unsorted string
 * @return vector<string> 			array of sorted string
 * 
 * @example unsorted: "3" "45" "123" "1" "11" "111"
 * 			ret	   -> "1" "3" "11" "45" "111" "123"
 * 
 * @example unsorted: "1" "11" "111" "2" "22" "222"
 * 			ret	   -> "1" "2" "11" "22" "111" "222"
 * 
 */
std::vector<std::string> bigNumStringSort(std::vector<std::string> unsorted) {

	struct strAlphaNumaComparator 
	{
    	bool operator()(const std::string& str1, const std::string& str2) const {
        if (str1.length() != str2.length())
            	return str1.length() < str2.length();
        return str1 < str2;
    	}
	};

    std::multiset<std::string,strAlphaNumaComparator> mySet;
    std::vector<std::string> ret;
    for(auto el : unsorted) mySet.insert(el);
    for(auto el : mySet) ret.push_back(el);
    return ret;
}

/**
 * 
 * Solution for Making Anagrams problem.
 *
 *  -> How many letters do you need to remove for both strings to become identical? 
 * 
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/making-anagrams/problem
 * 
 * @param  string s1	first string
 * @param  string s2    second string
 * @return int 			return the numeric value of differences between two strings
 * 
 * @example s1: "abba" 
 * 			s2: "abba"
 * 		ret ->: 0
 * 
 * @example s1: "abbaqwe" 
 * 			s2: "abbaplm"
 * 		ret ->: 6
 * 
 */
int makeaDifrence(std::string s1, std::string s2) {
    int ret = 0;
    std::map<char, int> base;
    for(char zn = 'a'; zn<='z'; zn++) base.insert(std::make_pair(zn, 0));
    for(char zn : s1) base[zn]++;
    for(char zn : s2) base[zn]--;
    for(auto pos : base) ret += abs(pos.second) ;    
    return ret;
}



/**
 * 
 * Solution for Beautiful Triplets problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
 * 
 * @param  int         d 		Triplet diff
 * @param  vector<int> arr 		Array of sorted numberes
 * @return int		   ret	 	Returned amount of founded triplets in arr
 * 
 * @example d 	:  3
 * 			arr :  1 2 4 5 7 8 10
 * 			ret	-> 3
 * 		explained:
 * 		===  	1(1 4 7)   ===
 * 		===		2(2 5 8)   ===
 * 		===		3(4 7 10)  ===
 * @example a 	:  3
 * 			arr	:  1 6 7 7 8 10 12 13 14 19
 * 			ret -> 2
 * 		explanation:
 * 		===  	1(7 8 13)   ===
 * 		===		2(7 8 13)   ===
 * 
 * @note Algorithm complexity: O(nlogn) + O(n) +  O(n)
 * @note Algorithm complexity: O(nlogn) + O(nlogn) +  O(n)
 */
int beautifulTriplets__PBA_1(int d, std::vector<int> arr) {

    int ret = 0;

    for(int i=1; i<(int)arr.size()-1; i++){
        int Left     = arr[i]-d;
        int LeftCnt  = 0;
        int Right    = arr[i]+d;
        int RightCnt = 0;
        bool Lexists = false;
        bool Rexists = false;
        
        //Check if Left  Exists and how many
        for(int j=i; j>=0; j--){
            if(arr[j] == Left ){
                Lexists = true;
                while(arr[j] == Left ){
                    LeftCnt++;
                    j--;
                }
                break;
            }
        }
        
        //Check if Right Exists and how many
        for(int j=i; j<(int)arr.size(); j++){
            if(arr[j] == Right ){
                Rexists = true;
                while(arr[j] == Right ){
                    RightCnt++;
                    j++;
                }
                break;
            }
        }
        
        if(Lexists && Rexists){
            ret += RightCnt * LeftCnt;
        }
    }
    return ret;
}



/**
 * 
 * Solution for Beautiful Triplets problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
 * 
 * @param  int         d 		Triplet diff
 * @param  vector<int> arr 		Array of sorted numberes
 * @return int		   ret	 	Returned amount of founded triplets in arr
 * 
 * @example d 	:  3
 * 			arr :  1 2 4 5 7 8 10
 * 			ret	-> 3
 * 		explained:
 * 		===  	1(1 4 7)   ===
 * 		===		2(2 5 8)   ===
 * 		===		3(4 7 10)  ===
 * @example a 	:  3
 * 			arr	:  1 6 7 7 8 10 12 13 14 19
 * 			ret -> 2
 * 		explanation:
 * 		===  	1(7 8 13)   ===
 * 		===		2(7 8 13)   ===
 * 
 * @note Algorithm complexity: O(nlogn) + O(n) +  O(n)
 * @note Algorithm complexity: O(nlogn) + O(nlogn) +  O(n)
 */
int beautifulTriplets__GPT_1(int d, std::vector<int> arr) {
    int ret = 0;
    
    // Create a hash map to store the occurrences of elements in the array
    std::unordered_map<int, int> occurrences;
    for (int num : arr) {
        occurrences[num]++;
    }

    // Check for beautiful triplets
    for (int num : arr) {
        int left = num - d;
        int right = num + d;

        // Check if the left and right elements exist in the occurrences map
        if (occurrences.count(left) && occurrences.count(right)) {
            ret += occurrences[left] * occurrences[right];
        }
    }

    return ret;
}


/**
 * 
 * Solution for Beautiful Triplets problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
 * 
 * @param  int         d 		Triplet diff
 * @param  vector<int> arr 		Array of sorted numberes
 * @return int		   ret	 	Returned amount of founded triplets in arr
 * 
 * @example d 	:  3
 * 			arr :  1 2 4 5 7 8 10
 * 			ret	-> 3
 * 		explanation:
 * 		===  	1(1 4 7)   ===
 * 		===		2(2 5 8)   ===
 * 		===		3(4 7 10)  ===
 * @example a 	:  3
 * 			arr	:  1 6 7 7 8 10 12 13 14 19
 * 			ret -> 2
 * 		explained:
 * 		===  	1(7 8 13)   ===
 * 		===		2(7 8 13)   ===
 * 
 * @note Algorithm complexity: O(nlogn) + O(n) +  O(n)
 * @note Algorithm complexity: O(nlogn) + O(nlogn) +  O(n)
 */
int beautifulTriplets__OTH_1(int d, std::vector<int> arr) {
    int ret = 0;
    int n = arr.size();

    // Nested loops for generating all possible triplets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[j] - arr[i] == d && arr[k] - arr[j] == d) {
                    ret++;
                }
            }
        }
    }

    return ret;
}


/**
 * 
 * Solution for circularArrayRotation problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/circular-array-rotation/problem?h_r=profile
 * 
 * @param  vector<int> a 		Orginal data to shift.
 * @param  int         k 		Shift.
 * @param  vector<int> queries 	Vector of queries - each element is index(idx) of shifted vector 
 * @return vector<int> ret	 	Returned vector of values from shifted vector index.
 * 
 * @example a 		: 1 2 3
 * 			k 		: 2
 * 		=== shifteda: 2 3 1 ===
 * 			queries	: 0 1 2
 * 			ret	    ->2 3 1
 * 
 * @example a 		: 8 2 7 3 3 1 9 7
 * 			k 		: 18
 * 		=== shifteda: 9 7 8 2 7 3 3 1 ===
 * 			queries	: 7 2 0
 * 			ret	    ->1 8 9
 * 		
 */
int beautifulTriplets__GPT_2(int d, std::vector<int> arr) {
    int ret = 0;
    int n = arr.size();

    // Check for beautiful triplets
    for (int i = 0; i < n - 2; i++) {
        int left = arr[i] + d;
        int right = arr[i] + 2 * d;

        // Use two pointers to find the left and right elements
        int leftIndex = i + 1;
        int rightIndex = i + 2;

        while (rightIndex < n) {
            if (arr[leftIndex] == left && arr[rightIndex] == right) {
                ret++;
                leftIndex++;
                rightIndex++;
            } else if (arr[leftIndex] < left) {
                leftIndex++;
            } else {
                rightIndex++;
            }
        }
    }

    return ret;
}



/**
 * 
 * Solution for circularArrayRotation problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/circular-array-rotation/problem?h_r=profile
 * 
 * @param  vector<int> a 		Orginal data to shift.
 * @param  int         k 		Shift.
 * @param  vector<int> queries 	Vector of queries - each element is index(idx) of shifted vector 
 * @return vector<int> ret	 	Returned vector of values from shifted vector index.
 * 
 * @example a 		: 1 2 3
 * 			k 		: 2
 * 		=== shifteda: 2 3 1 ===
 * 			queries	: 0 1 2
 * 			ret	    ->2 3 1
 * 
 * @example a 		: 8 2 7 3 3 1 9 7
 * 			k 		: 18
 * 		=== shifteda: 9 7 8 2 7 3 3 1 ===
 * 			queries	: 7 2 0
 * 			ret	    ->1 8 9
 * 		
 */
std::vector<int> circularArrayRotation(std::vector<int> a, int k, std::vector<int> queries) {

    std::vector<int> ret;
    int size = a.size();

    // Reducting amount of full shifts
    int reducedShift = k%a.size();
    
    // Determine new idx=0 position
    int idx0 = size - reducedShift;
    if(idx0==size) idx0 = 0;
    
	// Determine new idx based on idx transformation
    for(int idx : queries)
    {
        idx += idx0;  
        
        if(idx < size ) ret.push_back(a[idx]);    
        else            ret.push_back(a[idx - size]);
        
    }
    return ret;
}



/**
 * 
 * Solution for Save The Prinsoner mentioned problem.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true
 * 
 * 
 * @param  int         n amount of positions.
 * @param  int         m amount of candy to distribute.
 * @param  int         s The first candy shift.
 * @return int   	   r The last candy position.
 * 
 *          [n][m][s]     [r]
 * 			------------------
 * @example  5  2  1  ->   2
 * @example	 5  2  2  ->   3
 * @example	 3  7  3  ->   3
 * @example	 7  19 2  ->   6
 *			------------------
 * 
 */
int saveThePrisoner(int n, int m, int s) {

    int ret = m%n;
    if(!ret) ret = n;
    
    ret+=s-1;
    
    return ret>n ?  ret%n : ret ;
    
}


/**
 * 
 * Converts an integer into a vector of its individual digits.
 *
 * 1 Use: (Source)
 * https://www.hackerrank.com/challenges/find-digits/problem
 * 2 Use:
 * https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
 * 
 * 
 * @param  int           The integer to be converted.
 * @return vector<int>   vector containing the individual digits of the input number.
 * 
 * @example 12345 -> 5 4 3 2 1
 * 			54445 -> 5 4 4 4 5
 * 			1     -> 1
 * 
 */
std::vector<int> intigerToDigitsVector(int n) {
	
	std::vector<int> ret;
    int tmp = n;
    
    for(int i=10; i<=n*10; i*=10){
        ret.push_back((tmp%i)/(i/10));
        tmp -= tmp%i;
    }
    
    return ret;
}



/**
 * 
 * Converts an integer into a intiger with reversed digits.
 *
 * 1 Use: (Source) 
 * https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
 * 
 * 
 * @param  int   The integer to be reversed.
 * @return int   The intiger with reversed digits.
 * 
 * @example 12345  -> 54321
 * 			987654 -> 456789
 * 			1219   -> 9121
 * 			1      -> 1
 *          0      -> 0
 * 			10000  -> 1
 * 			-479   -> -974
 * 
 */
int intigerToIntigerReversed(int n) {

    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

/**
 *
 * Complete the 'missingNumbers' function below.
 *
 * Source:
 * https://www.hackerrank.com/challenges/missing-numbers/problem
 * 
 * The function is expected to return an INTEGER_ARRAY.
 * @param arr tailored vector
 * @param brr orginal vector
 * @return A vector of missing elements.
 * @example arr  1 2 3 4 5
 *          brr  1 1 2 2 3 3 3 3 4 5
 * 			->   1 2 3
 * 
 *  		arr  203 204 205 206 207 208 203 204 205 206
 * 			brr  203 204 204 205 206 207 205 208 203 206 205 206 204*        
 * 			->   204 205 206
 */
std::vector<int> missingNumbers(std::vector<int> arr, std::vector<int> brr) {

    //
    // Prepare vector elements
    //
    std::sort(arr.begin(),arr.end());
    std::sort(brr.begin(),brr.end());
    int size_b = brr.size();
    std::vector<int> ret;
    
    //
    // Localize missing elements
    //
    for(int b=0,a=0; b<size_b; b++,a++){
        if(brr[b] != arr[a]){
            ret.push_back(brr[b]);
            a--;
        }
    }
    
    //
    // Eliminate duplicate elements
    //
    ret.erase(std::unique(ret.begin(), ret.end()), ret.end());

    return ret;
}


/**
 *
 * Complete the 'minimumDistances' function below.
 *
 * Source:
 * https://www.hackerrank.com/challenges/minimum-distances/problem
 * 
 * The distance between two array values is the number of indices between them. 
 * Given array a, find the minimum distance between any pair of equal elements in the array. 
 * If no such value exists, return -1.
 * @param a vector
 * @return Minimum distance.
 * @example a   7 1 3 4 1 7 
 * 		    ->  3
 * 
 */
int minimumDistances__PBA_1(std::vector<int> a) {

    int distance;
    int min_distance=10000;

    for(size_t i=0; i<a.size(); i++)
    {
        int current = a[i];
        int last_it = i;
        
        for(size_t j=i+1; j<a.size(); j++)
        {
            if(current == a[j]) 
            {
                distance = j-last_it;
                if(distance<min_distance) min_distance = distance;
                last_it = j;
            }
        }
    }return min_distance == 10000 ? -1 : min_distance ;
}

//
// ChatGPT version
//
int minimumDistances__GPT_1(std::vector<int> a) {

    std::unordered_map<int, int> indexMap;
    int minDistance = std::numeric_limits<int>::max();

    for (size_t i = 0; i < a.size(); ++i) {
        if (indexMap.count(a[i]) > 0) {
            int distance = i - indexMap[a[i]];
            minDistance = std::min(minDistance, distance);
        }
        indexMap[a[i]] = i;
    }

    return (minDistance == std::numeric_limits<int>::max()) ? -1 : minDistance;
}



/**
 * Decodes the Vigenere cipher for the given ciphertext and key.
 * 
 * @param cipher The ciphertext to be decoded.
 * @param key The key used for decoding.
 * @return The decoded plaintext.
 * 
 * @note
 * 
 * 
 */
std::string decode_cipherVigenere
(
    std::string cipher, 
    std::string key
)
{
    std::stringstream ss;
	char vinTableBig[26][26];
	char vinTableSmall[26][26];
	
	for(int i=0; i<26; i++)
	{
		static char litera = 'A';
		for(int j=0; j<26; j++){
			if(litera == 'Z') litera = 'A';
			vinTableBig[i][j] = litera;
			litera++;
		}
	}
	
	for(int i=0; i<26; i++)
	{
		char litera = 'a' + i;
		for(int j=0; j<26; j++){
			if(litera > 'z') litera = 'a';
			vinTableSmall[i][j] = litera;
			litera++;
		}
	}
	
	
	// std::cout << "Tablica: " << std::endl;
	// for(int i=0; i<26; i++)
	// {
	// 	for(int j=0; j<26; j++)
	// 	{
	// 		std::cout << vinTableSmall[i][j];
	// 	}std::cout << std::endl;
	// } std::cout << std::endl;
	
	size_t size = cipher.size();
	size_t size_k = key.size();

	while(size>size_k){
		key+=key;
		size_k = key.size();
	}
	
	
	for(size_t i=0; i<size; i++)
	{
		char klucz = key[i];
		char kod   = cipher[i];

		//-----------------------------------------------
		// Small letter
		//-----------------------------------------------
		if(cipher[i] >= 'a' && cipher[i] <= 'z' )
		{
			for(int j=0; j<26; j++){
				if(vinTableSmall[klucz-'a'][j] == kod){
					ss << (char)(j+'a');
					break;
				}
			}
		}
		//-----------------------------------------------
		// Big letter
		//-----------------------------------------------
		else if(cipher[i] >= 'A' && cipher[i] <= 'Z' )
		{
			for(int j=0; j<26; j++){
				if(vinTableBig[klucz-'a'][j] == kod){
					ss << (char)(j+'A');
					break;
				}
			}
		}
		//-----------------------------------------------
		// Non latin letter
		//-----------------------------------------------
		else
        {
		    ss << cipher[i];
            cipher.erase(i, 1); 
            size--; 
            i--;
        }
	}
    return ss.str();
}

std::string decode_cipherBacon
(
	std::string cipher, 
	char A, 
	char B
)
{
	int 	    size   = cipher.length();
	int 		cnt	   = size/5;
	std::stringstream ss;

	for(int i = 0; i<size; i++)
		cipher[i]==A ? ss<<"0" : ss<<"1";

	//std::cout << ss.str() << std::endl;

	std::string binary = ss.str();
	int decoded[100];


	std::stringstream tmp;
	for(int i=0; i<cnt*5; i+=5){
		for(int j=0; j<5; j++){
			tmp << binary[i+j];
		}
		decoded[i/5] = std::stoi(tmp.str(),nullptr,2);
		tmp.str(std::string());
	}

	for(int i=0; i<cnt; i++){
		if(decoded[i] <=  8 )
			tmp << char(decoded[i] + 'a');
		else if((decoded[i] <=  19 ))
			tmp << char(decoded[i] + 'a' + 1);
		else
			tmp << char(decoded[i] + 'a' + 2);
	}

	return tmp.str();
}

std::string decode_cipherBacon
(
	std::string cipher
)
{
	if(cipher.empty())
	{
		std::cout << "Error: cipher empty" << std::endl;
		return 0;
	}

	char firstCharacter = cipher[0];

	char secondCharacter;
	int size = cipher.length();
	for(int i=0; i<size; i++){
		if(firstCharacter != cipher[i]){
			secondCharacter = cipher[i];
			break;
		} 
	}

	return decode_cipherBacon(cipher, firstCharacter, secondCharacter);

}

std::string decode_cipherCezar
(	
	std::string cipher,
	int			shift
)
{
	std::stringstream  ss;
	size_t cip_size = cipher.size();

	for(size_t i=0; i<cip_size; i++)
	{
		char znak = cipher[i];

		if(znak >= 'a' && znak <= 'z' )
		{
			if(  znak + shift > 'z' ) 	ss << (char)('a'-1 +( znak + shift - 'z'));
			else  				 		ss << (char)(znak + shift);
		}
		else if(znak >= 'A' && znak <= 'Z' )
		{
			if(  znak + shift > 'Z' ) ss << (char)('A'-1 +( znak + shift - 'Z'));
			else 				  ss << (char)(znak + shift);
		}
		else{
			ss << znak;
		}
	}
	return ss.str();
}




std::string decode_cipherCezar
(	
	std::string cipher
)
{
	std::string tmp;

	for(int shift=0; shift<26; shift++)
	{
		tmp = decode_cipherCezar(cipher,shift);
		std::cout << shift << " : " << tmp << std::endl;
		if (tmp.find("flag") != std::string::npos) 
		{
			std::cout << "flag has been find" << std::endl;
			break;
		}
		else
		{
			std::cout << shift << " : " << tmp << std::endl;
		}	
	}
	return tmp;
}


std::string decode_cipherXOR
(
	std::string cipher
)
{
	std::string tmp;
	int max = 8;
	int max_bit = pow(2,max);

	for(int i=0; i<=max_bit; i++)
	{
		tmp = decode_cipherXOR(cipher,i);
		std::cout << i << " : " << tmp << std::endl;

		if (tmp.find("flag") != std::string::npos)
		{
			return tmp;
		}

	}
	return ":(";
}


std::string decode_cipherXOR
(	
	std::string cipher,
	uint8_t	 	key
)
{
	std::stringstream ss;
	//size_t size = cipher.size();
	// for(size_t i=0; i<255; i++)
	// {
	// 	char k = cipher[i];
	// 	k ^= key;
	// 	ss << k;
	// }

	std::string m1 ="aaa";
	std::string m2 ="bbb";

	std::string out;

	uint8_t a = 10 ; //1010
	uint8_t b = 12 ; //1100
	uint8_t c = a^b;
	std::cout << "a^b: " << c << std::endl;




	return ss.str();
}

void brute(void)
{
	std::string cipher = "q{vpln'bH_varHuebcrqxetrHOXEj";
	std::cout << decode_cipherCezar(cipher) << std::endl;
	std::cout << decode_cipherXOR(cipher);
}