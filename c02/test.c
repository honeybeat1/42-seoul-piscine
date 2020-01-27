#include <stdio.h>
#include <string.h>

int     main(void)
{
    char origin[] = "thisisnotadrill";
    char dest_empty[] = {}; //abort 복사될 공간이 읎음
    char dest_full[] = "thisisalreadyfull";//success
    char dest_emptybutlarge[20];//success
    char dest_small[10];//abort 복사될 공간 무 strcpy

    //strcpy(dest_empty, origin);
    //strcpy(dest_full, origin);
    //strcpy(dest_emptybutlarge, origin);
    strcpy(dest_small, origin);

    //printf("dest 0으로 비어있을 경우 : %s\n",dest_empty);
    //printf("dest 20글자로 차 있을 경우 : %s\n", dest_full);
    //printf("dest 크기 큼 20: %s\n", dest_emptybutlarge);
    printf("dest 크기 작음 10: %s\n", dest_small);
    return (0);
}
