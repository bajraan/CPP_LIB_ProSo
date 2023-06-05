#include "pbaProSo.hpp"

void test(void)
{
    std::cout << "Library compilation - PASS" << std::endl;
}

/**
 * Decodes the Vigenere cipher for the given ciphertext and key.
 * 
 * @param cipher The ciphertext to be decoded.
 * @param key The key used for decoding.
 * @return The decoded plaintext.
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
		for(int j=0; j<26; j++)
		{
			if(litera == 'Z') litera = 'A';
			vinTableBig[i][j] = litera;
			litera++;
		}
	}
	
	for(int i=0; i<26; i++)
	{
		char litera = 'a' + i;
		for(int j=0; j<26; j++)
		{
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
	
	for(size_t i=0; i<size; i++)
	{
		char klucz = key[i];
		char kod   = cipher[i];
		
		if(cipher[i] >= 'a' && cipher[i] <= 'z' )
		{
			for(int j=0; j<26; j++)
			{
				//cout << vinTableSmall[klucz-'a'][j] << "==" << kod <<
				//" ret: "<< (char)(j+'a') << endl;
				if(vinTableSmall[klucz-'a'][j] == kod)
				{
					ss << (char)(j+'a');
					break;
				}
			}
		}
		else if(cipher[i] >= 'A' && cipher[i] <= 'Z' )
		{
			for(int j=0; j<26; j++)
			{
				//cout << vinTableBig[klucz-'a'][j] << "==" << kod << endl;
				if(vinTableBig[klucz-'a'][j] == kod)
				{
					ss << (char)(j+'A');
					break;
				}
			}
		}
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