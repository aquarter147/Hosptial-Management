#include "doctordialog.h"
#include "ui_doctordialog.h"
#include "doctor.h"
DoctorDialog::DoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorDialog)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromUtf8("Thông tin bác sĩ"));
}

void DoctorDialog::Show(Doctor* doctor){

    ui->name->setText(doctor->GetName());
    ui->DOB->setText(doctor->GetDate());
    ui->Gender->setText(doctor->GetGender());
    ui->Department->setText(doctor->GetDepartment());
    ui->Specialist->setText(doctor->GetSpecialist());
    ui->SH->setText(doctor->GetSh());
    ui->Shift->setText(doctor->GetShift());
    m_Doctor=doctor;
    show();

}
DoctorDialog::~DoctorDialog()
{
    delete ui;
}

void DoctorDialog::on_Ok_btn_released()
{
    m_Doctor->SetName(ui->name->text());
    m_Doctor->SetDate(ui->DOB->text());
    m_Doctor->SetGender(ui->Gender->text());
    m_Doctor->SetDepartment(ui->Department->text());
    m_Doctor->SetSpecialist(ui->Specialist->text());
    m_Doctor->SetSh(ui->SH->text());
    m_Doctor->SetShift(ui->Shift->text());
    hide();
}




void DoctorDialog::on_Cancel_btn_clicked()
{
    hide();
}

