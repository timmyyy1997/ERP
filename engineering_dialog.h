#ifndef ENGINEERING_DIALOG_H
#define ENGINEERING_DIALOG_H

#include <QDialog>
#include <QStringList>
#include "upload_dialog.h"

namespace Ui {
class engineering_dialog;
}

class engineering_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit engineering_dialog(QWidget *parent = 0);
    ~engineering_dialog();


private slots:
    void on_upload_button_clicked();
    void pass_the_index_list();

private:
    Ui::engineering_dialog *ui;
    QStringList index_list;
    upload_dialog *up_dialog = new upload_dialog;

};

#endif // ENGINEERING_DIALOG_H
