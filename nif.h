#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cctype>

class nif {
private:
    long value_;   // los 8 dígitos
    char letter_;  // letra calculada automáticamente

    // Tabla de letras según el resto del módulo 23
    static constexpr char letters_[23] = {
        'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D',
        'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L',
        'C', 'K', 'E'
    };

    // Calcula la letra según la parte numérica
    char calculateLetter(long number) const {
        return letters_[number % 23];
    }

    // Extrae solo los dígitos de un string
    long extractDigits(const std::string& dni) {
        long num = 0;
        int count = 0;
        for (char letter : dni) {
            if (std::isdigit(letter)) {
                num = num * 10 + (letter - '0');
                ++count;
                if (count == 8) break; // solo 8 dígitos
            }
        }
        return num;
    }

public:
    // Constructor por defecto: valor aleatorio de 8 dígitos
    nif() {
        std::srand(std::time(nullptr));
        value_ = 10000000 + std::rand() % 90000000;
        letter_ = calculateLetter(value_);
    }

    // Constructor desde long
    nif(long val) : value_(val) {
        letter_ = calculateLetter(value_);
    }

    // Constructor desde string (ej: "12345678Z" o "12345678")
    nif(const std::string& s) {
        value_ = extractDigits(s);
        letter_ = calculateLetter(value_);
    }

    // Conversión a long
    operator long() const { return value_ ; }

    // Operadores de comparación
    bool operator==(const nif& other) const { return value_ == other.value_; }
    bool operator!=(const nif& other) const { return value_ != other.value_; }
    bool operator<(const nif& other) const { return value_ < other.value_; }
    bool operator>(const nif& other) const { return value_ > other.value_; }
    bool operator<=(const nif& other) const { return value_ <= other.value_; }
    bool operator>=(const nif& other) const { return value_ >= other.value_; }

    // Imprimir NIF completo
    friend std::ostream& operator<<(std::ostream& os, const nif& n) {
        os << n.value_ << n.calculateLetter(n.value_);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, nif& n) {
        std::string input;
        is >> input;
        // Solo tomamos los primeros 8 dígitos
        n.value_ = std::stol(input.substr(0,8));
        n.letter_ = n.calculateLetter(n.value_);
        return is;
    }
};