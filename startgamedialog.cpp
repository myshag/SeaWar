#include "startgamedialog.h"
#include "ui_startgamedialog.h"

StartGameDialog::StartGameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartGameDialog)
{
    ui->setupUi(this);
}

int StartGameDialog::getResult()
{
    if (ui->human_Vs_AI_button->isChecked())
        return HUMAN_VS_AI;
    else if (ui->human_Vs_human_button->isChecked())
        return HUMAN_VS_HUMAN;
    else if (ui->AI_Vs_AI_button->isChecked())
        return HUMAN_VS_HUMAN;
    return 0;
}

StartGameDialog::~StartGameDialog()
{
    delete ui;
}

void StartGameDialog::on_StartGameDialog_accepted()
{

}
