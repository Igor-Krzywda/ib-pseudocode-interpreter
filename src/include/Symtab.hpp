#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include "Token.hpp"
#include "AST.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <memory>
#include <utility>

namespace sym{

enum types{
    NUM, STRING,
    ARR_N, ARR_STR, STACK, 
    QUEUE, METHOD, PARAM
};

typedef std::vector<unsigned> dimensions;
typedef std::vector<std::string> data;

class Reference{
private:
public:
    Reference();
    Reference(dimensions *d, data *dt);
    void push_dimension(int d);
    void push_data(std::string d);
    void set_type(int type);
    void print_reference();
    int type;
    dimensions dim;
    data dat;
};

typedef std::unordered_map<std::string, std::unique_ptr<Reference>> symtab;
typedef std::map<std::string, std::unique_ptr<symtab>> scope;

class Symtab{
private:
    scope scopes;
public:
    Symtab();
    void new_scope(std::string name, ast::AST *root);
    void insert(std::string scope, std::string key, Reference *ref);
    Reference *lookup(std::string scope, std::string key);
    bool is_logged(std::string scope, std::string key);
    void print_symtab();
};

void test_table();

}
#endif
