//
// Created by kalle on 4/20/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewBlock.h" resolved

#include "newblock.h"
#include "ui_newblock.h"


NewBlock::NewBlock(QWidget *mainframe, Connector *connector, std::vector<BaseOutputBlock*> *output_blocks, QWidget *parent) :
        QWidget(parent), ui(new Ui::NewBlock) {
    ui->setupUi(this);

    _mainframe = mainframe;
    _connector = connector;
    _output_blocks = output_blocks;

    ui->blocklist->addItems({
        "LcdNumberOutput"
    });

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &NewBlock::create_block);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &NewBlock::close);
}

NewBlock::~NewBlock() {
    delete ui;
}

void NewBlock::create_block() {
    auto *current_item = ui->blocklist->currentItem();
    if(current_item != nullptr){
        lookup_correct_block(current_item->text());
    }
    close();
}

void NewBlock::lookup_correct_block(const QString& block_name) {
    if(block_name == "LcdNumberOutput"){
        auto block = new LcdNumberOutputBlock(_connector, _mainframe, LcdNumberOutputBlock::standard_property_set());
        qDebug() << block;
        _output_blocks->emplace_back(block);
    }
}
