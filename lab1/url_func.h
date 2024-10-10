#ifndef LAB1_URL_FUNC_H
#define LAB1_URL_FUNC_H

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <chrono>

using std::string;
using std::cin;
using std::cout;
using std::endl;

typedef struct Subscriber{
    string name;
    string number;
    time_t lastcall;
} Subscriber;

template<class T>
T getVal() {
    T a;
    while(true) {
        std::cin >> a;
        if(std::cin.eof())
            throw std::runtime_error("Failed to read number: EOF");
        else if(std::cin.bad())
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        else if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "You are wrong; repeat please!" << std::endl;
        }
        else
            return a;
    }
}

bool checkNumber(const string& number);
string inputNumber();
string toUrlEncoded(const Subscriber& subscriber, const string& recordName);

string getValueByKey(const string& s, const string& key);
Subscriber fromUrlEncoded(const string& s, const string& recordName);
Subscriber fromUrlEncoded(const char* s, const string& recordName);

string getValueByKey(const char* s, size_t size, const string& key);
Subscriber fromUrlEncoded(const char* s, size_t size, const string& recordName);


#endif
