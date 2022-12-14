#ifndef TABLE_ENTRY_H
#define TABLE_ENTRY_H
#include <iostream>
#include <fstream>
#include <vector>


//tuple with string and two ints
class Table_Entry{
public:
    Table_Entry(std::string _name, int _index, int _size, int _scope);
    std::string get_name();
    int get_index();
    int get_size();
    int get_scope();
private:
    std::string name;
    int index;
    int size;
    int scope;
};

#endif