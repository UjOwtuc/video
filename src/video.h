#ifndef VIDEO_H
#define VIDEO_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class video;
}

class video : public QMainWindow
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video() override;

private:
    QScopedPointer<Ui::video> m_ui;
};

#endif // VIDEO_H
