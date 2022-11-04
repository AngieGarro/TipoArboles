#include "Validar.h"
#include <string>

int Validar::ingresarInt(string pValor) {
    try {
        return stoi(pValor);
    }
    catch (exception e) {
        return -1;
    }
}