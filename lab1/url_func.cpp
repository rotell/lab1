#include "url_func.h"

bool checkNumber(const string& number) {
    if (number.empty() || !(number[0] == '+' || isdigit(number[0]) || number.length() > 16)) {
        return false;
    }
    return all_of(number.begin() + 1, number.end(), ::isdigit);
}

string inputNumber(){
    string number;
    bool flag;
    do {
        cout << "Input number:" << endl;
        number = getVal<string>();
        flag = checkNumber(number);
        if (!flag) {
            cout << "Invalid number. Try again." << endl;
        }
    }while(!flag);

    return number;
}
string toUrlEncoded(const Subscriber& subscriber, const string& recordName) {
    string res;
    res += recordName + "[name]=" + subscriber.name;
    res += "&" + recordName + "[number]=" + subscriber.number;
    res += "&" + recordName + "[lastcall]=" + std::to_string(subscriber.lastcall);
    return res;
}

string getValueByKey(const string& s, const string& key) {
    size_t start = s.find(key);
    if (start == string::npos) {
        throw std::invalid_argument("wrong string");
    }
    start += key.length();

    size_t end = s.find('&', start);
    if (end == string::npos) {
        end = s.length();
    }

    return s.substr(start, end - start);
}
Subscriber fromUrlEncoded(const string& s, const string& recordName){
    Subscriber subscriber;

    subscriber.name = getValueByKey(s,  recordName + "[name]=");
    subscriber.number = getValueByKey(s, recordName + "[number]=");
    string lastCallStr = getValueByKey(s, recordName + "[lastcall]=");
    if (!lastCallStr.empty()) {
        subscriber.lastcall = stol(lastCallStr);
    }
    else{
        subscriber.lastcall = 0;
    }

    return subscriber;
}
Subscriber fromUrlEncoded(const char* s, const string& recordName) {
    return fromUrlEncoded(string(s), recordName);
}

string getValueByKey(const char* s, size_t size, const string& key) {
    const char* start = std::search(s, s+size, key.begin(), key.end());
    if (start == s+size) {
        throw std::invalid_argument("wrong string");
    }
    start += key.size();
    const char* end = std::find(start, s+size, '&');

    return string(start, end);
}
Subscriber fromUrlEncoded(const char* s, size_t size, const string& recordName) {
    Subscriber subscriber;

    subscriber.name = getValueByKey(s, size,  recordName + "[name]=");
    subscriber.number = getValueByKey(s, size, recordName + "[number]=");
    string lastCallStr = getValueByKey(s, size, recordName + "[lastcall]=");
    if (!lastCallStr.empty()) {
        subscriber.lastcall = stol(lastCallStr);
    }
    else{
        subscriber.lastcall = 0;
    }

    return subscriber;

}
