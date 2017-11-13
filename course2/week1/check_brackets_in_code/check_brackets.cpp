#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.emplace(next, position);
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                std::cout << position + 1 << std::endl;
                return 0;
            }
            auto bracket = opening_brackets_stack.top();
            opening_brackets_stack.pop();

            if(!bracket.Matchc(next)) {
                std::cout << position + 1 << std::endl;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if (!opening_brackets_stack.empty()) {
        //int pos = opening_brackets_stack.top().position;
        int pos = 0;
        while(!opening_brackets_stack.empty()) {
            auto bracket = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            pos = bracket.position;
        }
        std::cout << pos + 1 << std::endl;
        return 0;
    }

    std::cout << "Success" << std::endl;

    return 0;
}
