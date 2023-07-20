#include "filenamedelegate.h"

#include <QApplication>
#include <QFileInfo>


QStyleOptionViewItem FilenameDelegate::buildOptions(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionViewItem opt = option;
	initStyleOption(&opt, index);

	QFileInfo info(index.model()->data(index, Qt::UserRole).toString());
	opt.text = info.baseName();
	return opt;
}


void FilenameDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionViewItem opt = buildOptions(option, index);
	qApp->style()->drawControl(QStyle::CE_ItemViewItem, &opt, painter);
}


QSize FilenameDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionViewItem opt = buildOptions(option, index);
	QSize hint = opt.fontMetrics.boundingRect(opt.text).size();
	hint = qApp->style()->sizeFromContents(QStyle::CT_ItemViewItem, &opt, hint);
	return hint;
}
