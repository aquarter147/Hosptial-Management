#include "patientfulllist.h"
#include "ui_patientfulllist.h"
#include <QVector>
#include "patient.h"
#include <sstream>
PatientFullList::PatientFullList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientFullList)
{
    ui->setupUi(this);
}

PatientFullList::~PatientFullList()
{
    delete ui;
}

void PatientFullList::Show(QVector<Patient *> patient, int size){
    ui->tableWidget->setRowCount(size);
    for(int i=0; i<= size-1 ;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(patient[i]->GetSh()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(patient[i]->GetName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(patient[i]->GetGender()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(patient[i]->GetDate()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(patient[i]->GetDepartment()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(patient[i]->GetDisease()));
        std::stringstream r; // doc gia tri phong
        r << patient[i]->GetRoom();
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(r.str().c_str()));

        std::stringstream m; // doc gia tri vien phi
        m << patient[i]->GetMoney();
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(m.str().c_str()));
    }
    show();
}

void PatientFullList::on_pushButton_clicked()
{
    hide();
    ui->tableWidget->clearContents();
}

