#include "upload_dialog.h"
#include "ui_upload_dialog.h"
#include <QFileDialog>
#include <QDebug>

upload_dialog::upload_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::upload_dialog)
{
    ui->setupUi(this);
    // disable the Ok button
    ui->Ok_button->setEnabled(false);

    // set flags to check if the ok Button should be activated
    set_input_fileName = false;
    set_upload_dir = false;



}

upload_dialog::~upload_dialog()
{
    delete ui;
}

void upload_dialog::on_input_dir_button_clicked()
{
    input_fileName = QFileDialog::getOpenFileName(this,
        tr("Select Drawing"), "",tr("SWP files (*.slddrw *.sldprt *.sldasm);;Any files(*.*)"));
    ui->lineEdit_input->setText(input_fileName);
    upload_dialog::check_OK_activated();



}

void upload_dialog::on_upload_dir_button_clicked()
{
    upload_dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_upload->setText(upload_dir);
    upload_dialog::check_OK_activated();


}

void upload_dialog::on_Ok_button_clicked()
{
    // check if the data inputs are correct


    //write data into database

    //test purpose
    list_to_pass << ui->lineEdit_0->text() << ui->lineEdit_1->text()<<ui->lineEdit_2->text()
                 << ui->lineEdit_3->text() << ui->lineEdit_4->text()<<ui->lineEdit_upload->text();


    this->accept();
}

void upload_dialog::on_Cancel_button_clicked()
{
    this->reject();
}

void upload_dialog::check_OK_activated(){
    // check if the two lineEdits are empty or not
    if(ui->lineEdit_input->text().isEmpty()){
        set_input_fileName = false;
    }
    else{
        set_input_fileName = true;
    }
    if(ui->lineEdit_upload->text().isEmpty()){
        set_upload_dir = false;
    }
    else
        set_upload_dir = true;

    // if both lines are not empty
    if(set_input_fileName == true && set_upload_dir ==true){

        ui->Ok_button->setEnabled(true);
    }
    else
        ui->Ok_button->setEnabled(false);


}

QStringList upload_dialog::pass_index_list(){
    QStringList a;
    return list_to_pass;
}
