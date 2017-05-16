#include "trenchcoatqt.h"
#include <string>

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
	shoppingBasketLayout->addWidget(new QPushButton{ "&Next" });

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
		QString itemInList = QString::fromStdString(s.getColor() + " - " + s.getSize() + " -Price: " + std::to_string(s.getPrice()));
		this->repoList->addItem(itemInList);
	}

	if (this->currentTshirtsInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void TrenchCoatQt::connectSignalAndSlots()
{
//	QObject::connect(this->nameFilter, SIGNAL(textChanged()), this, SLOT(filterTshirtsByLength()));
	QObject::connect(this->nameFilter, &QLineEdit::textChanged, this, &TrenchCoatQt::filterTshirtsByLength);

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