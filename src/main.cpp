#include "programs/test.cpp"
#include "instructions.cpp"
int main(){
    Instructions sys;
    sys.loadInstructions(program);
    sys.execute();
    return 0;
}