#include "patientsearch.h"
#include "ui_patientsearch.h"
#include <sstream>
PatientSearch::PatientSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientSearch)
{
    ui->setupUi(this);
}

PatientSearch::~PatientSearch()
{
    delete ui;
}

void PatientSearch::Show(){
    show();
}

void PatientSearch::on_pushButton_clicked()
{
    QVector<Patient*> patient1;
    for(int i=0; i<= m_Patients1.size()-1 ;i++){
        if((m_Patients1[i]->GetName()==ui->name->text())&&(m_Patients1[i]->GetSh()==ui->SH->text())){
            patient1.push_back(m_Patients1[i]);
        }
        else if(( (m_Patients1[i]->GetName()==ui->name->text())&&(ui->SH->text()=="")))
        {
            patient1.push_back(m_Patients1[i]);
        }
         else if(((ui->name->text()=="")&&(m_Patients1[i]->GetSh()==ui->SH->text()))){
            patient1.push_back(m_Patients1[i]);
        }
    ui->tableWidget->setRowCount(patient1.size());
    for(int i=0; i<= patient1.size()-1 ;i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(patient1[i]->GetSh()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(patient1[i]->GetName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(patient1[i]->GetGender()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(patient1[i]->GetDate()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(patient1[i]->GetDepartment()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(patient1[i]->GetDisease()));
        std::stringstream r; // doc gia tri phong
        r << patient1[i]->GetRoom();
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(r.str().c_str()));

        std::stringstream m; // doc gia tri vien phi
        m << patient1[i]->GetMoney();
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(m.str().c_str()));
    }
//    show();
    }
}

