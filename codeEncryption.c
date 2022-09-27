#include <stdio.h>
/*
Program Description: This is a C program which has been created to develop a security authentication program, based on an access code. The access code is 4 single-digit integers.
The program should allow a user to enter a code, encrypt the number and comapre it to an authorised access code. The program should also allow the user to decrypt an already encrypted code.
The program is menu-driven and displays the following menu when run:
    1. Enter any code
    2. Encrypt code entered and verify it correct
    3. Decrypt code
    4. Display the number of time the encrypted code entered matches the authorised code (i)Successfully (ii)Unsuccessfully
    5. Exit Program

Author: Ben O'Brien 

Operating System: Windows 10 

Compiler Version: minGW 

Made With Visual Studio Code */

// symbolic names used to prevent hard coding
#define SIZE 4

// function signatures for each individual cases
int case_1(int *);
int case_2(int *, int *, int *);
int case_3(int *, int *);
int case_4(int *);
int case_5();

int main()
{
    // declaring the variables needed for the program
    int menu;
    int casethree = 3;
    int exit_program = 0;
    int access_code[SIZE] = {4, 2, 5, 3};
    int user_code[SIZE];
    int encrypted_code[SIZE];
    int decrypted_code[SIZE];
    int check = 0;
    int code_entered = 0;
    int code_encrypted = 0;

    // do loop so the code executes atleast once
    while (exit_program != 1)
    {
        // The menu used to navigate through the program
        printf("\n**********************************************************************************************\n");
        printf("Welcome to the Code Encrypter!\n\n");
        printf("Enter a number between 1 and 5 to proceed:\n");
        printf("\n1. To enter any code, please be sure to press 'Enter' after every digit inputted\n");
        printf("2. Encrypt code and verify that it is correct:\n");
        printf("3. Decrypt The code:\n");
        printf("4. Displays the number of times the encrypted code entered matches the authorised code\n");
        printf("5. Exit Program\n");
        printf("\n**********************************************************************************************\n\n");

        // reads which number is entered
        scanf("%1d", &menu);

        // to clear characters from being entered
        getchar();

        // To separate the parts of the menu into individual cases
        switch (menu)
        {

            // case created for entering a 4-digit code
        case 1:
            case_1(user_code);
            code_entered = 1;
            code_encrypted = 0;
            fflush(stdin);
            break;
         // case end

        // Case for encrypting the 4-digit code
        case 2:
            // validation to only encrypt when a code is entered 
            if (code_entered == 1)
            {
                // validation if code is entered 
                if (code_encrypted == 0)
                {
                    case_2(user_code, encrypted_code, access_code);
                    code_encrypted = 1;
                }
                // validation if code is already encrypted
                else
                {
                    printf("The code is already encrypted");
                }

                fflush(stdin);
            }
            else
            {
                printf("Please enter a code ");
            }
            break;
         // case end //

        // case to decrypt the encrypted code
        case 3:
            // validation to see if code is entered 
            if (code_entered == 1)
            {
                // validation to decrypt when a the code is encrypted
                if (code_encrypted == 1)
                {
                    case_3(encrypted_code, decrypted_code);
                    code_encrypted = 0;
                }
                // validation if a code is not encrypted 
                else
                {
                    printf("Code is not encrypted");
                }
            }
            // validation if a code is not entered
            else
            {
                printf("Code is not entered, please try again ");
            }
            fflush(stdin);
            break;
    

        // to show the successful/unsuccessful attempts
        case 4:
        
            case_4(&casethree);
            fflush(stdin);
            break;
     

        // case created to end program
        case 5:
        
            exit_program = case_5();
            break;
      

        // default for number validation
        default:
        
            getchar();
            printf("Incorrect input entered, please try again!\n");
            fflush(stdin);
            break;

        }// default end //
    }

    return 0;
}
// function created for the user to enter any 4-digit code
int case_1(int *user_code)
{
    // declaring the local variables
    int i;
    int code_entered = 0;

    //Prompts the user to enter a code
    printf("Enter any 4-digit code, the first four digits will only be counted.\n");

    // input a 4-digit code
    for (i = 0; i < SIZE; i++)
    {
        scanf("%1d", &*(user_code + i));
    } //end for

    // clears the input buffer
    while (getchar() != '\n');

    printf("The code you have entered is: ");

    // displays the code entered to the user
    for (i = 0; i < SIZE; i++)
    {
        printf("%d", *(user_code + i));
    } //end for
}
// function for code encryption
int case_2(int *user_code, int *encrypted_code, int *access_code)
{
    // declaring local variables
    int i;
    int check;
    int caseone = 1;
    int casetwo = 2;
    int code_entered = 0;

    printf("You have chosen Option 2:");

    // switches the first position with the third position
    *(encrypted_code + 0) = *(user_code + 2) + 1;
    *(encrypted_code + 2) = *(user_code + 0) + 1;

    // switches the second position with the fourth position
    *(encrypted_code + 3) = *(user_code + 1) + 1;
    *(encrypted_code + 1) = *(user_code + 3) + 1;

    // to change inputs of 10 to 0
    for (i = 0; i < SIZE; i++)
    {
        if (*(encrypted_code + i) == 10)
        {
            *(encrypted_code + i) = 0;
        } // end if
    }     // end for

    printf("\nThe encrypted code is: ");
    // for loop created to print encrypted
    for (i = 0; i < SIZE; i++)
    {
        printf("%d", *(encrypted_code + i));
    } // end for
    // error checking if encrypted code is equal to access code or not
    for (i = 0; i < SIZE; i++)
    {
        if (*(access_code) != *(encrypted_code))
        {
            check = 0;
        } // else if
        else
        {
            check = 1;
        } // end else
    }     // end for
    // if created to check if encrypted code matches access code
    if (check == 1)
    {
        printf("\n\nEncryption successful");
        case_4(&caseone);
    } // end if
      // else created to show encryption was unsuccessful
    else
    {
        printf("\nEncryption unsuccessful, please try again");
        case_4(&casetwo);
    } // end else
}

// function for decrypting code
int case_3(int *encrypted_code, int *decrypted_code)
{
    // declaring the local variables
    int i;

    // switches the first position with the third position
    *(decrypted_code + 0) = *(encrypted_code + 2) - 1;
    *(decrypted_code + 2) = *(encrypted_code + 0) - 1;

    // switches the second position with the fourth position
    *(decrypted_code + 3) = *(encrypted_code + 1) - 1;
    *(decrypted_code + 1) = *(encrypted_code + 3) - 1;

    // to change inputs entered from '-1' to '9'
    for (i = 0; i < SIZE; i++)
    {
        if (*(decrypted_code + i) == -1)
        {
            *(decrypted_code + i) = 9;
        } // end if
    }     //end for

    printf("The decrypted code is :");
    // Prints the output of the decrypted code.
    for (i = 0; i < SIZE; i++)
    {
        printf("%d", *(decrypted_code + i));
    } //end for
}

// function for successful/unsuccessful attempts
int case_4(int *counter)
{
    // declaring the local variables
    static int successful;
    static int unsuccessful;
    switch (*counter)
    {
    // case created for successful attempts
    case 1:
        successful = successful + 1;
        break;

    // case created for unsuccessful attempts
    case 2:
        unsuccessful = unsuccessful + 1;
        break;

    // shows the user the successful/unsuccessful attempts
    case 3:
        printf("Encryption successful = %d\n", successful);
        printf("Encryption unsuccessful = %d\n", unsuccessful);
        break;
    } // end switch
}
// function for case 5
int case_5()
{
    // declaring the local variables
    char confirm_end;

    // Prompts the user to enter a either (y/n) to terminate the program
    printf("\nProgram ending. Are you sure (y/n)?\n");
    scanf("%1c", &confirm_end);

    // This clears the input buffer
    while (getchar() != '\n');

    // switch created to prompt the user with an option to confirm a graceful program end, or to be returned to the main menu
    switch (confirm_end)
    {
    case 'y':
        printf("\nGood bye\n");
        return 1;
        break;

    case 'n':
        printf("\nYou have selected 'n', returning you to the menu\n");
        break;
    default:
        printf("You have entered an invalid entry, returning you to menu\n");
        break;
    }
}

