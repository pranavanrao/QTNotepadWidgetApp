#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    connect(ui->actionOpen,
            &QAction::triggered,
            this,
            &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << "Open a file" << fileName << Qt::endl;
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QString data = file.readAll();
    this->m_textEdit->setPlainText(data);
}
