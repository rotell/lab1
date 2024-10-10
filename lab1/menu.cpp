#include "menu.h"
#define PROMPT_STR "Input string:\n"

void Exit(Subscriber&, const string&){
    cout << "Exiting..." << endl;
}

void Input_subscriber(Subscriber& subscriber, const string&){
    cout << "Input subscriber name:" << endl;
    subscriber.name = getVal<string>();
    subscriber.number = inputNumber();

    cout << "Input subscriber last call:" << endl;
    try{
        subscriber.lastcall = getVal<int>();
    }catch(std::runtime_error &e){
        cout << e.what();
        return;
    }
    cout << subscriber.name << ", " << subscriber.number << ", " << subscriber.lastcall << endl;
}

void menu_toUrlEncoded(Subscriber& subscriber, const string& recordName){
    cout << "Encoded: " << toUrlEncoded(subscriber, recordName) << endl;
}

void menu_fromUrlEncoded(Subscriber& subscriber, const string& recordName){
    int flag3;
    cout << "What type of data u want to use?" << endl << "1. String\n2. Const char\n3. Const char and size (massive)" << endl;
    flag3 = getVal<int>();
    switch (flag3) {
        case 1: {
            string url;
            cout << PROMPT_STR;
            url = getVal<string>();
            try {
                subscriber = fromUrlEncoded(url, recordName);
            }catch(std::invalid_argument const& e) {
                cout << e.what();
                break;
            }
            cout << "Decoded: " << subscriber.name << ", " << subscriber.number << ", " << subscriber.lastcall << endl;
            break;
        }
        case 2: {
            string url;
            cout << PROMPT_STR;
            url = getVal<string>();
            char* const_char = new char[url.size() + 1];
            strcpy(const_char, url.c_str());
            try {
                subscriber = fromUrlEncoded(const_char, recordName);
            }catch(std::invalid_argument const& e) {
                cout << e.what();
                delete[] const_char;
                break;
            }
            cout << "Decoded: " << subscriber.name << ", " << subscriber.number << ", " << subscriber.lastcall << endl;
            delete[] const_char;
            break;
        }
        case 3: {
            string url;
            cout << PROMPT_STR;
            url = getVal<string>();
            char* const_char = new char[url.size() + 1];
            strcpy(const_char, url.c_str());
            try {
                subscriber = fromUrlEncoded(const_char, url.size(), recordName);
            }catch(std::invalid_argument const& e) {
                cout << e.what();
                delete[] const_char;
                break;
            }
            cout << "Decoded: " << subscriber.name << ", " << subscriber.number << ", " << subscriber.lastcall << endl;
            delete[] const_char;
            break;
        }
        default:
            cout << "Wrong number, try again" << endl;
            break;
    }
}

void (*menuOptions[])(Subscriber&, const string&) = {
        Exit,
        Input_subscriber,
        menu_toUrlEncoded,
        menu_fromUrlEncoded
};

void menu(Subscriber& subscriber, const string& recordName) {
    int flag = 0;
    do {
        cout << endl << " 0. Exit\n 1. Input subscriber\n 2. toUrlEncoded\n 3. fromUrlEncoded\n";
        flag = getVal<int>();
        if (flag >= 0 && flag <= 3) {
            menuOptions[flag](subscriber, recordName);
        } else {
            cout << "Wrong number, try again" << endl;
        }
    } while (flag != 0);
}