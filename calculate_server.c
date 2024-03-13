#include "calculate.h"

// Service function for addition
float * add_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Declare a static result variable to hold the operation result
    
    // Perform addition
    result = argp->num1 + argp->num2;
    // Log request details
    printf("Got Request: Adding %f and %f\n", argp->num1, argp->num2);
    // Log response details
    printf("Sent Response: %f\n", result);
    
    return &result; // Return a pointer to the result
}

// Service function for subtraction
float * sub_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Declare a static result variable to hold the operation result
    
    // Perform subtraction
    result = argp->num1 - argp->num2;
    // Log request details
    printf("Got Request: Subtracting %f from %f\n", argp->num2, argp->num1);
    // Log response details
    printf("Sent Response: %f\n", result);
    
    return &result; // Return a pointer to the result
}

// Service function for multiplication
float * mul_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Declare a static result variable to hold the operation result
    
    // Perform multiplication
    result = argp->num1 * argp->num2;
    // Log request details
    printf("Got Request: Multiplying %f by %f\n", argp->num1, argp->num2);
    // Log response details
    printf("Sent Response: %f\n", result);
    
    return &result; // Return a pointer to the result
}

// Service function for division
float * div_1_svc(inputs *argp, struct svc_req *rqstp)
{
    static float result; // Declare a static result variable to hold the operation result
    
    // Perform division
    result = argp->num1 / argp->num2;
    // Check for division by zero
    if(argp->num2 == 0) {
        printf("Error: Division by zero.\n");
        result = 0; // Set result to zero or an error value
        return &result; // Return a pointer to the result
    }
    // Log request details
    printf("Got Request: Dividing %f by %f\n", argp->num1, argp->num2);
    // Log response details
    printf("Sent Response: %f\n", result);
    
    return &result; // Return a pointer to the result
}
