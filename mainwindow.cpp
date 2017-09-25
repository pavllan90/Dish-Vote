#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count = 0;
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addDish()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(func()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDish()
{
    QString fname = ui->lineEdit_2->text()+ui->lineEdit_3->text()+ui->lineEdit_4->text();
    bool f = true;
    for(int i = 0; i<count&&f; i++)
    {
        if(QString::compare(fname, (mass[i]->fio.surname+mass[i]->fio.name+mass[i]->fio.otc))==0)
        {
            ui->textEdit->append("Voice changed:\n User #"+ QString::number(i+1)+"\nFrom "+mass[i]->dish+" to " +ui->lineEdit->text());
            mass[i]->dish=ui->lineEdit->text();
            f = false;
        }
    }
    if(f)
    {
        mass[count] = new Blank(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text(), ui->lineEdit_5->text(), ui->lineEdit_6->text());
        ui->textEdit->append("User #"+QString::number(count+1)+"\nDish: "+mass[count]->dish+"\nName: "+mass[count]->fio.name+ "\nSurname: "+mass[count]->fio.surname+"\nSecond Name: "+mass[count]->fio.otc+"\nNumber: "+mass[count]->number+"\nE-mail:  "+mass[count]->email+"\n--------------"  );
        count+=1;
    }
}

struct dict
{
    QString dish;
    int counter;
};

void MainWindow::func()
{
    dict *a[count];
    bool f = false;
    a[0] = new dict;
    a[0]->dish=mass[0]->dish;
    a[0]->counter = 1;
    int r = 1;
    for(int i = 1; i<count; i++)
    {
        for(int j = 0; j<r&&!f; j++)
        {
            if(mass[i]->dish==a[j]->dish) f=true, a[j]->counter+=1;
        }
        if(!f) a[r]=new dict, a[r]->dish=mass[i]->dish, a[r]->counter=1,r+=1;
        f=false;
    }
    int max=0;
    for(int j = 0; j<r; j++)
    {
        if(max<a[j]->counter) max=a[j]->counter;
    }
    QString winners[count];
    int cc=0;
    for(int j = 0; j<r; j++)
    {
        if(max==a[j]->counter) winners[cc]=a[j]->dish, cc+=1;
    }
    for(int i =0; i<cc; i++)
    ui->textEdit->append("Winner #"+QString::number(i+1)+"\n"+winners[i]);
    ui->textEdit->append("\nSend messages to: \n");
    for(int i =0; i<count; i++)
    {
        for(int j = 0; j<cc; j++)
        {
            if(winners[j]==mass[i]->dish)
                if(mass[i]->number=="") ui->textEdit->append("\nName: "+mass[i]->fio.name+"\nE-mal: "+mass[i]->email);
                else ui->textEdit->append("\nName: "+mass[i]->fio.name+"\nNumber: "+mass[i]->number);
        }
    }

}
