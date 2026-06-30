#include "md5.h"
#include <iostream>
#include <fstream>
#include <string>

bool dictionary_crack(const std::string& target_hash, const std::string& wordlist_path){
    std::ifstream file(wordlist_path);

    if (!file.is_open()) {
         std::cerr << "Could not open wordlist: " << wordlist_path << std::endl;
         return false;
    }

    std::string word;
    long long attempts = 0;

    while (std::getline(file, word)){
          attempts++;
          std::string hashed = md5(word);

          if (hashed == target_hash){
               std::cout << "[+] CRACKED after " << attempts << std::endl;
               std::cout << "[+] Password: " << word << std::endl;
               return true;
            }
    }

    std::cout << "[-] Not found in wordlist after " << attempts << " attempts." << std::endl;
    return false;
}
