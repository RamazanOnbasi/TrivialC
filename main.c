#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


int menu();
int operations(int selection);
int zero();
void one();
void two();
void three();
void four();
int four_Second(int y[], int x); // A.k.a. Second
void five();
void six();


int main()
{
    menu();

    return 0;
}


int menu()
{
    int selection;

    printf("0. Exit\n");
    printf("1. Solving the mathematical equation\n");
    printf("2. Drawing the diamond shape\n");
    printf("3. Printing keyboard inputs in reverse\n");
    printf("4. Finding the second smallest element\n");
    printf("5. Distinct random number generation\n");
    printf("6. About\n\n\n");

    printf("Enter your selection: ");
    scanf("%d", &selection);
    printf("\n");

    operations(selection);

    return 0;
                                                              }

int operations(int selection)
{
    switch(selection)
{

    case 0:
{
    zero();
    break;
                          }

    case 1:
{
    printf(" N  \n");
    printf(" ∑------------\n");
    printf("i=1");


    one();
    printf("\n\n\n");
    return menu();
                        }

    case 2:
{
    two();
    printf("\n\n\n");
    return menu();
                         }

    case 3:
{

    fseek(stdin,0,SEEK_END); //It empties the buffer.
    printf("Write some inputs: ");
    three();
    printf("\n\n\n");
    return menu();
                        }

    case 4:
{
    four();
    printf("\n\n\n");
    return menu();
                         }

    case 5:
{
    five();
    printf("\n\n\n");
    return menu();
                            }

    case 6:
{
    six();
    printf("\n\n\n");
    return menu();
                             }

    default:
{
     printf("You must enter a number between 0-6!\a\n\n");
     return menu();
                                                           }
                                                            }
    return 0;
}

int zero()
{
    char confirmation;

    printf("Are you sure that you want to program to be closed? (Y/N)\n");
    scanf(" %c", &confirmation);

    if(confirmation == 'Y' || confirmation == 'y')
    return 0;

    else if (confirmation == 'N' || confirmation == 'n')
{
     printf("\n");
     return menu();
                                                         }

    else
{
     printf("\nYou must enter either Y or N!\a\n");
     return zero();
                                                  }
}

void one()
{
  int N, R, S;
  int k, j;
  double a;
  double r1=1, r2=0, r3;

  printf("Enter the value of N: ");
  scanf("%d", &N);

  while(N<1)

{
  printf("You must enter a POSITIVE value for N: \a");
  scanf(" %d", &N);
                                                      }

  printf("Enter the value of R: ");
  scanf(" %d", &R);

  while(R<1)
  {
  printf("You must enter a POSITIVE value for R: \a");
  scanf(" %d", &R);
                                                      }

  printf("Enter the value of S: ");
  scanf(" %d", &S);

  while(S<1)
{
  printf("You must enter a POSITIVE value for S: \a");
  scanf(" %d", &S);
                                                      }

  for(k=1; k<=R; ++k)
  {
   a=(3*pow(k, 3)+5)/pow(k, 2);
   r1*=a;
  }

  for(j=1; j<=S; ++j)
  {
   a=sqrt(3*pow(j, 3)+j+2)/(2*j);
   r2+=a;
  }

  r3=(r1/r2)*N;


  printf("\nThe result of the equation is %f", r3);
}

void two()
{
    int lines, spaces, dots=1;
    int i, j;

    printf("Enter the number of the lines of the diamond: ");
    scanf("%d", &lines);

    while(lines<=2 || lines%2==0)
{
    if(lines<=2)
{
    printf("You must enter a greater value than 2 for the lines: \a");
    scanf("%d", &lines);
                                                                      }
    else
{
     printf("You must enter an odd number for the lines of the diamond: \a");
     scanf("%d", &lines);
                                                                             }
                                                                              }

    printf("\n");

    spaces=(lines-1)/2;

    for(i=1; i<=(lines+1)/2; ++i)
{
    for(j=1; j<=spaces; ++j)
       printf(" ");
       --spaces;

    for(j=1; j<=dots; ++j)
       printf("*");
       printf("\n");
       dots+=2;
                                 }

    spaces=1;
    dots=(lines-2);


    for(i=1; i<=(lines-1)/2; ++i)
{
    for(j=1; j<=spaces; ++j)
       printf(" ");
       ++spaces;

    for(j=1; j<=dots; ++j)
       printf("*");
       printf("\n");
       dots-=2;
                                 }
}

void three()
{
    char inputs;

    scanf("%c", &inputs);

    if(inputs != '\n')
{
    three();
    printf("%c", inputs);
                           }
    else
    printf("Reversed version of the inputs: ");
}

void four()
{
    int a=0;
    int number[a];
    int second;

    printf("Enter a positive number: ");
    scanf("%d", &number[a]);

    while(number[a]<=0)
{
    if(number[a] == -1)
{
    printf("You cannot exit before entering at least 2 positive numbers!\a\n");
    printf("Enter a positive number: ");
    scanf("%d", &number[a]);

                                                                             }

    else
{
    printf("You must enter a POSITIVE NUMBER: \a");
    scanf("%d", &number[a]);
                                                  }
                                                   }

    ++a;

    printf("Enter a positive number: ");
    scanf("%d", &number[a]);


    while(number[a]<=0)
{
    if(number[a] == -1)
{
    printf("You cannot exit before entering at least 2 positive numbers!\a\n");
    printf("Enter a positive number: ");
    scanf("%d", &number[a]);

                                                                           }

    else
{
    printf("You must enter a POSITIVE NUMBER: \a");
    scanf("%d", &number[a]);
                                                  }
                                                   }
    ++a;

    while(number[a] != -1)
{
    printf("Enter a positive number (Enter -1 to exit): ");
    scanf("%d", &number[a]);
    if(number[a]>0)
    ++a;

    else if(number[a]<-1 || number[a]==0)
    printf("You must enter a POSITIVE NUMBER (or -1 to exit)\a\n");
                                                                   }
    second=four_Second(number, a-1);

    printf("\nThe second smallest number is %d\n\n\n", second);
}

int four_Second(int y[], int x) // A.k.a. Second
{
    int smallest, second_smallest;
    int i;

    smallest=y[0];

    for(i=0; i<=x; ++i)
{
    if(y[i]<smallest)
    smallest=y[i];

    else
    second_smallest=y[i];
                             }

    for(i=0; i<=x; ++i)
{
    if(y[i]>smallest && y[i]<second_smallest)
    second_smallest=y[i];
                                              }

    if(smallest==second_smallest)
{
    printf("There's no second smallest number!\a\n\n\n");
    return menu();
                                                         }

    return second_smallest;
}

void five()
{
    int y[19];
    int x=0;
    int i, a;

    srand(time(NULL));

    while(x<=19)
{
    a=1+rand()%20;

    for(i=0; i<x; ++i)
    if(y[i]==a)
    break;

    if(i==x)
{
    y[x]=a;
    ++x;
                       }
                        }

    for(i=0; i<=19; ++i)
    printf("%d. slot: \t%d\n", i+1, y[i]);
}

void six()
{
 setlocale(LC_CTYPE, "Turkish"); //Turkish character support.

 printf("The creators of the project");
 printf("Ramazan ONBAŞI\\n");
}


