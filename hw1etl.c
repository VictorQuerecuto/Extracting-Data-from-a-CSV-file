#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airPdata.h"

void PrintData(airPdata *airport);

int main(int argc, char **argv){
    char *filename = argv[1], buffer[10000], *tempStr;
    FILE *ifp;
    airPdata *myData;

    //Open file and check that file is not NULL
    if(NULL == (ifp = fopen(filename, "r")))
    {
        fprintf(stderr, "etl ERROR: File %s not found.\n", filename);
        return -1;
    }

    //Print format for header
    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s Tower\n", "FAA Site", "Short Name", "Airport Name", "City", "ST", "Latitude", "Longitude");
    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s =====\n", "========", "==========", "============", "====", "==", "========", "=========");

    //Allocate memory for struct and pointers inside the struct
    myData = malloc(sizeof(airPdata));
    if(myData == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for siteNumber
    myData->siteNumber = malloc(sizeof(char) * (50 + 1));
    if(myData->siteNumber == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for LocID
    myData->LocID = malloc(sizeof(char) * (50 + 1));
    if(myData->LocID == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for fieldName
    myData->fieldName = malloc(sizeof(char) * (50 + 1));
    if(myData->fieldName == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for city
    myData->city = malloc(sizeof(char) * (50 + 1));
    if(myData->city == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for state
    myData->state = malloc(sizeof(char) * (50 + 1));
    if(myData->state == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for latitude
    myData->latitude = malloc(sizeof(char) * (50 + 1));
    if(myData->latitude == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //malloc for longitude
    myData->longitude = malloc(sizeof(char) * (50 + 1));
    if(myData->longitude == NULL){
        printf("Not enough memory to store.");
        return -1;
    }

    //Declaration for loop counters
    int i, j=0, count = 0;

    //this loop reads in the entire contants of the file and store in in a buffer
    while(fgets(buffer, sizeof(buffer), ifp) != NULL)
    {
        tempStr = strtok(buffer, "\n"); // The use of strtok here is to tokenize each line in the file usng the "\n" as the tokenizer condition

        char comma = ',';

        //This loop treaverses each line that has been tokenized and stored in tempstr. Each character that is read is put through a conditional statement that compares it to a comma
        //if a comma is not found the character is assigned to the struct array, if a comma is found the field count increase by 1 and we move to the next field.
        for(i = 0; i < strlen(tempStr); i++)
        {
            if(tempStr[i] != comma && count == 0)
            {
                myData->siteNumber[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 0)
            {
                count ++;
                myData->siteNumber[j] = '\0';
                j = 0;
                continue;
            }

            if(tempStr[i] != comma && count == 1)
            {
                myData->LocID[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 1)
            {
                count++;
                myData->LocID[j] = '\0';
                j = 0;
                continue;
            }
            if(tempStr[i] != comma && count == 2)
            {
                myData->fieldName[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 2)
            {
                count++;
                myData->fieldName[j] = '\0';
                j = 0;
                continue;
            }
            if(tempStr[i] != comma && count == 3)
            {
                myData->city[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 3)
            {
                count ++;
                myData->city[j] = '\0';
                j = 0;
                continue;
            }
             if(tempStr[i] != comma && count == 4)
            {
                myData->state[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 4)
            {
                count ++;
                myData->state[j] = '\0';
                j = 0;
                continue;
            }
             if(tempStr[i] != comma && count == 5)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 5)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 6)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 6)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 7)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 7)
            {
                count ++;
                continue;
            }
             if(tempStr[i] != comma && count == 8)
            {
                myData->latitude[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 8)
            {
                count ++;
                myData->latitude[j] = '\0';
                j = 0;
                continue;
            }
             if(tempStr[i] != comma && count == 9)
            {
                myData->longitude[j] = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 9)
            {
                count ++;
                myData->longitude[j] = '\0';
                j = 0;
                continue;
            }
               if(tempStr[i] != comma && count == 10)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 10)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 11)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 11)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 12)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 12)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 13)
            {
                //nothing will happen here this is where a blank comma is found
            }
            else if(tempStr[i] == comma && count == 13)
            {
                count ++;
                continue;
            }
               if(tempStr[i] != comma && count == 14)
            {
                myData->controlTower = tempStr[i];
                j++;
            }
            else if(tempStr[i] == comma && count == 14)
            {
                count = 0;
                j = 0;
                break;
            }



        }
//Print final data
PrintData(myData);
    }


    //close file
    fclose(ifp);

    //free all varibles in struct
    free(myData->siteNumber);
    free(myData->LocID);
    free(myData->fieldName);
    free(myData->city);
    free(myData->state);
    free(myData->latitude);
    free(myData->longitude);

    //free strcut
    free(myData);

   return 0;
}

void PrintData(airPdata *airport)
{
    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s %c\n",
           airport->siteNumber, airport->LocID, airport->fieldName,
           airport->city, airport->state, airport->latitude,
           airport->longitude, airport->controlTower);


}



