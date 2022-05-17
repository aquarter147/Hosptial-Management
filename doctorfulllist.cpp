#include "doctorfulllist.h"
#include "ui_doctorfulllist.h"

DoctorFullList::DoctorFullList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorFullList)
{
    ui->setupUi(this);
}

DoctorFullList::~DoctorFullList()
{
    delete ui;
}

void DoctorFullList::Show(QVector<Doctor *> doctor, int size){
    ui->tableWidget->setRowCount(size);
    for(int i=0; i<= size-1 ;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(doctor[i]->GetSh()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(doctor[i]->GetName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(doctor[i]->GetGender()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(doctor[i]->GetDate()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(doctor[i]->GetDepartment()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(doctor[i]->GetSpecialist()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(doctor[i]->GetShift()));
    }
    show();
}

void DoctorFullList::on_pushButton_clicked()
{
    hide();
    ui->tableWidget->clearContents();
}

