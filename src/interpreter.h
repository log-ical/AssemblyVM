
#include <string>
#include <vector>
#include <cstdint>

class Interpreter {

public:
    enum class op_type
    {
        mov_reg,
        add_reg,
        sub_reg,
        int_reg, //temp print
        push_reg,
        pop_reg,
    };
    struct Opcode {
      uint16_t operand[3];
      op_type type;
    };
    enum reg_type{
        R0,
        R1,
        R2,
        R3,
        R4,
        R5,
        R6,
        R7,
        R8,
        R9
    };


    

    void parse(std::string program);
    void temp(std::string instruction); //temp for testing
    void loadInstructions(const std::vector<std::string>& program);
    void execute();

    Interpreter():line(0){}
private:
    void exeInstruction(Opcode opcode);
    uint32_t line;
    std::vector<std::string> program;
    struct keywords;
    Opcode convertToOpcode(op_type type, reg_type reg, uint32_t v1, uint32_t v2);
    op_type convertToOpType(std::string optype);
    reg_type convertToReg(std::string reg);
    void parseLine(std::string line);
    void parseSection(); //.section
    void parseGlobal();
    void parseData(std::string data); //.data
    void parseText(); //.text
    void parseConst(); //.equ/.set
    void parseOrg(); //.org
    void parseStart();
    //void parseMacro(); //%macro %endmacro
    //void parseDefine(); //%define
    //void parseInclude(); //.include

};
