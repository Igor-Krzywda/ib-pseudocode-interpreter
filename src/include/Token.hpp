#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <memory>
#include <string>
#include <map>

namespace tk{

enum id{
    END_FILE,
    PLUS, MINUS, MULT, DIV_WOQ, DIV_WQ, MOD,
    LSQBR, RSQBR, LPAREN, RPAREN, QTMARK,
    LT, GT, LEQ, GEQ, DNEQ, EQ, IS,
    AND, OR, NOT,
    DOT, COMMA,
    INT, FLOAT, NUM, STRING,
    ID_VAR, ID_METHOD,
    METHOD, RETURN,
    LOOP, FROM, TO, WHILE, UNTIL,
    IF, ELSE, THEN,
    END,
    NEW_ARR, NEW_QUEUE, NEW_STACK,
    LENGTH,
    ADD_ITEM, GET_NEXT, RESET_NEXT, HAS_NEXT,
    PUSH, POP,
    ENQUEUE, DEQUEUE,
    IS_EMPTY,
    OUTPUT, INPUT
};

class Token{
    public:
        double val_num;
        std::string val_str;
        int id;
        void mutate(int id, std::string val);
        void mutate(int id, double val);
        Token() = default;
        ~Token() = default;
};

const std::map<std::string, int> RESERVED_KEYWORDS = {
    {"div", DIV_WQ},
    {"mod", MOD},
    {"AND", AND},
    {"OR", OR},
    {"NOT", NOT},
    {"method", METHOD},
    {"return", RETURN},
    {"loop", LOOP},
    {"from", FROM},
    {"to", TO},
    {"while", WHILE},
    {"until", UNTIL},
    {"if", IF},
    {"else", ELSE},
    {"then", THEN},
    {"end", END},
    {"output", OUTPUT},
    {"input", INPUT},
    {"length", LENGTH},
    {"addItem", ADD_ITEM},
    {"getNext", GET_NEXT},
    {"resetNext", RESET_NEXT},
    {"hasNext", HAS_NEXT},
    {"push", PUSH},
    {"pop", POP},
    {"enqueue", ENQUEUE},
    {"dequeue", DEQUEUE},
    {"isEmpty", IS_EMPTY},
    {"Array", NEW_ARR},
    {"Stack", NEW_STACK},
    {"Queue", NEW_QUEUE}
};

int lookup_keyword(std::string lexeme);

void print_token(Token *token);
   
std::string id_to_str(int id);


}
#endif
