#ifndef TRENCHCOATQT_H
#define TRENCHCOATQT_H

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include "CSVShoppingBasket.h"
#include "HTMLShoppingBasket.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


class TrenchCoatQt : public QWidget
{
	Q_OBJECT

public:
	TrenchCoatQt(Controller& c, QWidget *parent = 0);
	~TrenchCoatQt();

private:
	Controller& ctrl;
	std::vector<Tshirt> currentTshirtsInRepoList;
	QLineEdit* nameFilter;
	QListWidget* repoList;
	QLineEdit* size;
	QLineEdit* color;
	QLineEdit* price;
	QLineEdit* quantity;
	QLineEdit* link;
	QLineEdit* length;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterButton;
	QPushButton* buy;
	QPushButton* saveToFile;
	QPushButton* openFromFile;

	QListWidget* shoppingBasket;

	void initGUI();
	void populateRepoList();
	
	void connectSignalAndSlots();

//public slots:
	void filterTshirtsByLength();
};

#endif // TRENCHCOATQT_H
