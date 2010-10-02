// Konstruktor - An interactive LDraw modeler for KDE
// Copyright (c)2006-2008 Park "segfault" J. K. <mastermind@planetmono.org>

#ifndef _DBUPDATER_H_
#define _DBUPDATER_H_

#include <QMutex>
#include <QObject>

#define DB_REVISION_NUMBER 3

class KonstruktorDBManager;
class KonstruktorPixmapRenderer;
class KonstruktorConfig;

namespace ldraw
{
    class part_library;
    class reader;
}

class KonstruktorDBUpdater : public QObject
{
  public:
	KonstruktorDBUpdater(QObject *parent = 0L);
	~KonstruktorDBUpdater();

	void dropOutdatedTables();
	void constructTables();
	void deleteAll();
	int start();
	
  private:
	bool checkTable(const QString &name);
	QString saveLocation(const QString &path);

	static QString escape(const QString &string);
	static QString unescape(const QString &string);

	void determineSize(const QString &str, float &xs, float &ys, float &zs);
	float floatify(const QString &str);
	void deletePartImages();

	QMutex globalMutex_;
	KonstruktorDBManager *manager_;
	KonstruktorPixmapRenderer *renderer_;
	KonstruktorConfig *config_;
	ldraw::part_library *library_;
	ldraw::reader *reader_;

	bool status_;
	bool forceRescan_;
};

#endif
