#include<iostream>
#include <fstream>
#include<string.h>
#include <list>
#include "Node.h"
#include <map>


namespace IR
{
extern map<std::string, std::string> opmap;
extern map<std::string, int> bool_map;
extern map<std::string, std::string> op_byte_code;

class TAC {
protected:
    std::string result, op, lhs, rhs;

public:
    TAC(std::string res, std::string o, std::string l, std::string r) : op(o), lhs(l), rhs(r), result(res){}
    
    virtual void dump(std::ofstream& stream)
    {
        stream  << result 
                << " := "
                << op << " " 
                << lhs << " " 
                << rhs;
    }
    string get_result()
    {
        return result;
    }
    void set_result(string res)
    {
        result = res;
    }

    string get_lhs()
    {
        return lhs;
    }
    string get_rhs()
    {
        return rhs;
    }
    string get_op()
    {
        return op;
    }

    void dump_lhs(std::ofstream& stream)
    {
        stream << value_to_instruction(lhs);
    }
    
    void dump_rhs(std::ofstream& stream)
    {
        stream << value_to_instruction(rhs);
    }

    void dump_op(std::ofstream& stream)
    {
        if(op.size() == 0)
            return;
        string op_bc = op_byte_code[op];
        stream << "\t" << op_bc << "\n";
    }

    void dump_result(std::ofstream& stream)
    {
        if(result.size() == 0)
            return;

        if(result.find("_+") == -1)
        {
            stream << "\tistore " << result << "\n";
        }
    }

    std::string value_to_instruction(std::string v)
    {
        if(v.find("_+") != -1 || v.size() == 0)
            return "";

        std::string res;
        if(bool_map.count(v) != 0)
        {
            res = "\ticonst " + bool_map[v];
        }
        else if(v.find("$") == -1)
        {
            res = "\tiload " + v;
        }
        else
        {
            res = "\ticonst " + v.substr(1, v.size() - 1);
        }
        return res + "\n";
    }

    virtual void stack_with(TAC* tac) {};
    virtual void dump_code(std::ofstream& stream){};
    virtual void dump_code(std::ofstream& stream, std::string argument){};
    virtual void dump_code(std::ofstream& stream, std::string arg1, std::string arg2){};
};

class AssignTAC : public TAC {
public:
    AssignTAC(std::string res, std::string o, std::string l, std::string r) : TAC(res, o, l, r){}

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        dump_result(stream);
    }
};

class CondTAC : public TAC {
public:
    CondTAC(std::string stmt_type, std::string o, std::string l, std::string r) : TAC(stmt_type, o, l, r){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " " 
                << op << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }
    
    void dump_code(std::ofstream& stream, std::string true_exit, std::string false_exit)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        stream << "\tiffalse goto \n\t\t" << false_exit << "\n";
    }
    
    void dump_code(std::ofstream& stream, std::string true_exit, std::string false_exit, std::string org_exit)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        stream << "\tiffalse goto \n\t\t" << false_exit << "\n";
    }
};

class PrintTAC : public TAC {
public:
    PrintTAC(std::string lhs) : TAC("PRINT", "", lhs, ""){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " "
                << op  << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        if(lhs.find("$") != -1)
            stream << "\ticonst " << lhs.substr(1, lhs.size() - 1) << "\n";
        stream << "\tprint\n";
    }
};

class ParamTAC : public TAC {
public:
    ParamTAC(std::string name) : TAC("", "param", "", name){}

    void dump(std::ofstream& stream)
    {
        stream  << result << " "
                << lhs << " "
                << op  << " "
                << rhs;
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        stream << value_to_instruction(rhs);
    }
};

class CallTAC : public TAC {
public:
    CallTAC(std::string res, std::string name, int params) : TAC(res, "call", name, std::to_string(params)){}

    void stack_with(TAC* tac)
    {
        result = tac->get_result();
    }

    void dump_code(std::ofstream& stream, std::string class_name)
    {
        stream << "\tinvokevirtual " << class_name << "_" << lhs << "\n";
    }
};

class ReturnTAC : public TAC {
public:
    ReturnTAC(std::string res) : TAC("", "", res, ""){}

    void dump(std::ofstream& stream)
    {
        stream  << "RETURN " << lhs; 
    }

    void stack_with(TAC* tac)
    {
        lhs = tac->get_lhs();
        rhs = tac->get_rhs();
        op = tac->get_op();
    }

    void dump_code(std::ofstream& stream)
    {
        dump_lhs(stream);
        dump_rhs(stream);
        dump_op(stream);
        dump_result(stream);
        stream << "\tireturn\n";
    }
};
};