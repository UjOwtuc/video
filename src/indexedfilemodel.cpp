#include "indexedfilemodel.h"


IndexedFileModel::IndexedFileModel(QObject* parent)
	: QAbstractTableModel(parent)
{
	m_digits = 1;
}


QVariant IndexedFileModel::data(const QModelIndex& index, int role) const
{
	if (! index.isValid())
		return QVariant();

	switch (role)
	{
		case Qt::DisplayRole :
		case Qt::UserRole :
		{
			auto it = m_files.constBegin() + index.row();
			if (index.column() == 0)
				return QString("%1").arg(it.key(), m_digits, 10, QLatin1Char('0'));
			return it.value();
		}
	}
	return QVariant();
}


bool IndexedFileModel::addEntry(quint64 id, const QString& filename)
{
	if (m_files.contains(id))
		return false;

	quint64 rows_above = std::count_if(m_files.keyBegin(), m_files.keyEnd(), [id](quint64 key) {
		return key < id;
	});

	beginInsertRows(QModelIndex(), rows_above, rows_above);
	m_files.insert(id, filename);
	endInsertRows();

	m_digits = QString::number(m_files.lastKey()).length();
	return true;
}


void IndexedFileModel::addEntry(const QString& filename)
{
	quint64 id = 1;
	if (! m_files.isEmpty())
		id = m_files.lastKey() +1;

	beginInsertRows(QModelIndex(), m_files.size(), m_files.size());
	m_files.insert(id, filename);
	endInsertRows();
	m_digits = QString::number(m_files.lastKey()).length();
}
