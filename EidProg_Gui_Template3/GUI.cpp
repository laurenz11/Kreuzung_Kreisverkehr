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

	gui.add(outcomeEast); std::cout << "incomeEast added" << std::endl;
	gui.add(outcomeNorth);
	gui.add(outcomeSouth);
	gui.add(outcomeWest);

	gui.add(incomeEast); std::cout << "incomeEast added" << std::endl;
	gui.add(incomeNorth);
	gui.add(incomeSouth);
	gui.add(incomeWest);

	gui.add(labelCounterOutcomeStart);
	gui.add(labelCounterOutcomeZiel);
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
	this->initCounterOutcome();
	this->initLabelCounterOutcome();
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
	editBoxMinutes->setMaximumCharacters(1);
	editBoxMinutes->setInputValidator("[1-9]*");

	editBoxSeconds->setSize(60.f, 40.f);
	editBoxSeconds->setPosition(1115.f, 720.f);
	editBoxSeconds->setTextSize(18);
	editBoxSeconds->setDefaultText("Sek.");
	editBoxSeconds->setMaximumCharacters(2);
	editBoxSeconds->setInputValidator("[1-9]*");

	
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
	timeBox->setSize(120.f, 40.f);
	timeBox->setPosition(1300.f, 720.f);
	timeBox->setDefaultText("0.0");
	timeBox->setText(secondsString + " sec");
	timeBox->getRenderer()->setFont(font);
	timeBox->setTextSize(18);
	timeBox->setReadOnly(true);
	gui.add(timeBox);
}

void GUI::initWarning() {
	this->warning->setSize(250.f, 50.f);
	this->warning->setPosition(1150.f, 900.f);
	this->warning->setText("Bitte Simulationsdauer eingeben");
	this->warning->getRenderer()->setFont(font);
	this->warning->setVisible(false);
}

void GUI::initCounterOutcome() {
	outcomeEast->setSize(50.f, 40.f);
	outcomeEast->setPosition(1450.f, 300.f);
	outcomeEast->getRenderer()->setFont(font);
	outcomeEast->setReadOnly(true);

	outcomeWest->setSize(50.f, 40.f);
	outcomeWest->setPosition(1250.f, 300.f);
	outcomeWest->getRenderer()->setFont(font);
	outcomeWest->setReadOnly(true);

	outcomeSouth->setSize(50.f, 40.f);
	outcomeSouth->setPosition(1350.f, 400.f);
	outcomeSouth->getRenderer()->setFont(font);
	outcomeSouth->setReadOnly(true);

	outcomeNorth->setSize(50.f, 40.f);
	outcomeNorth->setPosition(1350.f, 200.f);
	outcomeNorth->getRenderer()->setFont(font);
	outcomeNorth->setReadOnly(true);

	

	incomeEast->setSize(50.f, 40.f);
	incomeEast->setPosition(1200.f, 300.f);
	incomeEast->getRenderer()->setFont(font);
	incomeEast->setReadOnly(true);

	incomeWest->setSize(50.f, 40.f);
	incomeWest->setPosition(1000.f, 300.f);
	incomeWest->getRenderer()->setFont(font);
	incomeWest->setReadOnly(true);

	incomeSouth->setSize(50.f, 40.f);
	incomeSouth->setPosition(1100.f, 400.f);
	incomeSouth->getRenderer()->setFont(font);
	incomeSouth->setReadOnly(true);

	incomeNorth->setSize(50.f, 40.f);
	incomeNorth->setPosition(1100.f, 200.f);
	incomeNorth->getRenderer()->setFont(font);
	incomeNorth->setReadOnly(true);
}

void GUI::initLabelCounterOutcome(){
	labelCounterOutcomeStart->setSize(75.f, 30.f);
	labelCounterOutcomeStart->setPosition(1100.f, 150.f);
	labelCounterOutcomeStart->setText("Start");
	labelCounterOutcomeStart->getRenderer()->setFont(font);
	labelCounterOutcomeStart->setTextSize(20);

	labelCounterOutcomeZiel->setSize(75.f, 30.f);
	labelCounterOutcomeZiel->setPosition(1350.f, 150.f);
	labelCounterOutcomeZiel->setText("Ziel");
	labelCounterOutcomeZiel->getRenderer()->setFont(font);
	labelCounterOutcomeZiel->setTextSize(20);
}

void GUI::updateCounterOutcome(int endCounterNorth,int endCounterEast,int endCounterSouth,int endCounterWest,int startCounterNorth,int startCounterEast,int startCounterSouth,int startCounterWest) {
	outcomeEast->setText(StringConverter::toString(endCounterEast));
	outcomeWest->setText(StringConverter::toString(endCounterWest));
	outcomeSouth->setText(StringConverter::toString(endCounterSouth));
	outcomeNorth->setText(StringConverter::toString(endCounterNorth));

	incomeEast->setText(StringConverter::toString(startCounterEast));
	incomeWest->setText(StringConverter::toString(startCounterWest));
	incomeSouth->setText(StringConverter::toString(startCounterSouth));
	incomeNorth->setText(StringConverter::toString(startCounterNorth));
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

