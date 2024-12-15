#include "Lexeme.hpp"
#include "Value.hpp"
#include "Operator.hpp"
#include "Evaluate.hpp"
#include "Add.hpp"
#include "Subtract.hpp"
#include "Multiply.hpp"
#include "Divide.hpp"
#include "Sin.hpp"
#include "Cos.hpp"
#include "Parse.hpp"


int main(int argc, char* argv[]) {
    try {
        FILE* fin = fopen("input.txt", "r");
        if (!fin) throw std::runtime_error("Unable to open file");

        Lexeme* lexemes[MAX_LEXEMES_NUM];
        int lexemesCount;
        Parse(fin, lexemes, lexemesCount);
        fclose(fin);

        double result = Evaluate(lexemes, lexemesCount);
        std::cout << "Result: " << result << std::endl;
    }catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }catch (...) {
        std::cerr << "Unknown Error!" << std::endl;
    }
    return EXIT_SUCCESS;
}
