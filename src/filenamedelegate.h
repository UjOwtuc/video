#ifndef FILENAMEDELEGATE_H
#define FILENAMEDELEGATE_H

#include <QStyledItemDelegate>

class FilenameDelegate : public QStyledItemDelegate
{
public:
	QStyleOptionViewItem buildOptions(const QStyleOptionViewItem& option, const QModelIndex& index) const;

	void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const override;
	QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const override;
};

#endif // FILENAMEDELEGATE_H
