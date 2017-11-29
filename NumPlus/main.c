#include <stdio.h>
#undef MAX
#define MAX 50 //最大位
char out[MAX + 1];

void setZero(char * s, int length, char c);

void inputNum(char * s);

char * plusNum(char * num1, char * num2, int length);

void reverseNum(char * s);

int countZero(char * s);

int numLen(char * s);   //to cal the length;

int main(void)
{
    char num1[MAX + 1];
    char num2[MAX + 1];
    char * result;

    //Init all of them:
    setZero(num1, MAX, '0');
    setZero(num2, MAX, '0');
    setZero(out, MAX, '0');

    //Input the num:
    inputNum(num1);
    inputNum(num2);

    //Output the result:
    printf("The result is:\n");
    result = plusNum(num1, num2, MAX);
    result += countZero(result + 1) + 1;
    puts(result);


    return 0;
}

void setZero(char * s, int length, char c)
{
    int i;
    for(i=0;i<length-1;i++)
        s[i] = c;
    s[i] = '\0';

    return;

}

void inputNum(char * s)
{
    static int id = 1;
    int i=0;
    //UI
    printf("Please input your number %d:\n", id);

    //input:
    while((s[i]=getchar()) != '\n')
        i++;

    //翻转这个数使得从个位相加
    s[i] = '\0';
    reverseNum(s);
    s[i] = '0';

    id++;
    return;

}

void reverseNum(char * s)
{
    char temp;
    int l = numLen(s);
    int i = 0;
    for(i=0;i<l/2;i++)
    {
        temp = s[l-1-i];

        s[l-1-i] = s[i];
        s[i] = temp;
    }

    return;
}

int numLen(char * s)
{
    int i = 0;
    while(*s++)
        i++;
    return i;
}

//Core Of Plus
char * plusNum(char * num1, char * num2, int length)
{


    int i, j;  //counter;
    int isot = 0; //进位判断
    int temp = 0;

    for(i=0,j=length-1;i<length;i++,j--)
    {
        temp = num1[i] + num2[i] + isot - '0';
        isot = 0;
        if(temp > '9')
        {
            isot = 1;
            temp -= 10;
        }

        //A little bug:

        out[j] = temp;

        //printf("This is %c\n", out[j]);
    }

    out[length] = '\0';

    return out;
}

int countZero(char * s)
{
    int i = 0;
    for(;s[i] == '0';i++)
        continue;

    return i;
}
