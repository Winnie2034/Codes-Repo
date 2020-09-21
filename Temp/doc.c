#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char data[50], temp;
int key = 3, count;

void getmessage()
{
    printf("Enter a String: ");
    scanf("%[^\n]s", data);
}

void caesar_cipher_encryption()
{
    for (count = 0; data[count] != '\0'; count++)
    {
        temp = data[count];
        if (temp >= 'a' && temp <= 'z')
        {
            temp = temp + key;
            if (temp > 'z')
            {
                temp = temp - 'z' + 'a' - 1;
            }
            data[count] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            temp = temp + key;
            if (temp > 'Z')
            {
                temp = temp - 'Z' + 'A' - 1;
            }
            data[count] = temp;
        }
    }
    printf("\nEncrypted Message:\t%s\n", data);
    
}

void caesar_cipher_decryption()
{
    for (count = 0; data[count] != '\0'; count++)
    {
        temp = data[count];
        if (temp >= 'a' && temp <= 'z')
        {
            temp = temp - key;
            if (temp < 'a')
            {
                temp = temp + 'z' - 'a' + 1;
            }
            data[count] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            temp = temp - key;
            if (temp < 'A')
            {
                temp = temp + 'Z' - 'A' + 1;
            }
            data[count] = temp;
        }
    }
    printf("\nDecrypted Message:\t%s\n", data);
}

int main()
{
    int choice;
    getmessage();
    while (1)
    {
        printf("\n1. Encryption\n2. Decryption\n3. Exit\n");
        printf("\nEnter You Choice:\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            caesar_cipher_encryption();
            
            break;
        case 2:
            caesar_cipher_decryption();
            
            break;
        case 3:
            exit(0);
        default:
            printf("\nPlease select a correct option:\n");
        }
        
    }
    printf("\n");
    return 0;
}
