#ifndef DOCTORSEARCH_H
#define DOCTORSEARCH_H
#include <QVector>
#include <QDialog>
#include "doctor.h"

namespace Ui {
class DoctorSearch;
}

class DoctorSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorSearch(QWidget *parent = nullptr);
    ~DoctorSearch();
    void Show();
    QVector<Doctor*> m_Doctors1;
private slots:
    void on_pushButton_clicked();

private:
    Ui::DoctorSearch *ui;

};

#endif // DOCTORSEARCH_H
