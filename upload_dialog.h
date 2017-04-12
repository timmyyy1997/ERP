#ifndef UPLOAD_DIALOG_H
#define UPLOAD_DIALOG_H

#include <QDialog>
#include <QString>
#include <QStringList>

namespace Ui {
class upload_dialog;
}

class upload_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit upload_dialog(QWidget *parent = 0);
    ~upload_dialog();
    QStringList pass_index_list();


private slots:
    void on_input_dir_button_clicked();

    void on_upload_dir_button_clicked();

    void on_Ok_button_clicked();

    void on_Cancel_button_clicked();



private:
    Ui::upload_dialog *ui;
    QString input_fileName;
    QString upload_dir;

    //private function
    void check_OK_activated();

    // flags
    bool set_input_fileName;
    bool set_upload_dir;
    QStringList list_to_pass;

};

#endif // UPLOAD_DIALOG_H
