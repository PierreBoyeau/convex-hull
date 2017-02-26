#ifndef _WINDOW_
#define _WINDOW_

// std
#include <list>
#include <QWidget>

// Qt
#include <QString>
#include "scene.h"
#include "ui_convex.h"

class MainWindow : public QMainWindow, public Ui_MainWindow
{
	Q_OBJECT

private:
	Scene* m_scene;

	unsigned int maxNumRecentFiles;
	QAction* recentFilesSeparator;
	QVector<QAction*> recentFileActs;

public:
	MainWindow();
	~MainWindow();

	void update();

protected:

	protected slots:

	// drag & drop
	void closeEvent(QCloseEvent *event);

public slots:

	    // Data
		void on_actionClear_triggered();
		void on_actionRandom_triggered();
};

#endif // _WINDOW_
