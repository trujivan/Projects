// creating a menu driven tool to assist users with circuit calculations. (V=IR)

#include <stdio.h>
int main(void) {

float V = 0;
float R = 0;
float I = 0;

printf("Welcome to the simple circuit calculator\n"); // printing introduction
printf("\n");

printf("please choose one of the following options\n"); // printing out options for user

printf("1 - Calculate resistance\n");
printf("2 - Calculate current\n");
printf("3 - Calculate voltage\n");
printf("4 - Exit\n");

printf("Enter your choice: \n");
printf("\n");

int pick=0; // setting pick as an interger so that we can use it later in our if command
  scanf("%d", &pick); // scanning the input of the user

while (pick!=4) { // creating a whileloop so that exit option can be excluded from loop

if (pick==1) { // setting up conditions for loop for what should be done in certain circumstances
  printf("Enter the voltage in Volts: \n");
  scanf("%f", &V);
  printf("Enter the current in Amps: \n");
  scanf("%f", &I);
R = V / I; // eqution to solve for
  printf("Given the voltage of %f Volts, and the current of %f Amps, the resistance is %f Ohms \n", V, I, R); // printing results

}

else if (pick==2) {  // setting up conditions for loop for what should be done in certain circumstances
 printf("Enter the voltage in Volts: \n");
 scanf("%f", &V);
 printf("Enter the resistance in Ohms: \n");
 scanf("%f", &R);
I = V / R;
printf("Given the voltage of %f Volts, and the resisteance of %f Ohms, the current is %f Amps \n", V, R, I);

}

else if (pick==3) {  // setting up conditions for loop for what should be done in certain circumstances
 printf("Enter the resistance in Ohms: \n");
 scanf("%f", &R);
 printf("Enter the current in Amps: \n");
 scanf("%f", &I);
V = I * R;
printf("Given the resistance of %f Ohms, and the current of %f Amps, the voltage is %f Volts \n", R, I, V);

}

printf("\n");
printf("please choose one of the following options\n"); // offering the user if they would like to pick again

printf("1 - Calculate resistance\n");
printf("2 - Calculate current\n");
printf("3 - Calculate voltage\n");
printf("4 - Exit\n");
printf("\n");

printf("Enter your choice: \n");

scanf("%d", &pick);

} //this bracket is the end of the loop

printf("Thanks for using the simple circuit calculator\n"); // if none of the options from the loop is selected default command is to exit, which is option 4 and this statement will apear.


return 0;

}




// char array [] = string
