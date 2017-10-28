#ifndef CALLBACKFUNCTION_H
#define CALLBACKFUNCTION_H

#include <Arduino.h>

typedef std::function<void(uint8_t pin, uint8_t state)> CallbackFunction;

#endif
