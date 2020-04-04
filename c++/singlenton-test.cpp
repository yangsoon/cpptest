#include <iostream>
#include "Singleton.h"

int main() {
    Singlenton::getInstance().setup();
    Singlenton::getInstance().setup();
}