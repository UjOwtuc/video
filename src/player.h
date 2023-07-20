#ifndef PLAYER_H
#define PLAYER_H

#include <QVideoWidget>

class QMediaPlayer;
class QSignalBlocker;

class Player : public QVideoWidget
{
	Q_OBJECT
public:
	Player(QObject* parent, const QString& filename);
	~Player();

protected:
	void showEvent(QShowEvent* event) override;
	void hideEvent(QHideEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;

private:
	QMediaPlayer* m_media_player;
	QSignalBlocker* m_parentBlocker;
};

#endif // PLAYER_H
