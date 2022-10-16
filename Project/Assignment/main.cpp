#include <iostream>
#include <fstream>
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"
#include "functions.h"
#define COMMAND_AMOUNT 26


int main(int argc, char** argv){
    //Array for the lists of Command 
    std::string command_list[COMMAND_AMOUNT] = {"declscal", "declarr", "label", 
    "gosublabel", "start", "end", "exit", "jump", "jumpzero", "jumpnzero", "gosub", "return",
    "pushscal", "pusharr", "pushi", "pop", "popscal", "poparr", "dup", "swap", "add", "negate", "mul",
    "div", "printtos", "prints"};
    //Array for the Command Objects
    Command * object_list[COMMAND_AMOUNT] = {new Declscal( ), new Declarr( ), new Label( ), new Gosublabel( ), new Start( ),
    new End( ), new Exit( ), new Jump( ), new Jumpzero( ), new Jumpnzero( ), new Gosub( ), new Return( ), new Pushscal( ),
    new Pusharr( ), new Pushi( ), new Pop( ), new Popscal( ), new Poparr( ), new Dup( ), new Swap( ), new Add( ), new Negate( ), 
    new Mul( ), new Div( ), new Printtos( ), new Prints( )};

    //Create Map for the commands
    Map * command_map = new Map();
    for (int i = 0; i < COMMAND_AMOUNT; i++){
        command_map->insert(command_list[i], object_list[i]);
    }

    //Create Symbol Table:
    Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();

    //Create Statement/Instruction Buffer:
    Statement_Buffer * statement_buffer = Statement_Buffer::create_statement_buffer();

    //Opening the file
    std::ifstream myfile;
    myfile.open(argv[1]);
    std::string myline;
    if (myfile.is_open()){
       	//REPEATING END CONDITION FIXED - Joseph 
		
        //Check for start in the beginning of the file
        std::getline(myfile, myline);
        myline = cleanString(myline);
        if (myline != "start"){
            std::cout << "No start\n";
            exit(0);
        }
		Command* curr_command = command_map->lookUp(myline);
        curr_command->display();
        curr_command->add();
        
        //Check rest of the file
        while (myfile.good()){
            std::getline(myfile, myline);
            myline = cleanString(myline);
            if (myline == "end")
            {
                break;
            }
			//shift the substr(0, myline.find(" "))) into the class
			Command* curr_command = command_map->lookUp(myline);		
			curr_command->display();
            curr_command->add();
            if(curr_command -> check) {
				if(!(curr_command -> check_args(myline))) {
					std::cout << "ERROR:\n  Invalid input arguments!";
				}
    
			}
        }
        //Checks if there are any commands after end
        while (myfile.good()){
            std::getline(myfile, myline);
            myline = cleanString(myline);
            if (myline.length() !=0){
                std::cout << "ERROR:\n  There is non-space characters after end\n";
                exit(0);
            }
        }
    }
    else {
        std::cout << "ERROR:\n  Error opening the File\n";
        exit(0);
    }

    statement_buffer->printContent();
}