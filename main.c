/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Logic
 *
 * Created on April 20, 2020, 11:55 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void PassCodeDisplay(void);
void WelcomeDisplay(void);
void DateTimeDisplay(void);
int AdminDisplay(void);
void DisplayRegisteredParties(char *Ragged_Array[], int Array_Size);
void VoterMenuDisplay(void);
void Wrt_Voters(void);
double Result_Percent(int);

typedef enum
{
    Register_PP = 1,
    Exit_Program
} AdminMenu;
AdminMenu Administrator_Menu;

typedef enum
{
    start_voting = 1,
    Exit_program
} SubMenu;
SubMenu Sub_Menu;

typedef enum
{
    Next_Voter = 1,
    Current_Statistics,
    End_Voting_Process
} VotMenu;
VotMenu Voter_Menu;

int selection, registered, PassCode;
/*
 * 
 */
void PassCodeDisplay(void)
{
    int PassCode_cnt = 0;
    do
    {
        printf("Administrative PassCode\n");
        printf(" >>"), scanf("%d", &PassCode);
        PassCode_cnt++;        /*Counts the amount of error in PassCode trials*/
        if (PassCode_cnt == 3) /*terminates your program whenever you input three wrong PassCodes*/
        {
            printf(" You Have incorrectly typed your PassCode %d times, Terminating program...\n", PassCode_cnt);
            exit(0);
        }
    } while (PassCode != 9920);
}

void WelcomeDisplay(void)
{

    printf("\t|||||||||||||||||||||||||||||||||||\n");
    printf("\t||INDEPENDENT ELECTORAL COMISSION||\n");
    printf("\t|||||||MOBILE VOTING SYSTEM||||||||\n");
    printf("\t|||||||||||||||||||||||||||||||||||\n");
    putchar('\n');
    printf(" Welcome Administrator,\n ");
}

void DateTimeDisplay(void)
{
    printf("%s\n%s\n", __DATE__, __TIME__);
}

int AdminDisplay(void)
{
    selection = 0;
    printf("ADMINISTRATOR:\n ");
    printf("1. Register Political Parties.\n");
    printf(" 2. Exit Program.\n");
    printf(" >>");
    scanf("%d", &selection);
    return selection;
}

int SubDisplay(void)
{
    printf("ADMINISTRATOR SUBMENU:\n ");
    printf("1. Start Voting.\n");
    printf(" 2. Exit Program.\n");
    printf(" >>");
    scanf("%d", &selection);
    return selection;
}

void DisplayRegisteredParties(char *Politcal_PartiesDB[], int NPolitical_Parties)
{
    for (registered = 1; registered <= NPolitical_Parties; registered++)
    {
        printf("%d. %s\n", registered, Politcal_PartiesDB[registered]);
    }
}

int main(int argc, char **argv)
{
    int *VotesDB, NVoters, VoterID, Decision, NPolitical_Parties = 0;
    char **Political_PartiesDB;

    DateTimeDisplay();
    WelcomeDisplay();
    PassCodeDisplay();

    if (PassCode == 9920)
    {
        DateTimeDisplay();
        WelcomeDisplay();
        switch (AdminDisplay())
        {
        case Register_PP:
            printf("How many political parties do you want to register?\n >>");
            scanf("%d", &NPolitical_Parties);
            *Political_PartiesDB[5];
            printf("Enter Names Of Political Parties.\n");
            for (registered = 1; registered <= NPolitical_Parties; registered++)
            {
                printf("Political Party %d of %d\n >>", registered, NPolitical_Parties);
                Political_PartiesDB[registered] = (char *)calloc(10, sizeof(char));
                assert(Political_PartiesDB[registered] != NULL);
                scanf("%s", Political_PartiesDB[registered]);
            }
            printf("Magnitude Of The Voters:\n >>");
            scanf("%d", &NVoters);
            //system("clear");
            switch (SubDisplay())
            {
            case start_voting:
                VotesDB = calloc(NVoters, sizeof(int));
                for (VoterID = 1; VoterID <= NVoters; VoterID++)
                {
                    printf("Registered Parties:\n");
                    DisplayRegisteredParties(Political_PartiesDB, NPolitical_Parties);
                    printf("Cast Your Vote -> Voter %d\n>>", VoterID);
                    scanf("%d", &Decision);
                    VotesDB[Decision]++;
                    //system("clear");
                }

            case Exit_program:
                exit(0);
            default:
                printf("\nERROR: Wrong Selection!\n");
                exit(0);
            }

        case Exit_Program:
            exit(0);

        default:
            printf("\nERROR: Wrong Selection!\n");
            exit(0);
        }
    }
    else
    {
        printf("PassCode incorrect! Try Again.");
    }
}
