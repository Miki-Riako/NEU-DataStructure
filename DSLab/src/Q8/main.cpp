#include "Quicksort.h"

#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Quicksort w;
    w.show();
    return a.exec();
}