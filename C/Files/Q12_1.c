#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fPtr;
    fPtr = fopen("dict.dic", "r");
    rewind(fPtr);//文件指针复位
    int tasknum;
    scanf("%d", &tasknum);
    if(tasknum==1)
    {
        printf("Task1:\n");
        int capital = 0, lowercase = 0, digit = 0, others = 0;
        char inputch;
        inputch = fgetc(fPtr);
        while(!feof(fPtr))
        {
            if(inputch>='A'&&inputch<='Z')
                capital++;
            else if(inputch>='a'&&inputch<='z')
                lowercase++;
            else if(inputch>='0'&&inputch<='9')
                digit++;
            else
                others++;
            inputch = fgetc(fPtr);
        }
        printf("capital: %d\nlowercase: %d\ndigit: %d\nothers: %d", capital, lowercase, digit, others);
        fclose(fPtr);
        return 0;
    }
    else if(tasknum==2)
    {
        printf("Task2:\n");
        int line = 0, max, min, num = 0;
        char inputch;
        inputch = fgetc(fPtr);
        while(!feof(fPtr))
        {
            if(inputch=='\n')
                line++;
            else if(inputch!='\n')
                num++;

            if(inputch=='\n'&&line==1)
            {
                max = num;
                min = num;
                num = 0;
            }
            else if(inputch=='\n'&&line!=1)
            {
                if(num>max)
                    max = num;
                if(num<min)
                    min = num;
                num = 0;
            }
            inputch = fgetc(fPtr);
        }
        printf("line: %d\n%d characters in max line.\n%d characters in min line.", line, max, min);
        fclose(fPtr);
        return 0;
    }
    else if(tasknum==3)
    {
        printf("Task3:\n");
        int times[128] = {0};
        char inputch;
        inputch = fgetc(fPtr);
        while(!feof(fPtr))
        {
            if((inputch>='A'&&inputch<='Z')||(inputch>='a'&&inputch<='z'))
                times[inputch]++;
            inputch = fgetc(fPtr);
        }
        int k;
        printf("CAPITAL:\n");
        for (k = 'A'; k <= 'Z';k++)
            printf("%c:%d\n", k, times[k]);
        printf("LOWERCASE:\n");
        for (k = 'a'; k <= 'z';k++)
            printf("%c:%d\n", k, times[k]);
        fclose(fPtr);
        return 0;
    }
}
