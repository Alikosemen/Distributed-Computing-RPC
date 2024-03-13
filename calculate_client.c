#include "calculate.h"

// Function to perform arithmetic operations using RPC
float calculate_prog_1(char *host, float n1, float n2, char opr, CLIENT *clnt)
{
    float *result_1;
    inputs add_1_arg;
    float *result_2;
    inputs sub_1_arg;
    float *result_3;
    inputs mul_1_arg;
    float *result_4;
    inputs div_1_arg;

    // Check which operation to perform based on the operator
    if(opr=='+'){
        // Set up arguments for addition
        add_1_arg.num1 = n1;
        add_1_arg.num2 = n2;
        add_1_arg.operator = opr;
  
        // Call the add function
        result_1 = add_1(&add_1_arg, clnt);
        if (result_1 == (float *) NULL) {
            clnt_perror(clnt, "call failed");
        }
        return *result_1;
    }
    else if(opr=='-'){
        // Set up arguments for subtraction
        sub_1_arg.num1 = n1;
        sub_1_arg.num2 = n2;
        sub_1_arg.operator = opr;
  
        // Call the subtract function
        result_2 = sub_1(&sub_1_arg, clnt);
        if (result_2 == (float *) NULL) {
            clnt_perror(clnt, "call failed");
        }
        return *result_2;
    }
    else if(opr=='*'){
        // Set up arguments for multiplication
        mul_1_arg.num1 = n1;
        mul_1_arg.num2 = n2;
        mul_1_arg.operator = opr;
  
        // Call the multiply function
        result_3 = mul_1(&mul_1_arg, clnt);
        if (result_3 == (float *) NULL) {
            clnt_perror(clnt, "call failed");
        }
        return *result_3;
    }
    else if(opr=='/'){
        // Set up arguments for division
        div_1_arg.num1 = n1;
        div_1_arg.num2 = n2;
        div_1_arg.operator = opr;
  
        // Check for division by zero
        if(n2 == 0){
            printf("Division by zero is not valid.\n");
            exit(0);
        }else{
            // Call the divide function
            result_4 = div_1(&div_1_arg, clnt);
            if (result_4 == (float *) NULL) {
                clnt_perror(clnt, "call failed");
            }
            return *result_4;
        }
    }
}

int main (int argc, char *argv[])
{
    char *host;
    float a,b;
    char op;
    CLIENT *clnt;

    // Ensure server host is provided
    if (argc < 2) {
        printf ("usage: %s server_host\n", argv[0]);
        exit (1);
    }
  
    // Prompt user for input
    printf("Welcome to Quick Cal!!!\n");
    printf("+ for Addition\n- for Substraction\n* for Multiplication\n/ for Division\n");
    printf("Enter number 1 :\n");
    scanf("%f",&a);
    printf("Enter number 2 :\n");
    scanf("%f",&b);
    printf("Enter the Operator :\n");
    scanf("%s",&op); 
  
    host = argv[1];
  
    // Create RPC client
    clnt = clnt_create (host, CALCULATE_PROG, CALCULATE_VER, "udp");
  
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
  
    // Perform calculation and print result
    printf("The Answer = %f\n", calculate_prog_1(host, a, b, op, clnt));
  
    // Destroy RPC client
    clnt_destroy(clnt);
  
    exit(0);
}

