#include "programs/test.cpp"
#include "interpreter.cpp"
int main(){
    Interpreter sys;
    sys.loadInstructions(program);
    sys.execute();
    return 0;
}