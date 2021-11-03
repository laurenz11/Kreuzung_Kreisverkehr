#include "SFML/Graphics.hpp"
#include "TGUI/TGUI.hpp"
#include <iostream>
#include "string.h"

class GUI
{
private:
	~GUI();
	tgui::Gui gui;

	sf::Font font;
	tgui::Button::Ptr closeButton = tgui::Button::create();
	tgui::Button::Ptr startButton = tgui::Button::create();
	tgui::Button::Ptr stopButton = tgui::Button::create();
	tgui::EditBox::Ptr editBoxMinutes = tgui::EditBox::create();
	tgui::EditBox::Ptr editBoxSeconds = tgui::EditBox::create();
	tgui::Label::Ptr labeleditBox = tgui::Label::create();
	tgui::Label::Ptr colon = tgui::Label::create();




public:

	
	GUI(sf::RenderWindow* window);
	
	std::string getTextFromEditBox();

	void initGUI(sf::RenderWindow* window);
	void initCloseButton(sf::RenderWindow* window);
	void initStartButton();
	void initStopButton();
	void initEditBoxTime();
	void initLabelEditBox();
	void loadFont();

	void ClickedOnClose(sf::RenderWindow* window, sf::Event event);
	bool ClickedOnStart(sf::Event e, bool *startIsAllowed);
	bool ClickedOnStop(sf::Event e, bool *stopIsRequired);

	void close(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);

	void handleEvent(sf::Event event);


};
