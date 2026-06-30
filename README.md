# hashcrack

A command-line MD5 hash cracker written in C++.
Built as part of my red team security learning journey.

## Features
- Dictionary attack using a wordlist
- Brute force attack with configurable max length

## Usage

### Dictionary Attack
./hashcrack -d <hash> <wordlist>

### Brute Force Attack
./hashcrack -b <hash> <max_length>

## Example
./hashcrack -d 5f4dcc3b5aa765d61d8327deb882cf99 wordlist.txt
Output: [+] CRACKED after 5 attempts! Password: password

## Build
g++ main.cpp md5.cpp cracker.cpp bruteforce.cpp -o hashcrack -lssl -lcrypto

## Disclaimer
This tool is for educational purposes only.
Only use on systems you own or have permission to test.

## Author
SajalG07

