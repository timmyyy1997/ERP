#include "upload_dir_dialog.h"
#include "ui_upload_dir_dialog.h"

upload_dir_dialog::upload_dir_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::upload_dir_dialog)
{
    ui->setupUi(this);
}

upload_dir_dialog::~upload_dir_dialog()
{
    delete ui;
}
