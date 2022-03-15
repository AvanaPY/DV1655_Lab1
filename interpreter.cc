#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define STACK_SIZE 2048

void
read_program(std::string file_name, 
             std::vector<std::pair<std::string, std::string>>* program,
             std::map<std::string, int>* label_map)
{
    std::string op, arg;
    std::pair<std::string, std::string> p;
    int i;
    std::string line;
    std::ifstream myfile (file_name);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            if(line.length() == 0)
                continue;

            if(line.find(":") != -1)
            {
                label_map->insert(std::pair<std::string, int>(line.substr(0, line.size() - 1), program->size()));
            }
            else
            {
                line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());

                i = line.rfind(" ");
                if(i == -1)
                {
                    op = line;
                    arg = "";
                }
                else
                {
                    op = line.substr(0, i);
                    arg = line.substr(i + 1, line.length());
                }

                p.first = op;
                p.second = arg;
                program->push_back(p);
            }
        }
        myfile.close();
    }

    else std::cout << "Unable to open file"; 
}

void
execute(std::vector<std::pair<std::string, std::string>>* program,
        std::map<std::string, int>* label_map)
{
    std::stack<int> data_stack;
    std::stack<int> acti_stack;
    std::map<std::string, int> variables;
    
    bool executing = true;

    std::string op, arg;
    int instruction_counter = 0;

    while(executing)
    {
        op = program->at(instruction_counter).first;
        arg = program->at(instruction_counter).second;

        if(op == "iload")
        {
            data_stack.push(variables[arg]);
        }
        else if(op == "iconst")
        {
            data_stack.push(stoi(arg));
        }
        else if(op == "istore")
        {
            int num = data_stack.top(); data_stack.pop();
            variables.insert(std::pair<std::string, int>(arg, num));
        }
        else if(op == "iadd")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num1 + num2);
        }
        else if(op == "isub")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 - num1);
        }
        else if(op == "imul")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 * num1);
        }
        else if(op == "idiv")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 / num1);
        }
        else if(op == "ilt")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 < num1);
        }
        else if(op == "igt")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 > num1);
        }
        else if(op == "ieq")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 == num1);
        }
        else if(op == "iand")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num1 && num2);
        }
        else if(op == "ior")
        {
            int num1 = data_stack.top(); data_stack.pop();
            int num2 = data_stack.top(); data_stack.pop();
            data_stack.push(num2 || num1);
        }
        else if(op == "inot")
        {
            int num1 = data_stack.top(); data_stack.pop();
            data_stack.push(num1 == 1 ? 0 : 1);
        }
        else if(op == "invokevirtual")
        {
            acti_stack.push(instruction_counter + 1);
            int new_instruction_counter = (*label_map)[arg];
            instruction_counter = new_instruction_counter - 1;
        }
        else if(op == "ireturn")
        {
            int new_instruction_counter = acti_stack.top(); acti_stack.pop();
            instruction_counter = new_instruction_counter - 1;
        }
        else if(op == "print")
        {
            int num = data_stack.top(); data_stack.pop();
            std::cout << num << "\n";
        }
        else if(op == "stop")
        {
            executing = false;
        }
        else
        {
            std::cout << "Instruction " << op << " not implemented\n";
        }
        instruction_counter++;
    }
    std::cout << "Finished Execution\n";
}

int main(void)
{
    std::string code_file_name = "code.mjbc";
    std::vector<std::pair<std::string, std::string>> program;
    std::map<std::string, int> label_map;
    
    read_program(code_file_name, &program, &label_map);
    execute(&program, &label_map);

    return 0;
}