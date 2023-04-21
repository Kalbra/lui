//
// Created by kalle on 4/16/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainFrame.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    Connector connector;

    fileio = new ProjectFileIO("project1.json", output_blocks);

    connect(ui->action_new_block, &QAction::triggered, this, &MainWindow::newBlock);
    connect(ui->action_save, &QAction::triggered, this, &MainWindow::Save);
    mainframe = new MainFrame(ui->mainframe);

    new_block_window = new NewBlock(mainframe, &connector, output_blocks);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::newBlock() {
    new_block_window->show();
}

void MainWindow::Save() {
    fileio->save();
}
