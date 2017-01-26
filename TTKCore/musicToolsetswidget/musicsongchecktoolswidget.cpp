#include "musicsongchecktoolswidget.h"
#include "ui_musicsongchecktoolswidget.h"
#include "musictoolsetsuiobject.h"
#include "musicuiobject.h"

MusicSongCheckToolsWidget::MusicSongCheckToolsWidget(QWidget *parent)
    : MusicAbstractMoveWidget(parent),
      m_ui(new Ui::MusicSongCheckToolsWidget)
{
    m_ui->setupUi(this);

    m_ui->topTitleCloseButton->setIcon(QIcon(":/functions/btn_close_hover"));
    m_ui->topTitleCloseButton->setStyleSheet(MusicUIObject::MToolButtonStyle03);
    m_ui->topTitleCloseButton->setCursor(QCursor(Qt::PointingHandCursor));
    m_ui->topTitleCloseButton->setToolTip(tr("Close"));
    connect(m_ui->topTitleCloseButton, SIGNAL(clicked()), SLOT(close()));

    renameWidgetInit();
    qualityWidgetInit();
    duplicateWidgetInit();

    switchToSelectedItemStyle(0);
}

MusicSongCheckToolsWidget::~MusicSongCheckToolsWidget()
{
    delete m_ui;
}

QString MusicSongCheckToolsWidget::getClassName()
{
    return staticMetaObject.className();
}

void MusicSongCheckToolsWidget::renameButtonClicked()
{
    switchToSelectedItemStyle(0);
}

void MusicSongCheckToolsWidget::renameButtonCheckClicked()
{
    if(m_ui->renameCheckButton->text() == tr("StarCheck") ||
       m_ui->renameCheckButton->text() == tr("ReCheck"))
    {
        m_ui->renameReCheckButton->hide();
        m_ui->renameLoadingLabel->start();
        m_ui->renameLoadingLabel->show();
        m_ui->renameCheckButton->setText(tr("StopCheck"));
    }
    else if(m_ui->renameCheckButton->text() == tr("StopCheck"))
    {
        m_ui->renameLoadingLabel->stop();
        m_ui->renameLoadingLabel->hide();
        m_ui->renameCheckButton->setText(tr("StarCheck"));
    }
    else if(m_ui->renameCheckButton->text() == tr("ApplayCheck"))
    {
        m_ui->renameLoadingLabel->stop();
        m_ui->renameLoadingLabel->hide();
        m_ui->renameReCheckButton->show();
    }
}

void MusicSongCheckToolsWidget::qualityButtonClicked()
{
    switchToSelectedItemStyle(1);
}

void MusicSongCheckToolsWidget::qualityButtonCheckClicked()
{

}

void MusicSongCheckToolsWidget::duplicateButtonClicked()
{
    switchToSelectedItemStyle(2);
}

void MusicSongCheckToolsWidget::duplicateButtonCheckClicked()
{

}

void MusicSongCheckToolsWidget::show()
{
    setBackgroundPixmap(m_ui->background, size());
    MusicAbstractMoveWidget::show();
}

void MusicSongCheckToolsWidget::renameWidgetInit()
{
    m_ui->renameSelectAllButton->setStyleSheet(MusicUIObject::MCheckBoxStyle01);
    m_ui->renameCheckButton->setStyleSheet(MusicUIObject::MPushButtonStyle04);

    connect(m_ui->renameButton, SIGNAL(clicked()), SLOT(renameButtonClicked()));
    connect(m_ui->renameCheckButton, SIGNAL(clicked()), SLOT(renameButtonCheckClicked()));

    m_ui->renameSelectAllButton->setEnabled(false);
    m_ui->renameLoadingLabel->setType(MusicGifLabelWidget::Gif_Cicle_Blue);
    m_ui->renameLoadingLabel->hide();
    m_ui->renameReCheckButton->hide();
}

void MusicSongCheckToolsWidget::qualityWidgetInit()
{
    m_ui->qualityCheckButton->setStyleSheet(MusicUIObject::MPushButtonStyle04);

    connect(m_ui->qualityButton, SIGNAL(clicked()), SLOT(qualityButtonClicked()));
}

void MusicSongCheckToolsWidget::duplicateWidgetInit()
{
    m_ui->duplicateCheckButton->setStyleSheet(MusicUIObject::MPushButtonStyle04);

    connect(m_ui->duplicateButton, SIGNAL(clicked()), SLOT(duplicateButtonClicked()));
}

void MusicSongCheckToolsWidget::switchToSelectedItemStyle(int index)
{
    m_ui->renameButton->setStyleSheet(MusicUIObject::MKGCheckTestRename);
    m_ui->qualityButton->setStyleSheet(MusicUIObject::MKGCheckTestQuality);
    m_ui->duplicateButton->setStyleSheet(MusicUIObject::MKGCheckTestDuplicate);

    m_ui->stackedWidget->setCurrentIndex(index);
    switch(index)
    {
        case 0: m_ui->renameButton->setStyleSheet(MusicUIObject::MKGCheckTestRenameClicked); break;
        case 1: m_ui->qualityButton->setStyleSheet(MusicUIObject::MKGCheckTestQualityClicked);break;
        case 2: m_ui->duplicateButton->setStyleSheet(MusicUIObject::MKGCheckTestDuplicateClicked);break;
        default: break;
    }
}
