#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QHash>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);

    virtual ~MainWindow();


private slots:

    void on_Hexapod2DOF_Tilt_Allowed_X_clicked();

    void on_HexapodRot1DOF_PitchRate_clicked();

    void on_Hexapod2DOF_Tilt_Allowed_Y_clicked();

    void on_HexapodRot1DOF_RollRate_clicked();

    void on_openFileButton_clicked();

    void on_Cancel_clicked();

    void on_Apply_clicked();

    void on_OK_clicked();

    void on_PathButton_clicked();

private:
    Ui::MainWindow ui;
};

#endif // MAINWINDOW_H
