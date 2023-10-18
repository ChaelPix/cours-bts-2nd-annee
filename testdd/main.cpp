#include <iostream>
#include <string>
#include <vector>
#include <cctype>

struct Term {
    char variable;        // 'y' or 'x'
    int index;            // The index of y or x (n, n-1, n-2, ...)
    int coefficient;      // The coefficient of the term (a, b, c, ...)
    char sign;            // '+', '-' or initial sign
};

std::vector<Term> decomposeEquation(const std::string& equation) {
    std::vector<Term> terms;

    char sign = '+'; // Default sign
    for (size_t i = 0; i < equation.size(); ++i) {
        if (equation[i] == '+' || equation[i] == '-') {
            sign = equation[i];
            continue;
        }

        Term term;
        term.sign = sign;

        // Extract coefficient if exists
        if (std::isdigit(equation[i])) {
            term.coefficient = equation[i] - '0';
            while (i + 1 < equation.size() && std::isdigit(equation[i + 1])) {
                term.coefficient = term.coefficient * 10 + (equation[++i] - '0');
            }
        }
        else {
            term.coefficient = 1; // Default coefficient
        }

        // Extract variable and index
        if (i + 1 < equation.size() && (equation[i + 1] == 'x' || equation[i + 1] == 'y')) {
            term.variable = equation[++i];
            if (i + 2 < equation.size() && equation[i + 2] == 'n') {
                i += 2; // Skip 'n'
                term.index = 0; // Default index
                if (i + 1 < equation.size() && (equation[i + 1] == '-' || equation[i + 1] == '+')) {
                    term.index = equation[++i] == '-' ? -(equation[++i] - '0') : equation[++i] - '0';
                }
            }
        }

        terms.push_back(term);
    }

    return terms;
}

int main() {
    std::string equation;
    std::cout << "Entrez votre équation de récurrence : ";
    std::getline(std::cin, equation);

    std::vector<Term> terms = decomposeEquation(equation);
    for (const Term& term : terms) {
        std::cout << term.sign << " " << term.coefficient << term.variable << term.index << std::endl;
    }

    return 0;
}
