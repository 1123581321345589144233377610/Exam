#pragma once
#include "Lexeme.hpp"
#include "Value.hpp"
#include "Operator.hpp"
#include "Add.hpp"
#include "Subtract.hpp"
#include "Multiply.hpp"
#include "Divide.hpp"
#include "Sin.hpp"
#include "Cos.hpp"
#include <unordered_map>
#include <functional>

void Parse(FILE* fin, Lexeme** lexemes, int& lexemesCount);