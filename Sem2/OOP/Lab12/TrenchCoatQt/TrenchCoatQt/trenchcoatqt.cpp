#include "trenchcoatqt.h"
#include <string>
#include <qmessagebox.h>
#include "RepositoryException.h"
#include "TshirtValidator.h"
#include <exception>

TrenchCoatQt::TrenchCoatQt(Controller& c,QWidget *parent):ctrl{c},QWidget{parent}
{
	this->initGUI();
	this->currentTshirtsInRepoList = this->ctrl.getRepo().getTshirts();
	this->populateRepoList();
}

TrenchCoatQt::~TrenchCoatQt()
{

}


void TrenchCoatQt::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };
	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the song data
	// - grid layout with buttons: add, delete, update, filter
	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	//Lab Activity;
	this->detailComboButton = new QComboBox{};
	QString detailed = "Detailed";
	QString succint = "Short";
	this->detailComboButton->addItem(detailed);
	this->detailComboButton->addItem(succint);



	this->nameFilter = new QLineEdit{};
	QLabel* nameLabel = new QLabel{ "&Filter:" };
	nameLabel->setBuddy(nameFilter);

	//list
	this->repoList = new QListWidget{};
	//set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	//Tshirt data
	QWidget* tshirtDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ tshirtDataWidget };
	this->size = new QLineEdit{};
	this->color = new QLineEdit{};
	this->price = new QLineEdit{};
	this->quantity = new QLineEdit{};
	this->link = new QLineEdit{};
	this->length = new QLineEdit{};
	formLayout->addRow("&Size:", size);
	formLayout->addRow("&Color:", color);
	formLayout->addRow("&Price:", price);
	formLayout->addRow("&Quantity:", quantity);
	formLayout->addRow("&Link:", link);
	formLayout->addRow("&Length:", length);

	//buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->filterButton = new QPushButton("Filter");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 1, 0);
	gridLayout->addWidget(filterButton, 1, 1);

	//add everything to the left layout
	leftSide->addWidget(nameLabel);
	leftSide->addWidget(nameFilter);
	leftSide->addWidget(detailComboButton);
	//TODO
	leftSide->addWidget(new QLabel{ "All Tshirts" });
	leftSide->addWidget(repoList);
	leftSide->addWidget(tshirtDataWidget);
	leftSide->addWidget(buttonsWidget);

	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->buy = new QPushButton{ ">> Buy" };
	this->saveToFile = new QPushButton{ ">> Save" };
	this->openFromFile = new QPushButton{ ">> Open" };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->buy);
	vLayoutUpperPart->addWidget(this->saveToFile);
	vLayoutUpperPart->addWidget(this->openFromFile);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right component: the playlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	shoppingBasket = new QListWidget{};
	
	//One button
	QWidget* shoppingBasketButtonsWidget = new QWidget{};
	QHBoxLayout* shoppingBasketLayout = new QHBoxLayout{ shoppingBasketButtonsWidget };
	
	
	this->nameFilter2 = new QLineEdit{};
	QLabel* nameLabel2 = new QLabel{ "&Total:" };
	nameLabel2->setBuddy(nameFilter2);

	shoppingBasketLayout->addWidget(nameLabel2);
	shoppingBasketLayout->addWidget(nameFilter2);

	//add everything to the right layout
	rightSide->addWidget(new QLabel{ "Shopping Basket" });
	rightSide->addWidget(shoppingBasket);
	rightSide->addWidget(shoppingBasketButtonsWidget);

	//add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	//connect the signals and slots
	this->connectSignalAndSlots();

}

void TrenchCoatQt::populateRepoList()
{
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto s : this->currentTshirtsInRepoList) {
		QString itemInList = QString::fromStdString(s.getColor() + " - " + s.getSize() + " -Price: " + std::to_string(s.getPrice()) + " length: " + std::to_string(s.getLength()));
		this->repoList->addItem(itemInList);
	}

	if (this->currentTshirtsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void TrenchCoatQt::connectSignalAndSlots()
{
//	QObject::connect(this->nameFilter, SIGNAL(textChanged()), this, SLOT(filterTshirtsByLength()));
	QObject::connect(this->nameFilter, &QLineEdit::textChanged, this, &TrenchCoatQt::filterTshirtsByLength);
	QObject::connect(this->detailComboButton, &QComboBox::currentTextChanged, this, &TrenchCoatQt::combo_box_handler);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &TrenchCoatQt::deleteTshirt);
	QObject::connect(this->addButton, &QPushButton::clicked, this, &TrenchCoatQt::addTshirt);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &TrenchCoatQt::updateTshirt);
	QObject::connect(this->filterButton, &QPushButton::clicked, this, &TrenchCoatQt::filterTshirtByLength);
	QObject::connect(this->repoList, &QListWidget::itemSelectionChanged, this, &TrenchCoatQt::listItemChanged);
	QObject::connect(this->buy, &QPushButton::clicked, this, &TrenchCoatQt::buyTshirt);
	QObject::connect(this->saveToFile, &QPushButton::clicked, this, &TrenchCoatQt::saveToFileSB);
	QObject::connect(this->openFromFile, &QPushButton::clicked, this, &TrenchCoatQt::openFromFileSB);
}

void TrenchCoatQt::filterTshirtsByLength()
{
	std::string length = this->nameFilter->text().toStdString();
	if (length == "") {
		this->currentTshirtsInRepoList = this->ctrl.getRepo().getTshirts();
		this->populateRepoList();
		return;
	}
	int len = stoi(length);
	this->currentTshirtsInRepoList = this->ctrl.filterByLength(len);
	this->populateRepoList();

}

void TrenchCoatQt::combo_box_handler()
{
	if (this->detailComboButton->currentText() == "Detailed") {
		this->populateRepoList();
	}
	else {
		this->populateShortList();
	}
}

void TrenchCoatQt::populateShortList()
{
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto s : this->currentTshirtsInRepoList) {
		QString itemInList = QString::fromStdString(s.getColor() + " - " + s.getSize() );
		this->repoList->addItem(itemInList);
	}

	if (this->currentTshirtsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}


void TrenchCoatQt::deleteTshirt()
{
	std::string link = this->link->text().toStdString();
	try {
		this->ctrl.deleteTshirt(link);
		//refresh list
		this->currentTshirtsInRepoList = this->ctrl.getRepo().getTshirts();
		this->populateRepoList();
	}
	catch (NotFoundTshirtException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
	catch (NotSoldOutException& e)
	{
		QMessageBox messageBox;
		messageBox.information(0, "Error", e.what());
	}
}

void TrenchCoatQt::addTshirt()
{
	//addTshirt(const std::string & size, const std::string & color, double price, int quantity, const std::string & link, int length)
	//read data from textbox
	std::string size = this->size->text().toStdString();
	std::string color = this->color->text().toStdString();
	double price = this->price->text().toDouble();
	int quantity = this->quantity->text().toInt();
	std::string link = this->link->text().toStdString();
	int length = this->length->text().toInt();
	try {
		this->ctrl.addTshirt(size, color, price, quantity, link, length);
		//refresh the list
		this->currentTshirtsInRepoList = this->ctrl.getRepo().getTshirts();
		this->populateRepoList();
	}
	catch (TshirtException& e) {
		QMessageBox messageBox;
		for(auto er : e.getErrors())
			messageBox.critical(0, "Error",er.c_str());
	}

}

void TrenchCoatQt::updateTshirt()
{
	//read data from textbox
	std::string size = this->size->text().toStdString();
	std::string color = this->color->text().toStdString();
	double price = this->price->text().toDouble();
	int quantity = this->quantity->text().toInt();
	std::string link = this->link->text().toStdString();
	int length = this->length->text().toInt();
	try {
		this->ctrl.updateTshirt(size, color, price, quantity, link, length);
		//refresh the list
		this->currentTshirtsInRepoList = this->ctrl.getRepo().getTshirts();
		this->populateRepoList();
	}
	catch (TshirtException& e) {
		QMessageBox messageBox;
		for (auto er : e.getErrors())
			messageBox.critical(0, "Error", er.c_str());
	}
	catch (NotFoundTshirtException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TrenchCoatQt::filterTshirtByLength()
{
	int length = this->length->text().toInt();
	
	this->currentTshirtsInRepoList = this->ctrl.filterByLength(length);
	this->populateRepoList();
}

void TrenchCoatQt::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;
	std::vector<Tshirt> tshirts = this->currentTshirtsInRepoList;

	if (idx >= tshirts.size())
		return;
	Tshirt t = tshirts[idx];
	this->size->setText(QString::fromStdString(t.getSize()));
	this->color->setText(QString::fromStdString(t.getColor()));
	std::string p = std::to_string(t.getPrice());
	this->price->setText(QString::fromStdString(p));
	std::string q = std::to_string(t.getQuantity());
	this->quantity->setText(QString::fromStdString(q));
	this->link->setText(QString::fromStdString(t.getLink()));
	std::string l = std::to_string(t.getLength());
	this->length->setText(QString::fromStdString(l));
	t.display();
}

int TrenchCoatQt::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->size->clear();
		this->color->clear();
		this->price->clear();
		this->quantity->clear();
		this->link->clear();
		this->length->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void TrenchCoatQt::buyTshirt()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentTshirtsInRepoList.size())
		return;
	const Tshirt& t = this->currentTshirtsInRepoList[idx];
	this->ctrl.buyTshirt(t);
	this->populateShopingBasket();
}

void TrenchCoatQt::populateShopingBasket()
{
	if (this->shoppingBasket->count() > 0)
		this->shoppingBasket->clear();
	for (auto t : this->ctrl.getShoppingBascket()->getTshirts()) {
		QString itemList = QString::fromStdString(t.getColor() + " - " + t.getSize() + " -Price: " + std::to_string(t.getPrice()) + " length: " + std::to_string(t.getLength()));
		this->shoppingBasket->addItem(itemList);
	}
	double total = this->ctrl.getShoppingBascket()->getTotalSum();
	QString itemTotal = QString::fromStdString(std::to_string(total));
	this->nameFilter2->setText(itemTotal);
}

void TrenchCoatQt::saveToFileSB()
{
	std::string filename = "D:\\out.txt";
	try
	{
		this->ctrl.saveShoppingBasketToFile(filename);
	}
	catch (FileException& e) {
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void TrenchCoatQt::openFromFileSB()
{
	this->ctrl.openShoppingBasket();
}