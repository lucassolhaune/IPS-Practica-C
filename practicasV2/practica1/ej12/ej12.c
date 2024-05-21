#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isIPAddress(char *string);
bool isEmail(char *string);
bool isCreditCard(char *string);

int main() {
    char *string = (char *)malloc(100 * sizeof(char));
    printf("Ingrese su direccion IP, correo electronico o su tarjeta de credito: ");
    fgets(string, 100, stdin);

    printf("IP Address: %s", isIPAddress(string) ? "true\n" : "false\n");
    printf("Email Address: %s", isEmail(string) ? "true\n" : "false\n");
    printf("Credit Card Number: %s", isCreditCard(string) ? "true\n" : "false\n");

    return 0;
}
bool isIPAddress(char *string) {
    bool IPAddress = true;
    int numGroup, dotCounter = 0;

    if(string[0] == '.') {
        IPAddress = false;
    } else {
        for (int i = 0; i < (strlen(string) - 1); ++i) {
            if(((string[i] >= 48) && (string[i] <= 57)) || (string[i] == '.')) {
                if((string[i] == '.') && (string[i+ 1] == '.')) {
                    IPAddress = false;
                    break;
                } else {
                    if (string[i] == '.') {
                        dotCounter++;
                    }
                    if (dotCounter > 3) {
                        IPAddress = false;
                        break;
                    }
                }
            } else {
                IPAddress = false;
                break;
            }
        }
        if (dotCounter != 3) {
            IPAddress = false;
        } else {
            for(int i = 0; i < (strlen(string) - 1); ++i) {
                if(string[i] != '.') {
                    numGroup = 10 * numGroup + (string[i] - '0');
                } else {
                    numGroup = 0;
                }
                if (numGroup > 255) {
                    IPAddress = false;
                    break;
                }
            }
        }
    }

    return IPAddress;
}

bool isEmail(char *string) {
    bool email = false;
    for(int i = 0; i < (strlen(string) - 1); i++) {
        if(((string[i] >= 48) && (string[i] <= 57)) || ((string[i] >= 64 ) && (string[i] <= 90)) || ((string[i] >= 97) && (string[i] <= 122)) || (string[i] == '-') || (string[i] == '.')) {
            if(((string[i] == 64) && (string[i+1] == 64)) || ((string[i] == '.') && (string[i+1] == '.'))) {
                email = false;
                break;
            } else {
                email = true;
            }
        }
    }
    return email;
}
bool isCreditCard(char *string) {
    bool creditCard = false;
    int numCounter = 0;

    for(int i = 0; i < strlen(string); i++) {
        if(((string[i] >= 65 ) && (string[i] <= 90)) || ((string[i] >= 97) && (string[i] <= 122))) {
            creditCard = false;
            break;
        } else if(((string[i] >= 48) && (string[i] <= 57)) || (string[i] == 32)) {
            numCounter++;
        }
    }
    if((numCounter >= 13) && (numCounter <= 19)) {
        creditCard = true;
    }
    return creditCard;
}