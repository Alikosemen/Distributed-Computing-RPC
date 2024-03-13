// Define a structure for inputs that includes two floating-point numbers and an operator
struct inputs{
 float num1; // First number
 float num2; // Second number
 char operator; // Operator (+, -, *, /)
};
 
// Define the RPC program CALCULATE_PROG with a program number
program CALCULATE_PROG{
 version CALCULATE_VER{
   // Define remote procedure for addition, which takes 'inputs' struct and returns a float result
   float ADD(inputs)=1; 
   // Define remote procedure for subtraction, which takes 'inputs' struct and returns a float result
   float SUB(inputs)=2;
   // Define remote procedure for multiplication, which takes 'inputs' struct and returns a float result
   float MUL(inputs)=3;
   // Define remote procedure for division, which takes 'inputs' struct and returns a float result
   float DIV(inputs)=4;
  
 }=1; // Version number of the CALCULATE_VER
}=0x2fffffff; // Unique program number for CALCULATE_PROG

