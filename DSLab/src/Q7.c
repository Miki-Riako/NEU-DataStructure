#include "Q2.h"

int main(void)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    char input[MAXSIZE - 1];
    int s = 0, e, i;
    double result;
    char exitJudge = 0;
    do
    {
        printf("Please enter an expression：");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        scanf("%s", &input);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        e = strlen(input);
        for (i = 0; i < e; i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
                continue;
            else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')
                continue;
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("ERROR!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                exitJudge = 1;
                break;
            }
        }
        if (exitJudge == 1)
        {
            exitJudge = 0;
            system("pause");
            system("cls");
            continue;
        }
        result = cal(afaToBtree(input, s, e));
        printf("The result is ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        printf("%.2lf\n", result);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printf("Press enter to continue, or enter anything to quit.\n");
        fflush(stdin);
        exitJudge = _getch();
        if (exitJudge != 13)
            break;
        else
            system("cls");
    } while (1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
