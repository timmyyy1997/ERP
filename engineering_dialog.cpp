#include "engineering_dialog.h"
#include "ui_engineering_dialog.h"
#include <QDebug>


engineering_dialog::engineering_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::engineering_dialog)
{
    ui->setupUi(this);

    // set up basic workflow viewer
    int workflow_rowcount = 15;
    int workflow_columncount = 8;
    ui->tableWidget_workflow->setRowCount(workflow_rowcount);
    ui->tableWidget_workflow->setColumnCount(workflow_columncount);
    QStringList horizontal_labels;
    horizontal_labels.append("A");
    horizontal_labels.append("B");
    horizontal_labels.append("C");
    horizontal_labels.append("D");
    horizontal_labels.append("E");
    horizontal_labels.append("F");
    ui->tableWidget_workflow->setHorizontalHeaderLabels(horizontal_labels);
    ui->tableWidget_workflow->setColumnWidth(0,50);
    ui->tableWidget_workflow->verticalHeader()->hide();
    for(int i = 0; i<workflow_rowcount; i++){
        ui->tableWidget_workflow->setRowHeight(i,25);
    }
    ui->tableWidget_workflow->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_workflow->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set up the other viewer
    int second_chart_rowcount = 15;
    int second_chart_columncount = 8;
    ui->tableWidget_2->setRowCount(second_chart_rowcount);
    ui->tableWidget_2->setColumnCount(second_chart_columncount);
    QStringList horizontal_labels_2;
    horizontal_labels_2.append("ID");
    horizontal_labels_2.append("Part Name");
    horizontal_labels_2.append("Part Number");
    horizontal_labels_2.append("SN");
    horizontal_labels_2.append("Assembly ID");
    horizontal_labels_2.append("Other");
    ui->tableWidget_2->setHorizontalHeaderLabels(horizontal_labels_2);
    ui->tableWidget_2->setColumnWidth(0,50);
    ui->tableWidget_2->verticalHeader()->hide();
    for(int i = 0; i<second_chart_rowcount; i++){
        ui->tableWidget_2->setRowHeight(i,25);
    }
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // set up the thid_viewer
    int third_chart_rowcount = 10;
    int third_chart_columncount = 15;
    ui->tableWidget_3->setRowCount(third_chart_rowcount);
    ui->tableWidget_3->setColumnCount(third_chart_columncount);
    QStringList horizontal_labels_3;
    horizontal_labels_3.append("ID");
    horizontal_labels_3.append("Part Name");
    horizontal_labels_3.append("Part Number");
    horizontal_labels_3.append("SN");
    horizontal_labels_3.append("Assembly ID");
    horizontal_labels_3.append("Server Dir");
    horizontal_labels_3.append("Index 7");
    horizontal_labels_3.append("Index 8");
    horizontal_labels_3.append("Index 9");
    horizontal_labels_3.append("Index 10");

    ui->tableWidget_3->setHorizontalHeaderLabels(horizontal_labels_3);
    ui->tableWidget_3->setColumnWidth(0,50);
    ui->tableWidget_3->verticalHeader()->hide();
    for(int i = 0; i<second_chart_rowcount; i++){
        ui->tableWidget_3->setRowHeight(i,20);
    }
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);



    connect(up_dialog,SIGNAL(accepted()),this,SLOT(pass_the_index_list()));



}

engineering_dialog::~engineering_dialog()
{
    delete ui;
}

void engineering_dialog::on_upload_button_clicked()
{
    //upload_dialog new_dialog;
    //new_dialog.show();

    up_dialog->exec();



}

void engineering_dialog::pass_the_index_list(){
    qDebug() << "Entering pass the index list in main.";
    QStringList a = up_dialog->pass_index_list();
    for (int i = 0; i<a.count();i++){
        QTableWidgetItem *mitem = new QTableWidgetItem;
        mitem->setText(a.at(i));
        ui->tableWidget_3->setItem(0,i,mitem);
    }
}
