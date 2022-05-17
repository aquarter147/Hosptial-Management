#include "doctorsearch.h"
#include "ui_doctorsearch.h"
#include <QVector>
#include "doctor.h"
DoctorSearch::DoctorSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorSearch)
{
    ui->setupUi(this);
}


void DoctorSearch::Show(){
    show();
}

DoctorSearch::~DoctorSearch()
{
    delete ui;
}

void DoctorSearch::on_pushButton_clicked()
{
    QVector<Doctor*> doctor1;
    for(int i=0; i<= m_Doctors1.size()-1 ;i++){
        if((m_Doctors1[i]->GetName()==ui->name->text())&&(m_Doctors1[i]->GetSh()==ui->SH->text())){
            doctor1.push_back(m_Doctors1[i]);
        }
        else if(( (m_Doctors1[i]->GetName()==ui->name->text())&&(ui->SH->text()=="")))
        {
            doctor1.push_back(m_Doctors1[i]);
        }
         else if(((ui->name->text()=="")&&(m_Doctors1[i]->GetSh()==ui->SH->text()))){
            doctor1.push_back(m_Doctors1[i]);
        }
    ui->tableWidget->setRowCount(doctor1.size());
    for(int i=0; i<= doctor1.size()-1 ;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(doctor1[i]->GetSh()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(doctor1[i]->GetName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(doctor1[i]->GetGender()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(doctor1[i]->GetDate()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(doctor1[i]->GetDepartment()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(doctor1[i]->GetSpecialist()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(doctor1[i]->GetShift()));
    }
//    show();
    }
}
