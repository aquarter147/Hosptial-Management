#include "patientdialog.h"
#include "ui_patientdialog.h"
#include "patient.h"
#include <sstream>
#include <string>
#include <string.h>
PatientDialog::PatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientDialog)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("Thông tin bệnh nhân"));
}

void PatientDialog::Show(Patient* patient){

    ui->name->setText(patient->GetName());
    ui->DOB->setText(patient->GetDate());
    ui->Gender->setText(patient->GetGender());
    ui->Department->setText(patient->GetDepartment());
    ui->Disease->setText(patient->GetDisease());
    ui->SH->setText(patient->GetSh());

    std::stringstream sstream;
    sstream << patient->GetRoom();
    ui->Room->setText(sstream.str().c_str());


    std::stringstream sstream2;
    sstream2<<patient->GetMoney();
    ui->Money->setText(sstream2.str().c_str());
    m_Patient=patient;
    show();

}
PatientDialog::~PatientDialog()
{
    delete ui;
}

void PatientDialog::on_Ok_btn_released()
{
    m_Patient->SetName(ui->name->text());
    m_Patient->SetDate(ui->DOB->text());
    m_Patient->SetGender(ui->Gender->text());
    m_Patient->SetDisease(ui->Disease->text());
    m_Patient->SetDepartment(ui->Department->text());
    m_Patient->SetSh(ui->SH->text());


    int val;
    std::string str1=ui->Room->text().toStdString();
    const char* p = str1.c_str();
    val = atoi(p);
    m_Patient->SetRoom(val);


    long long val_2;
    std::string str_2=ui->Money->text().toStdString();
    const char* p_1 = str_2.c_str();
    val_2 = atoll(p_1);
    m_Patient->SetMoney(val_2);
    hide();
}



void PatientDialog::on_Cancel_btn_clicked()
{
    hide();
}
