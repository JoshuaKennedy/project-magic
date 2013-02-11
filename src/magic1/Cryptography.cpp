#include "stdafx.h"

extern "C" __declspec (dllexport) const char* GetMD5Hash(char* input)
{
        HCRYPTPROV CryptProv; 
        HCRYPTHASH CryptHash; 
        BYTE BytesHash[33];//!
        DWORD dwHashLen;
        string final;

        if(CryptAcquireContext(&CryptProv, 
                NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_MACHINE_KEYSET)) 
        {
                if(CryptCreateHash(CryptProv, CALG_MD5, 0, 0, &CryptHash)) 
                {
                        if(CryptHashData(CryptHash, (BYTE*)input, strlen(input), 0))
                        {
                                if(CryptGetHashParam(CryptHash, HP_HASHVAL, BytesHash, &dwHashLen, 0)) 
                                {
										final.clear();
                                        string hexcharset = "0123456789ABCDEF";
                                        for(int j = 0; j < 16; j++)
                                        {
                                                final += hexcharset.substr(((BytesHash[j] >> 4) & 0xF),1);
                                                final += hexcharset.substr(((BytesHash[j]) & 0x0F),1);
                                        }
                                }
                        }
                }
        }

        CryptDestroyHash(CryptHash); 
        CryptReleaseContext(CryptProv, 0); 
		return final.c_str(); 
}
