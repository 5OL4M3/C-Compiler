#ifndef STATEMENT_BUFFER_H_
#define STATEMENT_BUFFER_H_

#include <string>
#include <map>
#include <iostream>
#include "map.h"
#include "symbol_table.h"
#include "command.h"
#include <vector>

class Statement_Buffer{
private:
    static Statement_Buffer * instance;
    static std::vector<Command *> statement_vector;
    Statement_Buffer();
public:
    static Statement_Buffer * create_statement_buffer(); 
    static void add_statement(Command *);
    static void printContent();
};
//Determines what command is being declared 

#endif