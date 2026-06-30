#include "bruteforce.h"
#include "md5.h"
#include <iostream>
#include <string>

bool brute_force_crack(const std::string& target_hash, int max_length){
     std::string charset = "abcdefghijklmnopqrstuvwxyz0123456789@#$%^";
     long long attempts = 0;
     for(int length = 1; length <= max_length ; length++){
        std::string guess(length,charset[0]);

        while(true){
             attempts++;
             if(md5(guess) == target_hash){
                std::cout << "[+] CRACKED after " << attempts << " attempts!" << std::endl;
                std::cout << "[+] Password: " << guess << std::endl;
                return true;
             }

             int pos = length - 1;
             while (pos >= 0){
                int idx = charset.find(guess[pos]);
                if(idx + 1 < (int)charset.size()) {
                   guess[pos] = charset[idx + 1];
                   break; 
                }else{
                   guess[pos] = charset[0];
                   pos--;
                 }

             }
             if (pos < 0) break;

        }
     }
     std::cout << "[-]Not found within length " << max_length << std::endl;
     return false;
}

