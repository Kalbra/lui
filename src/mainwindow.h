//
// Created by kalle on 4/16/23.
//

#ifndef LUI_MAINWINDOW_H
#define LUI_MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QDebug>
#include <QAction>

#include "mainframe.h"
#include "newblock.h"

#include "ProjectFileIO.h"

#include "./Blocks/BaseOutputBlock.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct ProjectSettings {};


class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QWidget *mainframe;

    ProjectFileIO *fileio;
    NewBlock *new_block_window;

    std::vector<BaseOutputBlock*> *output_blocks = new std::vector<BaseOutputBlock*>;

private slots:
    void newBlock();
    void Save();
};


#endif //LUI_MAINWINDOW_H
