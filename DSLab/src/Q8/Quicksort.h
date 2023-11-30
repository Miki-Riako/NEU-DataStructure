#pragma once
#include "ui_Quicksort.h"
#include <QMainWindow>
#include <QApplication>
#include <QListView>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000

class Quicksort : public QMainWindow {
    Q_OBJECT
public:
    Quicksort(QWidget* parent = nullptr);
    int counter;
    bool flag[4] = {false, false, false, false};
    int target[SIZE];
    int number;
    int K;
    void loadNumber(void);
    void loadK(void);
    void findK(void);
    void loadTarget(void);
    void startSort(void);
    void sort(int *target, int front, int rear);
    ~Quicksort();
private:
    Ui_Quicksort* ui;
};
