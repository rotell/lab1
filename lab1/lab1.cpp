#include "menu.h"

int main() {
    string recordName;
    cout << "Input record name:" << endl;
    recordName = getVal<string>();
    Subscriber subscriber{};
    menu(subscriber, recordName);
    return 0;
}
