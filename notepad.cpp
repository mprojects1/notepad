#include "notepad.h"
#include "ui_notepad.h"

#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QFontDialog>
#include<QFont>
#include<QColorDialog>
#include<QColor>
#include<QPrintDialog>
#include<QPrinter>
notepad::notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->textEdit);
}

notepad::~notepad()
{

    delete ui;
}


void notepad::on_actionNew_triggered()
{

    file_name_="";

    ui->textEdit->setText("");
}

void notepad::on_actionOpen_triggered()
{

    QString file_name=QFileDialog::getOpenFileName(this,"open the file");

    QFile file(file_name);

    file_name_=file_name;

    if(!file.open(QFile::ReadOnly | QFile::Text)){
       QMessageBox::warning(this,"Warning","cannot open file");
       return;
   }
   QTextStream in(&file);
   QString text=in.readAll();
   ui->textEdit->setText(text);
   file.close();

}

void notepad::on_actionSave_triggered()
{
    if(file_name_ == "")
    {

        on_actionSave_As_triggered() ;  //calls save as if file has no prev path
        return;
     }
    QFile file(file_name_);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","cannot save file");
        return;
    }
    QTextStream out(&file);

   QString text= ui->textEdit->toPlainText();
   out<<text;
   file.flush();
    file.close();

}

void notepad::on_actionSave_As_triggered()
{
    QString filter="Text file(*.txt)";
    QString file_name=QFileDialog::getSaveFileName(this,"Save","D://",filter);
    QFile file(file_name);
    file_name_=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","cannot save file");

        return;
    }
    QTextStream out(&file);

   QString text= ui->textEdit->toPlainText();
   out<<text;
   file.flush();
    file.close();
}

void notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void notepad::on_actionAbout_triggered()
{
QString about_text;
about_text="notepad written in C++ using Qt\n";
QMessageBox::about(this,"About",about_text);

}

void notepad::on_actionFont_triggered()
{
    bool isfontselected;
    QFont font =QFontDialog::getFont(&isfontselected,this);
    if(isfontselected)
    {
        ui->textEdit->setFont(font);
    }
    else{

        return;

    }
}

void notepad::on_actioncolor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"select color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}

void notepad::on_actionchange_background_color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"select color");
    QPalette palette;  //defining qpalette cause it doent works anymore
      palette.setColor(QPalette::Base,color);
    if(color.isValid()){
        ui->textEdit->setPalette(palette);
    }

}

void notepad::on_actionprint_triggered()
{
QPrinter print;
QPrintDialog dialog(&print,this);
if (dialog.exec() == QDialog::Rejected){
        return;}
ui->textEdit->print(&print);
}
