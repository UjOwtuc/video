#ifndef INDEXEDFILEMODEL_H
#define INDEXEDFILEMODEL_H

#include <QAbstractTableModel>


class IndexedFileModel : public QAbstractTableModel
{
public:
	explicit IndexedFileModel(QObject* parent = nullptr);

	int rowCount(const QModelIndex &) const override { return m_files.size(); }
	int columnCount(const QModelIndex &) const override { return 2; }
	QVariant data(const QModelIndex & index, int role) const override;

	bool addEntry(quint64 id, const QString& filename);
	void addEntry(const QString& filename);

private:
	QMap<quint64, QString> m_files;
	int m_digits;
};

#endif // INDEXEDFILEMODEL_H
