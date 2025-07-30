#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <cctype>

using namespace std;

struct ExamplePassword {
    string password;
};

bool checkPasswordStrength(const string& password) {
    bool hasDigit = false;
    bool hasSymbol = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool isStrong = true;

    if (password.length() < 8) {
        cout << "Password too short!" << endl;
        isStrong = false;
    }

    for (char c : password) {
        if (isdigit(static_cast<unsigned char>(c))) hasDigit = true;
        else if (ispunct(static_cast<unsigned char>(c))) hasSymbol = true;
        else if (isupper(static_cast<unsigned char>(c))) hasUpper = true;
        else if (islower(static_cast<unsigned char>(c))) hasLower = true;
    }

    if (!hasDigit) {
        cout << "Add at least one digit." << endl;
        isStrong = false;
    }
    if (!hasSymbol) {
        cout << "Add at least one symbol." << endl;
        isStrong = false;
    }
    if (!hasUpper) {
        cout << "Add at least one uppercase letter." << endl;
        isStrong = false;
    }
    if (!hasLower) {
        cout << "Add at least one lowercase letter." << endl;
        isStrong = false;
    }

    if (isStrong) {
        cout << "Your password is strong enough!" << endl;
    }
    else {
        cout << "Your password is not strong enough." << endl;
    }

    return isStrong;
}

int main() {
    vector<ExamplePassword> examples = {
        {"Abc123!@"},
        {"password123"},
        {"Qwerty!23"},
        {"HelloWorld1#"},
        {"12345678"},
        {"StrongPass!9"}
    };

    default_random_engine engine(static_cast<unsigned int>(time(nullptr)));
    shuffle(examples.begin(), examples.end(), engine);

    string randomExample = examples[0].password;

    cout << "Random example password: " << randomExample << endl;

    checkPasswordStrength(randomExample);

    string userPassword;
    while (true) {
        cout << "Enter your password: ";
        getline(cin, userPassword);

        if (checkPasswordStrength(userPassword)) {
            cout << "Password accepted." << endl;
            break;
        }
        else {
            cout << "Try again." << endl;
        }
    }

    return 0;
}
