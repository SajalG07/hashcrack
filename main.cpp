#include <iostream>
#include "md5.h"
#include "cracker.h"
#include "bruteforce.h"

void usage() {
     std::cout << "Usage:" << std::endl;
     std::cout << " Dictionary : ./hashcrack -d <hash> <wordlist>" << std::endl;
     std::cout << " Brute force: ./hashcrack -b <hash> <max_length>" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
         usage();
         return 1;
    }
    std::string mode = argv[1];
    std::string hash = argv[2];

    if (mode == "-d") {
       std::string wordlist = argv[3];
       std::cout << "[*] Dictionary attack on: " << hash << std::endl;
       dictionary_crack(hash, wordlist);
    }else if (mode == "-b"){
       int max_len = std::stoi(argv[3]);
       std::cout << "[*] Brute force attack on: " << hash << std::endl;
       brute_force_crack(hash, max_len);

    }else{
       usage();
    }

    return 0;

}



