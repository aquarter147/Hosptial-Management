#ifndef DOCTORDIALOG_H
#define DOCTORDIALOG_H

#include <QDialog>
#include "doctor.h"
namespace Ui {
class DoctorDialog;
}

class DoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorDialog(QWidget *parent = nullptr);
    ~DoctorDialog();
    void Show(Doctor* doctor);

private slots:
    void on_Ok_btn_released();

    void on_Cancel_btn_clicked();

private:
    Ui::DoctorDialog *ui;
    Doctor* m_Doctor;

};

#endif // DOCTORDIALOG_H
