#ifndef STRING_BUFFER_H_
#define STRING_BUFFER_H_

#include <string>
#include <iostream>
#include "symbol_table.h"
#include "command.h"
#include <vector>

class String_Buffer{
private:
    static String_Buffer * instance;
    static std::vector<std::string> string_vector;
    String_Buffer();
public:
    static String_Buffer * create_string_buffer(); 
    static void add_statement(Command *);
    static void printContent();
    static int find_location(std::string);
    static void print_str_at(int);
};
//Determines what command is being declared 

#endif