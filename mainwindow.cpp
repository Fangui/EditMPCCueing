#include "mainwindow.h"

#define impossibleValue -500.764
#define nbSpace 35

static const char* const arrayParameters[] =
{
    "PrePositionEnable",
    "PrePositionBlocked",
    "Kp_X",
    "Kp_Y",
    "Kp_Z",
    "GainAcc_X",
    "GainAng_Pitch",
    "GainAcc_Y",
    "GainAng_Roll",
    "GainAcc_Z",
    "GainAng_Yaw",
    "Nc_Rail_X",
    "N_Rail_X",
    "Nc_Rail_Y",
    "N_Rail_Y",
    "Nc_Hexapod_Y",
    "N_Hexapod_Y",
    "Nc_Hexapod_Z",
    "N_Hexapod_Z",
    "Hexapod_TiltAngMaxDeg_X",
    "Hexapod_TiltRateMaxDeg_X",
    "Hexapod_TiltAccMaxDeg_X",
    "Hexapod_TiltAngMaxDeg_Y",
    "Hexapod_TiltRateMaxDeg_Y",
    "Hexapod_TiltAccMaxDeg_Y",
    "Hexapod_TiltAngMaxDeg_Z",
    "Hexapod_TiltRateMaxDeg_Z",
    "Hexapod_TiltAccMaxDeg_Z",
    "RailMotionAllowed_X",
    "HexapodLinMotionAllowed_X",
    "Hexapod2DOF_Tilt_Allowed_X",
    "RailMotionAllowed_Y",
    "HexapodLinMotionAllowed_Y",
    "Hexapod2DOF_Tilt_Allowed_Y",
    "HexapodLinMotionAllowed_Z",
    "HexapodRot1DOF_PitchRate",
    "HexapodRot1DOF_RollRate",
    "HexapodRot1DOF_YawRate",
    "HexapodRot1DOF_PitchAngle",
    "HexapodRot1DOF_RollAngle",
    "T_Rail_X",
    "T_Hexapod_Lin_X",
    "T_Hexapod_Rot_X",
    "T_Rail_Y",
    "T_Hexapod_Lin_Y",
    "T_Hexapod_Rot_Y",
    "T_Hexapod_Lin_Z",
    "T_Hexapod_Rot_Z",
    "dU_As_Input_X",
    "dU_As_Input_Y",
    "dU_As_Input_Z",
    "Q_Rail_p_X",
    "Q_Rail_v_X",
    "Q_Rail_u_X",
    "Q_Rail_u_input_X",
    "Q_Rail_jk_input_X",
    "Q_Rail_u_output_X",
    "Q_Rail_jk_output_X",
    "Q_Hexapod_p_X",
    "Q_Hexapod_v_X",
    "Q_Hexapod_u_X",
    "Q_Hexapod_u_input_X",
    "Q_Hexapod_jk_input_X",
    "Q_Hexapod_u_output_X",
    "Q_Hexapod_jk_output_X",
    "Q_Hexapod_q_Tilt_X",
    "Q_Hexapod_qp_Tilt_X",
    "Q_Hexapod_qp2_Tilt_X",
    "Q_Hexapod_qp2_input_Tilt_X",
    "Q_Hexapod_qp3_input_Tilt_X",
    "Q_Hexapod_qp_output_Tilt_X",
    "Q_Hexapod_qp2_output_Tilt_X",
    "Q_Rail_p_Y",
    "Q_Rail_v_Y",
    "Q_Rail_u_Y",
    "Q_Rail_u_input_Y",
    "Q_Rail_jk_input_Y",
    "Q_Rail_u_output_Y",
    "Q_Rail_jk_output_Y",
    "Q_Hexapod_p_Y",
    "Q_Hexapod_v_Y",
    "Q_Hexapod_u_Y",
    "Q_Hexapod_u_input_Y",
    "Q_Hexapod_jk_input_Y",
    "Q_Hexapod_u_output_Y",
    "Q_Hexapod_jk_output_Y",
    "Q_Hexapod_q_Tilt_Y",
    "Q_Hexapod_qp_Tilt_Y",
    "Q_Hexapod_qp2_Tilt_Y",
    "Q_Hexapod_qp2_input_Tilt_Y",
    "Q_Hexapod_qp3_input_Tilt_Y",
    "Q_Hexapod_qp_output_Tilt_Y",
    "Q_Hexapod_qp2_output_Tilt_Y",
    "Q_Hexapod_q_Tilt_Z",
    "Q_Hexapod_qp_Tilt_Z",
    "Q_Hexapod_qp2_Tilt_Z",
    "Q_Hexapod_qp2_input_Tilt_Z",
    "Q_Hexapod_qp3_input_Tilt_Z",
    "Q_Hexapod_q_output_Tilt_Z",
    "Q_Hexapod_qp_output_Tilt_Z",
    "Q_Hexapod_p_Z",
    "Q_Hexapod_v_Z",
    "Q_Hexapod_u_Z",
    "Q_Hexapod_u_input_Z",
    "Q_Hexapod_jk_input_Z",
    "Q_Hexapod_u_output_Z",
    "Q_Hexapod_jk_output_Z",
    "WithVestibularModel",
    "WithRecordingSignal_X"
};

static const unsigned short nbParameters = sizeof(arrayParameters) / sizeof(char *);        // the size of the array

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

MainWindow::~MainWindow()
{}

void changeOtherCheck(QCheckBox *checkBox1, QCheckBox *checkBox2, QGroupBox *GroupBox)  //Disable the other button and Enable/disable the GroupBox
{
    if(checkBox1->isChecked())
    {
        checkBox2->setChecked(false);
        GroupBox->setEnabled(true);
    }
    else
    {
        if(!checkBox2->isChecked())
            GroupBox->setEnabled(false);
    }
}

void MainWindow::on_Hexapod2DOF_Tilt_Allowed_X_clicked()
{
    changeOtherCheck(ui.Hexapod2DOF_Tilt_Allowed_X, ui.HexapodRot1DOF_PitchRate, ui.TiltBoxX);
}

void MainWindow::on_HexapodRot1DOF_PitchRate_clicked()
{
    changeOtherCheck(ui.HexapodRot1DOF_PitchRate, ui.Hexapod2DOF_Tilt_Allowed_X, ui.TiltBoxX);
}

void MainWindow::on_Hexapod2DOF_Tilt_Allowed_Y_clicked()
{
    changeOtherCheck(ui.Hexapod2DOF_Tilt_Allowed_Y, ui.HexapodRot1DOF_RollRate, ui.TiltBoxY);
}

void MainWindow::on_HexapodRot1DOF_RollRate_clicked()
{
    changeOtherCheck(ui.HexapodRot1DOF_RollRate, ui.Hexapod2DOF_Tilt_Allowed_Y, ui.TiltBoxY);
}

void MainWindow::on_openFileButton_clicked() //Read the file and load the value in the IHM
{
    QString filename = ui.path->toPlainText();          //get the path if there is one
    if(filename == "")
    {
        filename = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                "C://",
                                                "All files (*.*);; Configuration File (*.cfg);; TextFile (*.txt)");
    }
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
        return;
    }

    bool b;
    QHash<QString, double> hashtab;
    QString line;
    QString str;
    QString value;
    QTextStream in(&file);
    unsigned int i;
    unsigned int size;

    for(unsigned short k = 0; k < nbParameters; ++k)        //Insert all the element insert in the vector on the hashtable
        hashtab.insert(arrayParameters[k], impossibleValue);

    while(!in.atEnd() )
    {
        b = true;
        i = 0;
        str = "";                       //str will be the first world on the line
        value = "";                     // value will be the value after str
        line = in.readLine();
        size = line.capacity();

        while(i < size && b)            // Stop until the end of the line or the end of the first world
        {
            if(line[i] != ' ')          // Add char to str until there is no ' '
                str += line[i];
            else
            {
                while (i < size && line[i] == ' ')  // we found a ' ' increment the index i until there is no ' '
                    ++i;
                b = false;
                --i;
            }
            ++i;
        }

        if(hashtab.contains(str))               //if the first world is in the hashtable then it is a parameter the next element is his value
        {
            while(i < size && line[i] >= '0' && line[i] <= '9' || line[i] == '.' || line[i] == 'e')  // get the value
            {
                value += line[i];
                ++i;
            }
            hashtab[str] = value.toDouble();                    // convert it to Double + set value
        }
    }
    QDoubleSpinBox *doubleBox;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QSpinBox *spinBox;

    for(unsigned short k = 0; k < nbParameters; ++k)
    {
        if(hashtab[arrayParameters[k]] != impossibleValue)         // if the value has been modified
        {
           doubleBox = ui.centralWidget->findChild<QDoubleSpinBox*>(arrayParameters[k]); //look in the IHM if there is a QDoubleSpinBox with the parameter name
           if(doubleBox)                                                                 // it is the case so we set the value
               doubleBox->setValue(hashtab[arrayParameters[k]]);
           else
           {
               spinBox = ui.centralWidget->findChild<QSpinBox*>(arrayParameters[k]);   //it is not the case so we look for spinBox this time
                if(spinBox)
                    spinBox->setValue(hashtab[arrayParameters[k]]);
                else                                                                   //Repeat until we find the box
                {
                    checkBox = ui.centralWidget->findChild<QCheckBox*>(arrayParameters[k]);
                    if(checkBox)
                        checkBox->setChecked(hashtab[arrayParameters[k]]);
                    else
                    {
                        groupBox = ui.centralWidget->findChild<QGroupBox*>(arrayParameters[k]);
                        if(groupBox)
                            groupBox->setChecked(hashtab[arrayParameters[k]]);
                        else
                            QMessageBox::information(0, "Not find in the UI", arrayParameters[k]);  // We haven't found it can't set the value
                    }
                }
           }
        }
        else
            QMessageBox::information(0, "Missing argument in " + filename, arrayParameters[k]);    //the parameter is not on the file
    }
    file.close();
}

void MainWindow::on_Cancel_clicked()
{
    this->close();
}

void MainWindow::on_Apply_clicked()         //Writting function
{
    QString filename = ui.path->toPlainText();
    if(filename == "")
    {
        filename = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                "C://",
                                                "All files (*.*);; Configuration File (*.cfg);; TextFile (*.txt)");
    }

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "info", file.errorString());
        return;
    }
    bool b;
    QHash<QString, double> hashtab;
    QCheckBox *checkBox;
    QDoubleSpinBox *doubleBox;
    QGroupBox *groupBox;
    QSpinBox *spinBox;
    QString s;
    QString str;
    QString value;
    QVector<QString> vectNewParameters;            //vector which will contain the writting of the new file
    QTextStream in(&file);
    unsigned short capacity = 0;
    unsigned short i;
    unsigned short size;

    for(unsigned short k = 0; k < nbParameters; ++k)
    {
        doubleBox = ui.centralWidget->findChild<QDoubleSpinBox*>(arrayParameters[k]);          //Push in the hashtable all the parameters and their values
        if(doubleBox)
            hashtab.insert(arrayParameters[k], doubleBox->value());
        else
        {
            spinBox = ui.centralWidget->findChild<QSpinBox*>(arrayParameters[k]);
            if(spinBox)
                hashtab.insert(arrayParameters[k], spinBox->value());
            else
            {
                checkBox = ui.centralWidget->findChild<QCheckBox*>(arrayParameters[k]);
                if(checkBox)
                    hashtab.insert(arrayParameters[k], checkBox->isChecked());
                else
                {
                    groupBox = ui.centralWidget->findChild<QGroupBox*>(arrayParameters[k]);
                    if(groupBox)
                        hashtab.insert(arrayParameters[k], groupBox->isChecked());
                    else
                        QMessageBox::information(0, "Not find in the GUI", arrayParameters[k]); //Missing parameters in the IHM
                }
            }
        }
    }

    while(!in.atEnd() )         //Read the file until the first world is a parameter (usefull to keep the header of the file)
    {
        b = true;
        str = "";
        s = in.readLine();
        size = s.size();

        for(i = 0; i < size && b; ++i)
        {
            if(s[i] != ' ')
                str += s[i];
            else
                b = false;
        }
        if(hashtab.contains(str))
            break;
        else if(size)
        {
           ++capacity;
            vectNewParameters.push_back(s);
        }
    }
    for(i = 0; i < nbParameters; ++i)       //Write all the parameter
    {
        str = "";
        str += arrayParameters[i];
        size = str.size();
        for(unsigned short j = 0; j < nbSpace - size; ++j)      //choose how many spaces we need (to align them in the txt file)
            str += ' ';
        value = QString::number(hashtab[arrayParameters[i]]);
        size = value.size();
        if(value.contains("+"))                     //if the value contains a + it has the form 1e+07 but we want to change in 1e7
        {
            for(unsigned short cpt = 0; cpt < size; ++cpt)
            {
                s = "";
                if(value[cpt] != '+')
                    str += value[cpt];
                else
                {
                    if(value[cpt + 1] == '0')
                        ++cpt;
                }
            }
        }
        else
            str += value;
        vectNewParameters.push_back(str);
    }
    file.close();

    if(!file.open( QIODevice::WriteOnly ) )
    {
        QMessageBox::information(0, "Fail", "Error while writting in " + filename);
        return;
    }
    QTextStream text(&file);

    for(i = 0; i < capacity + nbParameters - 1; ++i)        //Writting in text
        text << vectNewParameters.at(i) << endl;
    text << vectNewParameters.at(i) << "\0";                //We don't want a \n for the last char

    file.close();
}

void MainWindow::on_OK_clicked()
{
    on_Apply_clicked();
    this->close();
}

void MainWindow::on_PathButton_clicked()  // Change the file of parameters
{
    QString filename = QFileDialog::getOpenFileName(0,
                                                    "Open File",
                                                    "C://",
                                                    "All files (*.*);; Configuration File (*.cfg);; TextFile (*.txt)");
    ui.path->setText(filename);
}
