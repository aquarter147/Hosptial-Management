#ifndef PATIENTDIALOG_H
#define PATIENTDIALOG_H

#include <QDialog>
#include "patient.h"
namespace Ui {
class PatientDialog;
}

class PatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PatientDialog(QWidget *parent = nullptr);
    ~PatientDialog();
    void Show(Patient* patient);

private slots:
    void on_Ok_btn_released();

    void on_Cancel_btn_clicked();

private:
    Ui::PatientDialog *ui;
    Patient* m_Patient;
};

#endif // PATIENTDIALOG_H
