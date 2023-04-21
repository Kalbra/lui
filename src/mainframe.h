//
// Created by kalle on 4/16/23.
//

#ifndef LUI_MAINFRAME_H
#define LUI_MAINFRAME_H

#include <QWidget>

class MainFrame : public QWidget {
Q_OBJECT

public:
    explicit MainFrame(QWidget *parent = nullptr);

    ~MainFrame() override;
};


#endif //LUI_MAINFRAME_H
