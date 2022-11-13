#include <string>
#include <iostream>
#include "data_memory.h"

Data_Memory* Data_Memory::instance = nullptr;

Data_Memory::Data_Memory(){}

Data_Memory * Data_Memory::create_data_memory() {
    if (instance == NULL){
        instance = new Data_Memory();
    }
    return instance;
}

void Data_Memory::add_data(std::string item){
    TwoTuple * new_item = new TwoTuple(item);
    data_memory.push_back(new_item);
}

void Data_Memory::printContent(){
    std::cout << "Data Memory: \n";
    for (int i = 0; i < data_memory.size(); i++)
    {
        std::cout << "  " << data_memory.at(i)->name << ", " << data_memory.at(i)->value << "\n";
    }
}