#include "pbaProSo.hpp"

void test(void)
{
    std::cout << "Library compilation - PASS" << std::endl;
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
 * 
 */
std::vector<int> intigerToDigitsVector(int n) {
	
	std::vector<int> ret;
    int tmp = n;
    
    for(int i=10; i<n*10; i*=10){
        ret.push_back((tmp%i)/(i/10));
        tmp -= tmp%i;
    }
    
    return ret;
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

    for(int i=0; i<a.size(); i++)
    {
        int current = a[i];
        int last_it = i;
        
        for(int j=i+1; j<a.size(); j++)
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

    for (int i = 0; i < a.size(); ++i) {
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