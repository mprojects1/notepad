#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class notepad; }
QT_END_NAMESPACE

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionAbout_triggered();

    void on_actionFont_triggered();

    void on_actionchange_selected_font_triggered();

    void on_actionquit_triggered();

    void on_actioncolor_triggered();

    void on_actionchange_background_color_triggered();

    void on_actionprint_triggered();

private:
    Ui::notepad *ui;
    QString file_name_;
};
#endif // NOTEPAD_H
