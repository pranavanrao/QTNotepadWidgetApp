#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->statusBar()->showMessage("Go to hell");

    this->m_bar = this->menuBar();
    QMenu *tools = new QMenu("Tools");
    m_bar->addMenu(tools);

    QAction *act = new QAction("C++",this);
    tools->addAction(act);

    this->m_textEdit = new QTextEdit;
    this->setCentralWidget(m_textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
