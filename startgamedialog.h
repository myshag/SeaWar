#ifndef STARTGAMEDIALOG_H
#define STARTGAMEDIALOG_H

#include <QDialog>



namespace Ui {
class StartGameDialog;
}

class StartGameDialog : public QDialog
{
    const int HUMAN_VS_AI = 1;
    const int HUMAN_VS_HUMAN = 2;
    const int AI_VS_AI = 3;
    Q_OBJECT


public:
    explicit StartGameDialog(QWidget *parent = nullptr);
   int getResult();
    ~StartGameDialog();


private slots:
    void on_StartGameDialog_accepted();

private:
    Ui::StartGameDialog *ui;
};

#endif // STARTGAMEDIALOG_H
