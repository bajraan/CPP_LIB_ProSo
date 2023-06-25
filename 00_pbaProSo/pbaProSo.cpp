#include <vector>
#include "pbaProSo.hpp"

void test(void)
{
    std::cout << "Library compilation - PASS" << std::endl;
}

/**
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
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