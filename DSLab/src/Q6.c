#include "Q1.h"

int main(void)
{
    node *root = dataBase();
    for (bool flag = true; flag; continueProgram(&flag))
    {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        LARGE_INTEGER startTime[2], endTime[2], frequency;
        QueryPerformanceFrequency(&frequency);
        char target[MAXSIZE];
        printf("Please enter the domain name to be searched:\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        scanf(" %s", target);
        domainFlag = false;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("\nSearch by DFS:\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        QueryPerformanceCounter(&startTime[0]);
        DFS(root, target);
        QueryPerformanceCounter(&endTime[0]);
        if (!domainFlag)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("No such domain\n");
        }
        domainFlag = false;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        printf("\nSearch by BFS:\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        QueryPerformanceCounter(&startTime[1]);
        BFS(root, target);
        QueryPerformanceCounter(&endTime[1]);
        if (!domainFlag)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("No such domain\n");
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        double timeDFS = (double)(endTime[0].QuadPart - startTime[0].QuadPart) / frequency.QuadPart;
        double timeBFS = (double)(endTime[1].QuadPart - startTime[1].QuadPart) / frequency.QuadPart;
        printf("\nTime:\nDFS:%lfs\nBFS:%lfs\n", timeDFS, timeBFS);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
