#include "video.h"
#include "ui_video.h"

video::video(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::video)
{
    m_ui->setupUi(this);
}

video::~video() = default;
