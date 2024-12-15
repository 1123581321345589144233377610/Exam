#pragma once
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#pragma warning (disable : 4996)

#define MAX_STACK_SIZE 1024
#define MAX_LEXEMES_NUM 1024

class Lexeme {
protected:
    char* name;

public:
    Lexeme(const char* name);

    virtual ~Lexeme() {
        delete[] name;
    }

    virtual const class Value* AsValue() const {
        return nullptr;
    }

    virtual class Value* AsValue() {
        return nullptr;
    }

    virtual const class Operator* AsOperator() const {
        return nullptr;
    }

    virtual class Operator* AsOperator() {
        return nullptr;
    }

    const char* GetName() const{
        return name;
    }
};