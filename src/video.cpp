#include "video.h"
#include "ui_video.h"

#include "indexedfilemodel.h"
#include "filenamedelegate.h"
#include "player.h"
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QSortFilterProxyModel>


Video::Video(QWidget *parent) :
	QMainWindow(parent),
	m_ui(new Ui::video)
{
	m_ui->setupUi(this);

	m_model = new IndexedFileModel();
	m_proxy = new QSortFilterProxyModel(this);
	m_proxy->setSourceModel(m_model);
	m_proxy->setFilterKeyColumn(0);
	m_ui->tableView->setModel(m_proxy);
	m_ui->tableView->setItemDelegateForColumn(1, new FilenameDelegate());

	connect(m_ui->numEdit, &QLineEdit::textChanged, [this](const QString& filter){
		QString digits;
		for (auto c : filter)
		{
			if (c.isDigit())
				digits += c;
		}
		if (digits != filter)
			m_ui->numEdit->setText(digits);
		else
			m_proxy->setFilterRegExp("^" + digits);
	});

	connect(m_ui->numEdit, &QLineEdit::returnPressed, this, &Video::start);
	connect(m_ui->startButton, &QToolButton::clicked, this, &Video::start);
}


Video::~Video() = default;


void Video::start()
{
	if (m_proxy->rowCount() > 0)
	{
		QString file = m_proxy->data(m_proxy->index(0, 1), Qt::UserRole).toString();
		qDebug() << "start video" << file;

		Player* p = new Player(this, file);
		p->showFullScreen();
		p->setFocus();
	}

	m_ui->numEdit->clear();
}


void Video::loadSource(const QString& filename)
{
	QFileInfo info(filename);
	if (info.isDir())
		addDir(info.absoluteFilePath());
	else
		addFile(info.absoluteFilePath());

	m_ui->tableView->resizeColumnsToContents();
	m_ui->tableView->resizeRowsToContents();
}


void Video::addDir(const QString& path)
{
	QDir dir(path);
	auto entries = dir.entryInfoList(QDir::Files | QDir::Readable);
	for (const QFileInfo& info : entries)
		m_model->addEntry(info.absoluteFilePath());
}


void Video::addFile(const QString& file)
{
	m_model->addEntry(QFileInfo(file).absoluteFilePath());
}
