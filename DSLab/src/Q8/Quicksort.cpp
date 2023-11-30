#include "Quicksort.h"

Quicksort::Quicksort(QWidget *parent)
    : QMainWindow(parent), ui(new Ui_Quicksort)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->showEdit->setReadOnly(true);
    connect(ui->pushButton,   &QPushButton::clicked, this, &Quicksort::loadNumber);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &Quicksort::loadK);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &Quicksort::loadTarget);
    connect(ui->startButton,  &QPushButton::clicked, this, &Quicksort::startSort);
    connect(ui->sortButton,   &QPushButton::clicked, this, &Quicksort::findK);
}

Quicksort::~Quicksort()
{
    delete ui;
}

void Quicksort::loadNumber()
{
    number = ui->lineEdit->text().toInt();
    if (number > 0)
    {
        QMessageBox::information(this, "Success", "Number Loaded!");
        flag[0] = true;
        counter = 0;
    }
    else
        QMessageBox::warning(this, "Warning", "Number must be greater than 0!");
}

void Quicksort::loadK()
{
    K = ui->lineEdit_2->text().toInt();
    if (K > 0 && K < number)
    {
        QMessageBox::information(this, "Success", "K Loaded!");
        flag[1] = true;
    }
    else
        QMessageBox::warning(this, "Warning", "K must be greater than 0 and less than the number!");
}

void Quicksort::findK()
{
    if (flag[0] && flag[1] && flag[2] && flag[3])
    {
        ui->showEdit->setText("");
        string print = "";
        for (int i = 0; i < number; i++)
            print += to_string(target[i]) + ' ';
        ui->showEdit->setText(QString::fromStdString(print));
        string found = "The Kth smallest number is: " + to_string(target[K - 1]);
        QMessageBox::information(this, "Success", QString::fromStdString(found));
    }
    else
        QMessageBox::warning(this, "Warning", "Please load all the information!");
}

void Quicksort::loadTarget()
{
    if (flag[0] && flag[1])
    {
        target[counter++] = ui->lineEdit_3->text().toInt();
        if (counter == number)
        {
            QMessageBox::information(this, "Success", "Target Loaded!");
            flag[2] = true;
        }
        else if (counter > number)
            QMessageBox::warning(this, "Warning", "Numbers already exits!");
    }
    else
        QMessageBox::warning(this, "Warning", "Please load number and k first!");
}

void Quicksort::sort(int *target, int front, int rear)
{
    if (front < rear)
    {
        int temp;
        int pivot = front;
        int first = front;
        int last = rear;
        while (first < last)
        {
            while (target[first] <= target[pivot] && first < rear)
                first++;
            while (target[last] > target[pivot])
                last--;
            if (first < last)
            {
                temp = target[first];
                target[first] = target[last];
                target[last] = temp;
            }
        }
        temp = target[pivot];
        target[pivot] = target[last];
        target[last] = temp;
        sort(target, front, last - 1);
        sort(target, last + 1, rear);
    }
}

void Quicksort::startSort()
{
    if (flag[0] && flag[1] && flag[2])
    {
        ui->showEdit->setText("");
        string print = "";
        for (int i = 0; i < number; i++)
            print += to_string(target[i]) + ' ';
        ui->showEdit->setText(QString::fromStdString(print));
        flag[3] = true;
        sort(target, 0, number - 1);
    }
    else
        QMessageBox::warning(this, "Warning", "Pleas load target first!");
}
