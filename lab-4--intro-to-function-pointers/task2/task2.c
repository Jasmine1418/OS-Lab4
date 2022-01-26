#include <stdio.h>
#include <stdlib.h>


/* IMPLEMENT ME: Declare your functions here */
int(*operator[4])(int a, int b);
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);
int exit_prog();

int(*operands[5])(int a, int b);

int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */
  int num1 = 7;
  int num2 = 2;
  int oper;

  operands[0] = &add;
  operands[1] = &subtract;
  operands[2] = &multiply;
  operands[3] = &divide;
  operands[4] = &exit_prog;

    printf("Operand 'a': %d\n", num1);
    printf("Operand 'b': %d\n", num2);

  while(oper!=4){
    printf("Indicate which operation to complete by entering 0, 1, 2, or 3: \n'0'- Add\n'1'- Subtract\n'2'- Multiply\n'3'- Divide\n'4'- Exit Program\n");
    scanf("%d", &oper);

    int result = (*operands[oper]) (num1, num2);
    printf("Result = %d\n", result);
  }
	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { 
  printf ("Adding 'a' and 'b'\n"); 
  return a + b; 
}
int subtract (int a, int b) { 
  printf ("Subtracting 'a' and 'b'\n"); 
  return a - b; 
}
int multiply (int a, int b) { 
  printf ("Multiplying 'a' and 'b'\n"); 
  return a * b; 
}
int divide (int a, int b) { 
  printf ("Dividing 'a' and 'b'\n"); 
  return a / b; 
}
int exit_prog(int a, int b){
  printf("Exiting the program\n");
  exit(0);
}
