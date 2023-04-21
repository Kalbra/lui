//
// Created by kalle on 4/20/23.
//

#ifndef LUI_NEWBLOCK_H
#define LUI_NEWBLOCK_H

#include <QWidget>

#include "./Blocks/Connector.hpp"
#include "./Blocks/BaseOutputBlock.hpp"
#include "./Blocks/LcdNumberOutputBlock.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class NewBlock; }
QT_END_NAMESPACE

class NewBlock : public QWidget {
Q_OBJECT

public:
    NewBlock(QWidget *mainframe,
             Connector *connector,
             std::vector<BaseOutputBlock*> *output_blocks,
             QWidget *parent = nullptr
             );

    ~NewBlock() override;

private:
    Ui::NewBlock *ui;
    QWidget *_mainframe;
    Connector *_connector;
    std::vector<BaseOutputBlock*> *_output_blocks;
    void lookup_correct_block(const QString& block_name);


private slots:
    void create_block();
};


#endif //LUI_NEWBLOCK_H
