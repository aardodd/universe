#include <stdio.h>
#include <stdint.h>

int
main(void)
{
    union
    {
        uint32_t value;
        uint8_t data[sizeof(uint32_t)];
    } endian = {0};

    endian.data[0] = 0x01;
    endian.data[1] = 0x02;
    endian.data[2] = 0x03;
    endian.data[3] = 0x04;

    switch (endian.value) {
        case 0x04030201: {
            printf("platform is little (0x01020304 -> 0x04030201) endian");
            break;
        }

        case 0x01020304: {
            printf("platform is big (0x01020304 -> 0x01020304) endian");
            break;
        }

        case 0x01040302: {
            printf("platform is middle little (0x01020304 -> 0x01040302) endian");
            break;
        }

        case 0x02030401: {
            printf("platform is middle big (0x01020304 -> 0x02030401) endian");
            break;
        }

        default: {
            printf("unknown endian type: %x", endian.value);
            break;
        }
    }

    return 0;
}