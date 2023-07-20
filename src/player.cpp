#include "player.h"

#include <QDebug>
#include <QShowEvent>
#include <QMediaPlayer>
#include <QMessageBox>

Player::Player(QObject* parent, const QString& filename)
	: m_media_player(new QMediaPlayer),
	m_parentBlocker(new QSignalBlocker(parent))
{
	QPalette p = palette();
	p.setColor(QPalette::Window, Qt::black);
	setPalette(p);

	setCursor(Qt::BlankCursor);

	m_media_player->setMedia(QUrl::fromLocalFile(filename));
	m_media_player->setVideoOutput(this);

	connect(m_media_player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), [this](QMediaPlayer::Error err) {
		qDebug() << err;

		if (m_media_player->state() == QMediaPlayer::StoppedState)
		{
			deleteLater();
			QMessageBox::warning(this, "Fehler", "Video konnte nicht abgespielt werden", QMessageBox::Close);
		}
	});

	connect(m_media_player, &QMediaPlayer::stateChanged, [this](QMediaPlayer::State state) {
		if (state == QMediaPlayer::StoppedState)
			deleteLater();
	});
}


Player::~Player()
{
	delete m_parentBlocker;
	m_media_player->stop();
	delete m_media_player;
}


void Player::showEvent(QShowEvent* event)
{
	QVideoWidget::showEvent(event);
	m_media_player->play();
}


void Player::hideEvent(QHideEvent* event)
{
	QVideoWidget::hideEvent(event);
	m_media_player->pause();
}


void Player::keyPressEvent(QKeyEvent* /*event*/)
{
	deleteLater();
}
