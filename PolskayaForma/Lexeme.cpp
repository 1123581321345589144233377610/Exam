#include "Lexeme.hpp"

Lexeme::Lexeme(const char* name = "") {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}