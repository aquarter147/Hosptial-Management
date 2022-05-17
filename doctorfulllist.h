#ifndef DOCTORFULLLIST_H
#define DOCTORFULLLIST_H

#include <QWidget>
#include <QVector>
#include <doctor.h>
namespace Ui {
class DoctorFullList;
}

class DoctorFullList : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorFullList(QWidget *parent = nullptr);
    ~DoctorFullList();
    void Show(QVector<Doctor*> doctor, int size);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DoctorFullList *ui;
};

#endif // DOCTORFULLLIST_H
