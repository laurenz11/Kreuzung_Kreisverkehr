
#include "GUI.h"


GUI::~GUI()
{
}

GUI::GUI(sf::RenderWindow* window) {

	this->initGUI(window);
	gui.add(closeButton);
	gui.add(startButton);
	gui.add(stopButton);
	gui.add(labeleditBox);
	gui.add(editBoxMinutes);
	gui.add(editBoxSeconds);
	gui.add(colon);
}

void GUI::initGUI(sf::RenderWindow* window) {
	gui.setTarget(*window);
	this->loadFont();
	this->initCloseButton(window);
	this->initStartButton();
	this->initStopButton();
	this->initLabelEditBox();
	this->initEditBoxTime();
}

std::string GUI::getTextFromEditBox() {
	return this->editBoxMinutes->getText();
	return this->editBoxSeconds->getText();
}

void GUI::handleEvent(sf::Event event)
{
	gui.handleEvent(event);
}

void GUI::initCloseButton(sf::RenderWindow* window)
{
	
	closeButton->setPosition(1350.f, 920.f);
	closeButton->setSize(100.f, 50.f);
	closeButton->setText("Close");
	closeButton->getRenderer()->setFont(font);
	closeButton->setTextSize(20.f);
}

void GUI::initStartButton()
{
	
	startButton->setPosition(1200.f, 920.f);
	startButton->setSize(100.f, 50.f);
	startButton->setText("Start");
	startButton->getRenderer()->setFont(font);
	startButton->setTextSize(20.f);

	
}

void GUI::initStopButton()
{
	
	stopButton->setPosition(1050.f, 920.f);
	stopButton->setSize(100.f, 50.f);
	stopButton->setText("Stopp");
	stopButton->getRenderer()->setFont(font);
	stopButton->setTextSize(20.f);
}

void GUI::initEditBoxTime()
{
	editBoxMinutes->setSize(60.f, 40.f);
	editBoxMinutes->setPosition(1050.f, 720.f);
	editBoxMinutes->setTextSize(12);
	editBoxMinutes->setDefaultText("Min.");
	editBoxMinutes->setMaximumCharacters(5);
	editBoxMinutes->setInputValidator("[0-9]*");

	editBoxSeconds->setSize(60.f, 40.f);
	editBoxSeconds->setPosition(1115.f, 720.f);
	editBoxSeconds->setTextSize(12);
	editBoxSeconds->setDefaultText("Sek.");
	editBoxSeconds->setMaximumCharacters(5);
	editBoxSeconds->setInputValidator("[0-9]*");

	
}

void GUI::initLabelEditBox() {
	labeleditBox->setPosition(1050.f, 700.f);
	labeleditBox->setSize(190.f, 50.f);
	labeleditBox->setText("Simulationsdauer eingeben: ");
	labeleditBox->getRenderer()->setFont(font);
	labeleditBox->setTextSize(12.f);

	colon->setPosition(1104.f, 715.f);
	colon->setSize(20.f, 40.f);
	colon->setText(":");
	colon->getRenderer()->setFont(font);
	colon->setTextSize(35);
	
}
void GUI::loadFont()
{
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "font konnte nicht geladen werde!" << std::endl;
	}
}

void GUI::ClickedOnClose(sf::RenderWindow* window, sf::Event event) {
	
	if (this->closeButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
		this->close(window);
	}
}

bool GUI::ClickedOnStart(sf::Event event,  bool *startIsAllowed)
{
	if (this->startButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
		 *startIsAllowed = true;
		 std::cout << "clicked on start" << std::endl;
		 return *startIsAllowed;

	}
}

bool GUI::ClickedOnStop(sf::Event event, bool *startIsAllowed)
{
	
	if (this->stopButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
		*startIsAllowed = false;
		return *startIsAllowed;
	}
}

void GUI::close(sf::RenderWindow* window) {
	window->close();
}

void GUI::render(sf::RenderWindow* window)
{
	gui.draw();
}



