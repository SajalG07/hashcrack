#include "md5.h"
#include <openssl/evp.h>
#include<sstream>
#include<iomanip>

std::string md5(const std::string& input) {
     unsigned char digest[16];
     unsigned int digest_len = 0;

     EVP_MD_CTX* ctx = EVP_MD_CTX_new();
     EVP_DigestInit_ex(ctx, EVP_md5(), nullptr);
     EVP_DigestUpdate(ctx, input.c_str(), input.size());
     EVP_DigestFinal_ex(ctx, digest, &digest_len);
     EVP_MD_CTX_free(ctx);

     std::ostringstream oss;
     for(unsigned int i = 0; i < digest_len; i++){
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)digest[i];

}
     return oss.str();
}
