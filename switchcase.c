// Opeators in C
# include <stdio.h>
# include <stdbool.h>

int main() {
  bool choice = true;
  int a, b, selection;
  while (choice) {
      printf("Enter two integers");
      printf("\na =");
      scanf("%d", &a);
      printf("b =");
      scanf("%d", &b);
      
      printf("\n1. Addition");
      printf("\n2. Subraction");
      printf("\n3. Multiplication");
      printf("\n4. Division");
      printf("\nType the number for an operation: ");
      scanf("%d", &selection);
      
      switch (selection) {
          case 1:  printf("Addition result is %d", a + b);
                     break;
          case 2:  printf("Subtraction result is %d", a - b);
                     break;
          case 3:  printf("Multiplication result is %d", a * b);
                     break;
          case 4:  printf("Division result is %d", a / b);
                     break;
          default: printf("Invalid Selection");
      }
      printf("\nDo U wish to continue? (0 for NO / Non zero for YES)");
      scanf("%d", &choice);
  }
  return 0;
}

/*
/tmp/QdqX5wYiHr.o
Enter two integers
a =20
b =10

1. Addition
2. Subraction
3. Multiplication
4. DivisionType the number for an operation: 2
Subtraction result is 10
Do U wish to continue? (0 for NO / Non zero for YES)5
Enter two integers
a =8
b =9

1. Addition
2. Subraction
3. Multiplication
4. DivisionType the number for an operation: 7
Invalid Selection
Do U wish to continue? (0 for NO / Non zero for YES)0


=== Code Execution Successful ===
*/
