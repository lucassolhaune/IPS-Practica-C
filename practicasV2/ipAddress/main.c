#include <stdio.h>
#include <stdlib.h>

typedef struct ip_Address {
    int *address;
    int *mask;
} ipAddress;

void showIPAddress(ipAddress *ip);
int main() {
    ipAddress *ip1 = (ipAddress *)malloc(sizeof(ipAddress));
    ip1->address = (int *)malloc(4 * sizeof(int));
    ip1->mask = (int *)malloc(4 * sizeof(int));

    ip1->address[0] = 192;
    ip1->address[1] = 168;
    ip1->address[2] = 5;
    ip1->address[3] = 44;
    ip1->mask[0] = 255;
    ip1->mask[1] = 255;
    ip1->mask[2] = 255;
    ip1->mask[3] = 0;

    showIPAddress(ip1);
    return 0;
}
void showIPAddress(ipAddress *ip) {
    char *red = (char *)malloc(15 * sizeof(char));
    if (ip->mask[3] == 0 && ip->mask[2] != 0 && ip->mask[1] != 0 && ip->mask[0] != 0) {
        sprintf(red, "%d.%d.%d.%d", ip->address[0], ip->address[1], ip->address[2], ip->mask[3]);
    }
    printf("IP Address: %s\n", red);
}
