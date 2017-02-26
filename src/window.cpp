// Qt
#include <QtGui>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QClipboard>

#include "window.h"

#include <fstream>

MainWindow::MainWindow() : 
QMainWindow(), Ui_MainWindow(), 
maxNumRecentFiles(15), recentFileActs(15)
{
	setupUi(this);
    
	// init scene
	m_scene = new Scene;
	viewer->set_scene(m_scene);
    
    
	// Handling actions
	connect(actionQuit, SIGNAL(triggered()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
	delete m_scene;
}

void MainWindow::update()
{
	viewer->repaint();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
	event->accept();
}



void MainWindow::on_actionClear_triggered()
{
	m_scene->clear();
	update();
}

void MainWindow::on_actionRandom_triggered()
{
	m_scene->random();
	update();
}





