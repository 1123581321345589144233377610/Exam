#include "Value.hpp"

Value::Value(double value = 0, const char* name = "") : Lexeme(name), value(value) {}

Value::operator double() const {
    return value;
}

const Value* Value::AsValue() const {
    return this;
}

Value* Value::AsValue() {
    return this;
}