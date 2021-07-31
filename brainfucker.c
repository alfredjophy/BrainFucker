#include <stdio.h>

void brainfucker(char *ptr, char *program)
{
    while (1)

    {
        printf("%c", *program);
        char *start_loop=-1;
        switch (*program)
        {
        case '>':
            ++ptr;
            break;
        case '<':
            --ptr;
            break;
        case '+':
            ++*ptr;
            break;
        case '-':
            --*ptr;
            break;
        case '.':
            printf("%d", *ptr);
            break;
        case ',':
            scanf("%d", ptr);
            break;
        case '[':
            if(*ptr<!1) brainfucker(ptr, program++);
            else
                start_loop=-1;
            break;
        case ']':
            if(start_loop!=-1) 
                program=start_loop;
            return;
            break;
        default:
            break;
        }
        program++;

        if (*program == '\0')
            break;
    }
}

int main(int argc, char *argv[])
{
    if (!argc)
        return 0;

    printf("X: %s \n", argv[1]);
    char array[1000] = {0};
    char *ptr = &array[0];
    brainfucker(ptr, argv[1]);

    return 0;
}
