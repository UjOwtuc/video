#ifndef VIDEO_H
#define VIDEO_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class video;
}
class IndexedFileModel;
class QSortFilterProxyModel;

class Video : public QMainWindow
{
	Q_OBJECT

public:
	explicit Video(QWidget *parent = nullptr);
	~Video() override;

	void loadSource(const QString& filename);

protected slots:
	void start();

private:
	void addDir(const QString& path);
	void addFile(const QString& file);

	QScopedPointer<Ui::video> m_ui;
	IndexedFileModel* m_model;
	QSortFilterProxyModel* m_proxy;
};

#endif // VIDEO_H
