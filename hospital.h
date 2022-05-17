#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <QMainWindow>
#include "doctorlist.h"
#include "patientlist.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Hospital; }
QT_END_NAMESPACE

class Hospital : public QMainWindow
{
    Q_OBJECT

public:
    Hospital(QWidget *parent = nullptr);
    ~Hospital();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_clicked();

private:
    Ui::Hospital *ui;
    DoctorList* m_DoctorList;
    PatientList* m_PatientList;
};
#endif // HOSPITAL_H
