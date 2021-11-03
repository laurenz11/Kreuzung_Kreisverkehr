
#include "GUI.h"


GUI::~GUI()
{
}

GUI::GUI(sf::RenderWindow* window) {

	this->initGUI(window);
	gui.add(closeButton);
	gui.add(stopButton);
	gui.add(startButton);
	gui.add(labeleditBox);
	gui.add(editBoxMinutes);
	gui.add(editBoxSeconds);
	gui.add(colon);
	gui.add(warning);
}

void GUI::initGUI(sf::RenderWindow* window) {
	gui.setTarget(*window);
	this->loadFont();
	this->initCloseButton(window);
	this->initStartButton();
	this->initStopButton();
	this->initLabelEditBox();
	this->initEditBoxTime();//Für die Eingabe der Zeit
	this->initWarning();

}


std::string GUI::getTextFromEditBox() {
	return this->editBoxMinutes->getText();
	return this->editBoxSeconds->getText();
}

unsigned int GUI::getTimeFromEditBox() {
	//std::cout << StringConverter::toInt(editBoxMinutes->getText()) * 60  << std::endl;
	if (editBoxMinutes->getText().getSize() == 0) {
		return StringConverter::toInt(editBoxSeconds->getText());
	}
	else if (editBoxSeconds->getText().getSize() == 0) {
		return StringConverter::toInt(editBoxMinutes->getText()) * 60;
	}

	else
		return (StringConverter::toInt(editBoxMinutes->getText()) * 60 + StringConverter::toInt(editBoxSeconds->getText()));
	
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
	startButton->setVisible(true);
	startButton->setEnabled(true);
	
}

void GUI::initStopButton()
{
	
	stopButton->setPosition(1100.f, 920.f);
	stopButton->setSize(100.f, 50.f);
	stopButton->setText("Stopp");
	stopButton->getRenderer()->setFont(font);
	stopButton->setTextSize(20.f);
	stopButton->setVisible(false);
	stopButton->setEnabled(false);
}

void GUI::initEditBoxTime()
{
	editBoxMinutes->setSize(60.f, 40.f);
	editBoxMinutes->setPosition(1050.f, 720.f);
	editBoxMinutes->setTextSize(18);
	editBoxMinutes->setDefaultText("Min.");
	editBoxMinutes->setMaximumCharacters(5);
	editBoxMinutes->setInputValidator("[0-9]*");

	editBoxSeconds->setSize(60.f, 40.f);
	editBoxSeconds->setPosition(1115.f, 720.f);
	editBoxSeconds->setTextSize(18);
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

void GUI::initTimeTextBox()//Für die Ausgabe der abgelaufenen Zeit
{
	this->timeBox->setSize(120.f, 40.f);
	this->timeBox->setPosition(1300.f, 720.f);
	this->timeBox->setDefaultText("0.0");
	this->timeBox->setText(secondsString + " sec");
	this->timeBox->getRenderer()->setFont(font);
	this->timeBox->setTextSize(18);
	this->timeBox->setReadOnly(true);
	this->gui.add(timeBox);
}

void GUI::initWarning() {
	this->warning->setSize(250.f, 50.f);
	this->warning->setPosition(1150.f, 900.f);
	this->warning->setText("Bitte Simulationsdauer eingeben");
	this->warning->getRenderer()->setFont(font);
	this->warning->setVisible(false);
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
	if (this->startButton->mouseOnWidget(tgui::Vector2f(event.mouseButton.x, event.mouseButton.y))|| event.key.code == sf::Keyboard::Enter) {
		if (this->editBoxMinutes->getText().getSize() != 0 || this->editBoxSeconds->getText().getSize() != 0) {
			*startIsAllowed = true;
			std::cout << "clicked on start" << std::endl;
			this->warning->setVisible(false);
			return *startIsAllowed;
			
			
		}
		else {
			this->warning->setVisible(true);
		}

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


void GUI::takeElapsedTime(unsigned int sec, unsigned int ms)
{
	this->secondsToString(sec);
	this->msecondsToString(ms);
}


void GUI::secondsToString(unsigned int sec)
{
	secondsString = StringConverter::toString(sec);
}


void GUI::msecondsToString(unsigned int ms)
{
	msecondsString = StringConverter::toString(ms);
}


void GUI::StartStopSwitch(bool switcher) {
	if (switcher) {
		this->stopButton->setEnabled(true);
		this->stopButton->setVisible(true);
		this->startButton->setEnabled(false);
		this->startButton->setVisible(false);
	}
	else {
		this->startButton->setEnabled(true);
		this->startButton->setVisible(true);
		this->stopButton->setEnabled(false);
		this->stopButton->setVisible(false);
	}

}

