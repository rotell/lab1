#ifndef LAB1_MENU_H
#define LAB1_MENU_H

#include "url_func.h"

void Exit(Subscriber&, const string&);
void Input_subscriber(Subscriber& subscriber, const string&);
void menu_toUrlEncoded(Subscriber& subscriber, const string& recordName);
void menu_fromUrlEncoded(Subscriber& subscriber, const string& recordName);

void menu(Subscriber& subscriber, const string& recordName);

#endif
