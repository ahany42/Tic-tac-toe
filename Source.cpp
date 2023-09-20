#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;
struct Menu {
	Sprite spMainMenu;
	Sprite spgrid[9];
	Sprite oneplayergrid[9];
	Sprite spGrid;
	Sprite xwinscreen;
	Sprite owinscreen;
	Sprite drawscreen;
	Sprite youwonscreen;
	Sprite aiwonscreen;
	int xoindecation = 0;
	bool isgridempty[9];
	bool isx[9];
	bool iso[9];
	bool isxwin = false;
	bool isowin = false;
	bool isdraw = false;
	bool isstart = true;
	bool isgameend = false;
	int counter = 0;
	int screenindex = 0;
	Clock  time;
	int timer = 0;
};
struct Texs {
	Texture txmainmenu;
	Texture txx;
	Texture txo;
	Texture txaiwonscreen;
	Texture txyouwonscreen;
	Texture txgrid;
	Texture txxwinscreen;
	Texture txowinscreen;
	Texture txdrawscreen;
	Texture txblack;
	Texture txcomingsoon;
	Font score;
};

void fnreset(RenderWindow& window, Menu& resources, Texs& texture, Event& event);
void fn1player(RenderWindow& window, Menu& resources, Texs& texture, Event& event);
void GOcheck(RenderWindow& window, Event& event, Texs& texture, Menu& resources);
void fnmainmenu(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				exit(EXIT_SUCCESS);
			}
		}

		while (resources.screenindex == 0) {
			//1 Player
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i mousePos = Mouse::getPosition(window);
				if (mousePos.x > 782 && mousePos.x < 1174 && mousePos.y>517 && mousePos.y < 580 ) {
					resources.screenindex = 2;
					break;
					
				}	
					
			}
			window.draw(resources.spMainMenu);
			window.display();

			//2players button
			if (Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i mousePos = Mouse::getPosition(window);
				if (mousePos.x > 105 && mousePos.x < 501 && mousePos.y>512 && mousePos.y < 594)
				{
					resources.screenindex = 1;
					break;
					
				}
			}

		}
	
}

//2 players
void fngameloop(RenderWindow& window, Menu& resources, Texs& texture,Event& event) {
	 while (resources.screenindex == 1) {
		 while (window.pollEvent(event)) {
			 if (event.type == Event::Closed) {
				 window.close();
				 exit(EXIT_SUCCESS);
			 }
		 }
		 // to avoid double press
		 if (resources.time.getElapsedTime().asSeconds() >= 1) {
			 ++resources.timer;
			 resources.time.restart();
		 }

		 //Main menu button
		 Vector2i mousePos = Mouse::getPosition(window);
		 if (resources.isgameend == true) {
			 if (Mouse::isButtonPressed(Mouse::Left)) {
				 if (mousePos.x > 794 && mousePos.x < 1187 && mousePos.y>597  && mousePos.y < 677 )
				 {
					 resources.screenindex = 0;
					 break;

				 }
			 }
		 }
		if (Mouse::isButtonPressed(Mouse::Left)) {
			Vector2i mousePos = Mouse::getPosition(window);
			if (mousePos.x > 386 && mousePos.x < 569 && mousePos.y>99 && mousePos.y < 265  )
				//Grid 1
			{
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[0] == true )
				{
					resources.isstart = true;
					resources.spgrid[0].setPosition(410, 140);
					resources.spgrid[0].setScale(0.6, 0.6);
					resources.spgrid[0].setTexture(texture.txx);
					resources.isx[0] = true;
					resources.iso[0] = false;
					resources.isgridempty[0] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[0] == true)
				{
					resources.isstart = true;
					resources.spgrid[0].setPosition(420, 125);
					resources.spgrid[0].setScale(0.5, 0.5);
					resources.spgrid[0].setTexture(texture.txo);
					resources.isx[0] = false;
					resources.iso[0] = true;
					resources.isgridempty[0] = false;
					resources.xoindecation++;
				}
			}
			// Grid 2
			if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>99 && mousePos.y < 265 && resources.isgameend == false) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[1] == true)
				{
					resources.isstart = true;
					resources.spgrid[1].setPosition(590, 140);
					resources.spgrid[1].setScale(0.6, 0.6);
					resources.spgrid[1].setTexture(texture.txx);
					resources.isgridempty[1] = false;
					resources.isx[1] = true;
					resources.iso[1] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[1] == true)
				{
					resources.isstart = true;
					resources.spgrid[1].setPosition(605, 135);
					resources.spgrid[1].setScale(0.5, 0.5);
					resources.spgrid[1].setTexture(texture.txo);
					resources.isgridempty[1] = false;
					resources.isx[1] = false;
					resources.iso[1] = true;
					resources.xoindecation++;
				}
			}
			//Grid 3
			if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>99 && mousePos.y < 265 && resources.isgameend == false ) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[2] == true )
				{
					resources.isstart = true;
					resources.spgrid[2].setPosition(770, 140);
					resources.spgrid[2].setScale(0.6, 0.6);
					resources.spgrid[2].setTexture(texture.txx);
					resources.isx[2] = true;
					resources.iso[2] = false;
					resources.isgridempty[2] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[2] == true )
				{
					resources.isstart = true;
					resources.spgrid[2].setPosition(770, 130);
					resources.spgrid[2].setScale(0.5, 0.5);
					resources.spgrid[2].setTexture(texture.txo);
					resources.isx[2] = false;
					resources.iso[2] = true;
					resources.isgridempty[2] = false;
					resources.xoindecation++;
				}
			}
			//Grid 4
			if (mousePos.x > 386 && mousePos.x < 569 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[3] == true)
				{
					resources.isstart = true;
					resources.spgrid[3].setPosition(410, 310);
					resources.spgrid[3].setScale(0.6, 0.6);
					resources.spgrid[3].setTexture(texture.txx);
					resources.isx[3] = true;
					resources.iso[3] = false;
					resources.isgridempty[3] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[3] == true)
				{
					resources.isstart = true;
					resources.spgrid[3].setPosition(420, 300);
					resources.spgrid[3].setScale(0.5, 0.5);
					resources.spgrid[3].setTexture(texture.txo);
					resources.isx[3] = false;
					resources.iso[3] = true;
					resources.isgridempty[3] = false;
					resources.xoindecation++;
				}
			}
			//Grid 5
			if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[4] == true)
				{
					resources.isstart = true;
					resources.spgrid[4].setPosition(590, 310);
					resources.spgrid[4].setScale(0.6, 0.6);
					resources.spgrid[4].setTexture(texture.txx);
					resources.isx[4] = true;
					resources.iso[4] = false;
					resources.isgridempty[4] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[4] == true)
				{
					resources.isstart = true;
					resources.spgrid[4].setPosition(605, 300);
					resources.spgrid[4].setScale(0.5, 0.5);
					resources.spgrid[4].setTexture(texture.txo);
					resources.isx[4] = false;
					resources.iso[4] = true;
					resources.isgridempty[4] = false;
					resources.xoindecation++;
				}
			}
			//Grid 6
			if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false ) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[5] == true)
				{
					resources.isstart = true;
					resources.spgrid[5].setPosition(770, 310);
					resources.spgrid[5].setScale(0.6, 0.6);
					resources.spgrid[5].setTexture(texture.txx);
					resources.isx[5] = true;
					resources.iso[5] = false;
					resources.isgridempty[5] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[5] == true)
				{
					resources.isstart = true;
					resources.spgrid[5].setPosition(770, 300);
					resources.spgrid[5].setScale(0.5, 0.5);
					resources.spgrid[5].setTexture(texture.txo);
					resources.isx[5] = false;
					resources.iso[5] = true;
					resources.isgridempty[5] = false;
					resources.xoindecation++;
				}
			}
			//Grid 7
			if (mousePos.x > 386 && mousePos.x < 596 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false && resources.timer >= 2) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[6] == true)
				{
					resources.isstart = true;
					resources.spgrid[6].setPosition(410, 480);
					resources.spgrid[6].setScale(0.6, 0.6);
					resources.spgrid[6].setTexture(texture.txx);
					resources.isx[6] = true;
					resources.iso[6] = false;
					resources.isgridempty[6] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[6] == true)
				{
					resources.isstart = true;
					resources.spgrid[6].setPosition(420, 470);
					resources.spgrid[6].setScale(0.5, 0.5);
					resources.spgrid[6].setTexture(texture.txo);
					resources.isx[6] = false;
					resources.iso[6] = true;
					resources.isgridempty[6] = false;
					resources.xoindecation++;
				}
			}
			//Grid 8
			if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false ) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[7] == true)
				{
					resources.isstart = true;
					resources.spgrid[7].setPosition(590, 480);
					resources.spgrid[7].setScale(0.6, 0.6);
					resources.spgrid[7].setTexture(texture.txx);
					resources.isx[7] = true;
					resources.iso[7] = false;
					resources.isgridempty[7] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[7] == true)
				{
					resources.isstart = true;
					resources.spgrid[7].setPosition(605, 470);
					resources.spgrid[7].setScale(0.5, 0.5);
					resources.spgrid[7].setTexture(texture.txo);
					resources.isx[7] = false;
					resources.iso[7] = true;
					resources.isgridempty[7] = false;
					resources.xoindecation++;
				}
			}
			//Grid 9
			if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false) {
				if (resources.xoindecation % 2 == 0 && resources.isgridempty[8] == true)
				{
					resources.isstart = true;
					resources.spgrid[8].setPosition(770, 480);
					resources.spgrid[8].setScale(0.6, 0.6);
					resources.spgrid[8].setTexture(texture.txx);
					resources.isx[8] = true;
					resources.iso[8] = false;
					resources.isgridempty[8] = false;
					resources.xoindecation++;

				}
				else if (resources.xoindecation % 2 != 0 && resources.isgridempty[8] == true)
				{
					resources.isstart = true;
					resources.spgrid[8].setPosition(770, 470);
					resources.spgrid[8].setScale(0.5, 0.5);
					resources.spgrid[8].setTexture(texture.txo);
					resources.isx[8] = false;
					resources.iso[8] = true;
					resources.isgridempty[8] = false;
					resources.xoindecation++;
				}
			}
		}
		GOcheck(window, event, texture, resources);
		window.clear();
		if (resources.isdraw == true)
			window.draw(resources.drawscreen);
		if (resources.isxwin == true)
			window.draw(resources.xwinscreen);
		if (resources.isowin == true)
			window.draw(resources.owinscreen);
		window.draw(resources.spGrid);
		if (resources.isstart == true)
			for (int i = 0; i < 9; i++)
			{
				window.draw(resources.spgrid[i]);

			}
		if (resources.isdraw == true  || resources.isxwin == true || resources.isowin == true)
		{
			fnreset(window, resources, texture, event);
			resources.isgameend = true;
			
		}
		window.display();
	}
}
void GOcheck(RenderWindow& window, Event& event, Texs& texture, Menu& resources) {
	// X win
	if (resources.isx[0] == true && resources.isx[3] == true && resources.isx[6] == true)
		resources.isxwin = true;
	else if (resources.isx[0] == true && resources.isx[1] == true && resources.isx[2] == true)
		resources.isxwin = true;
	else if (resources.isx[0] == true && resources.isx[4] == true && resources.isx[8] == true)
		resources.isxwin = true;
	else if (resources.isx[1] == true && resources.isx[4] == true && resources.isx[7] == true)
		resources.isxwin = true;
	else if (resources.isx[2] == true && resources.isx[4] == true && resources.isx[6] == true)
		resources.isxwin = true;
	else if (resources.isx[2] == true && resources.isx[5] == true && resources.isx[8] == true)
		resources.isxwin = true;
	else if (resources.isx[3] == true && resources.isx[4] == true && resources.isx[5] == true)
		resources.isxwin = true;
	else if (resources.isx[6] == true && resources.isx[7] == true && resources.isx[8] == true)
		resources.isxwin = true;
	// O win
	else if (resources.iso[0] == true && resources.iso[3] == true && resources.iso[6] == true)
		resources.isowin = true;
	else if (resources.iso[0] == true && resources.iso[1] == true && resources.iso[2] == true)
		resources.isowin = true;
	else if (resources.iso[0] == true && resources.iso[4] == true && resources.iso[8] == true)
		resources.isowin = true;
	else if (resources.iso[1] == true && resources.iso[4] == true && resources.iso[7] == true)
		resources.isowin = true;
	else if (resources.iso[2] == true && resources.iso[4] == true && resources.iso[6] == true)
		resources.isowin = true;
	else if (resources.iso[2] == true && resources.iso[5] == true && resources.iso[8] == true)
		resources.isowin = true;
	else if (resources.iso[3] == true && resources.iso[4] == true && resources.iso[5] == true)
		resources.isowin = true;
	else if (resources.iso[6] == true && resources.iso[7] == true && resources.iso[8] == true)
		resources.isowin = true;
	else if (resources.xoindecation == 9)
		resources.isdraw = true;
}
int main() {
	Menu resources;
	Texs texture;
	for (int i = 0; i < 9; i++)
		resources.isgridempty[i] = true;
	texture.txxwinscreen.loadFromFile("x win.png");
	texture.txowinscreen.loadFromFile("o win.png");
	texture.txdrawscreen.loadFromFile("Draw.png");
	texture.txcomingsoon.loadFromFile("coming soon.png");
	resources.xwinscreen.setTexture(texture.txxwinscreen);
	resources.owinscreen.setTexture(texture.txowinscreen);
	resources.drawscreen.setTexture(texture.txdrawscreen);
	texture.txx.loadFromFile("x-removebg-preview.png");
	texture.txo.loadFromFile("download-removebg-preview.png");
	texture.txmainmenu.loadFromFile("Main menu.png");
	resources.spMainMenu.setTexture(texture.txmainmenu);
	resources.spMainMenu.setOrigin(0, 0);
	resources.spMainMenu.setScale(1, 1);
	texture.txgrid.loadFromFile("xoGrid-removebg-preview.png");
	resources.spGrid.setTexture(texture.txgrid);
	resources.spGrid.setPosition(400, 100);
	resources.spGrid.setScale(4, 4);
	texture.txaiwonscreen.loadFromFile("1player Ai win.png");
	resources.aiwonscreen.setTexture(texture.txaiwonscreen);
	texture.txyouwonscreen.loadFromFile("1player you won.png");
	resources.youwonscreen.setTexture(texture.txyouwonscreen);
	RenderWindow window(VideoMode(1280, 720), "Tic Tac Toe");
	Event event;
	
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		if (resources.screenindex == 0)
			//Main menu
			fnmainmenu(window, resources, texture, event);
		else if (resources.screenindex == 1)
			//Game loop
		{
			
			fngameloop(window, resources, texture, event);
		}
		else if (resources.screenindex == 2)
			fn1player(window, resources, texture, event);
	
	}
	return 0;
}

void fnreset1p(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	Vector2i mousePos = Mouse::getPosition(window);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (mousePos.x > 120 && mousePos.x < 511 && mousePos.y>604 && mousePos.y < 678 ) {
			window.close();
			main();


		}

	}
}
// 1 player
void move1_1p(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	if (resources.xoindecation == 1 && resources.isgameend==false) {

		//First move
		if (resources.isgridempty[4] == true)
		{
			resources.spgrid[4].setTexture(texture.txo);
			resources.spgrid[4].setPosition(605, 300);
			resources.spgrid[4].setScale(0.5, 0.5);
			resources.isgridempty[4] = false;
			resources.isx[4] = false;
			resources.iso[4] = true;
			resources.xoindecation++;

		}
		
		else 
			{
			resources.spgrid[0].setTexture(texture.txo);
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.isgridempty[4] = false;
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.xoindecation++;
			resources.isstart = true;


		}
	}
	
}
void move2_1p(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	if (resources.xoindecation == 3 && resources.isgameend == false) {
		if (resources.iso[4] == true)
		{
			if (resources.isx[1] == true && resources.isx[2] == true )
			{
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
				
			}
			else if(resources.isx[3] == true && resources.isx[6] == true)
			{
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[0] == true && resources.isx[2] == true)
			{
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;
				
			}
			else if (resources.isx[0] == true && resources.isx[1] == true ) 
			{
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[5] == true && resources.isx[8] == true) {
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
				
			}

			else if (resources.isx[0] == true && resources.isx[6]==true)
			{
				
				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[2] == true && resources.isx[8]==true)
			{
				
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[0] == true && resources.isx[3]==true) 
			
			{
				
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
			else if(resources.isx[7] == true && resources.isx[8])
			{
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[6] == true && resources.isx[8] == true)
			{
				//Draw [7]
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[5] == true && resources.isx[2] == true)
			{
				//Draw [8]
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[1] == true && resources.isx[6] == true) {
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[0] == true && resources.isx[8] == true) {
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isgridempty[0] == true)
			{
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;

			}
			else if (resources.isgridempty[2] == true)
			{
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;

			}
			else if (resources.isgridempty[6] == true)
			{
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
		}
		else if (resources.isx[4] == true)
		{
			if (resources.isx[1] == true)
			{
				//Draw [7]
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[4] == true && resources.isx[8] == true)
			{
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			
			else if (resources.isx[2] == true) {
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[3] == true) {
				//Draw [5]
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[5] == true) {
				//Draw [3]
				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
				
			}
			else if (resources.isx[6] == true) {
				//Draw [2]
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[7] == true) {
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;

			}
			else if (resources.isx[8] == true) {
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;

			}

			else if (resources.isgridempty[2] == true) {
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[6] == true) {
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				
			}
		}
	}
}
void move3_1p(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	if(resources.xoindecation==5 && resources.isgameend == false){
		if (resources.iso[4] == true) {
			//Wining
			if (resources.iso[7] == true && resources.isgridempty[1] == true)
			{
				//Draw 1
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;

			}
			else if (resources.iso[6] == true && resources.isgridempty[2] == true)
			{
				//Draw 2
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.iso[5] == true && resources.isgridempty[3] == true)
			{
				//Draw 3
				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
			}
			else if (resources.iso[3] == true && resources.isgridempty[5] == true)
			{
				//Draw 5
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
			}
			else if (resources.iso[2] == true && resources.isgridempty[6] == true)
			{
				
				//Draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.iso[1] == true && resources.isgridempty[7] == true)
			{
				//Draw 7
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;

			}
			else if (resources.iso[0] == true && resources.isgridempty[8] == true)
			{
				//Draw 8
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}
			
			// Not losing
			else if (resources.isx[6] == true && resources.isx[3] == true && resources.isgridempty[0] == true)
			{
				//draw 0
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[1] == true && resources.isx[2] == true && resources.isgridempty[0] == true)
			{
				//draw 0
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[0] == true && resources.isx[2] == true && resources.isgridempty[1] == true)
			{
				//draw 1
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;
			}
			else if (resources.isx[0] == true && resources.isx[1] == true && resources.isgridempty[2] == true)
			{
				//draw 2
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[5] == true && resources.isx[8] == true && resources.isgridempty[2] == true)
			{
				//draw 2
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[6] == true && resources.isx[0] == true && resources.isgridempty[3] == true)
			{
				//draw 3
				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[2] == true && resources.isx[8] == true && resources.isgridempty[5] == true)
			{
				//draw 5
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
			}

			else if (resources.isx[7] == true && resources.isx[8] == true && resources.isgridempty[6] == true)
			{
				//draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[0] == true && resources.isx[3] == true && resources.isgridempty[6] == true)
			{
				//draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[6] == true && resources.isx[8] == true && resources.isgridempty[7] == true)
			{
				//draw 7
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
			}

			else if (resources.isx[7] == true && resources.isx[6] == true && resources.isgridempty[8] == true)
			{
				//draw 8
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}

			else if (resources.isx[5] == true && resources.isx[2] == true && resources.isgridempty[8] == true)
			{
				//draw 8
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}
			//corners
			else if (resources.isgridempty[0]==true)
			{
				//draw 0
				resources.isstart = true;
				resources.spgrid[0].setPosition(420, 125);
				resources.spgrid[0].setScale(0.5, 0.5);
				resources.spgrid[0].setTexture(texture.txo);
				resources.isx[0] = false;
				resources.iso[0] = true;
				resources.isgridempty[0] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[1]==true)
			{
				//draw 1
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[6]==true)
			{
				//draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[8]==true)
			{
				//draw 8
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}	
			
		}
		else if (resources.isx[4] == true)
		{
			if (resources.isgridempty[1] == true && resources.iso[0] == true && resources.iso[2] == true) {
				//Draw [1]

				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;
			}
			

			else if (resources.isgridempty[2] == true && resources.iso[5] == true && resources.iso[8] == true) {
				//Draw [2]
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[2] == true && resources.iso[0] == true && resources.iso[1] == true) {
				//Draw [2]

				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}

			else if (resources.isgridempty[3] == true && resources.iso[0] == true && resources.iso[6] == true) {
				//Draw [3]

				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[5] == true && resources.iso[2] == true && resources.iso[8] == true) {
				//Draw [5]
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[5] == true && resources.iso[3] == true && resources.iso[4] == true) {
				//Draw [5]
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[6] == true && resources.iso[3] == true && resources.iso[0] == true) {
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[6] == true && resources.iso[7] == true && resources.iso[8] == true) {
				//Draw [6]
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}


			else if (resources.isgridempty[7] == true && resources.iso[6] == true && resources.iso[8] == true) {
				//Draw [7]
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
			}

			else if (resources.isgridempty[8] == true && resources.iso[2] == true && resources.iso[5] == true) {
				//Draw [8]
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[8] == true && resources.iso[7] == true && resources.iso[8] == true) {
				//Draw [8]
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}
			//Not losing
			else if (resources.isx[6] == true && resources.isgridempty[2] == true) {
				//draw 2
				resources.isstart = true;
				resources.spgrid[2].setPosition(770, 130);
				resources.spgrid[2].setScale(0.5, 0.5);
				resources.spgrid[2].setTexture(texture.txo);
				resources.isx[2] = false;
				resources.iso[2] = true;
				resources.isgridempty[2] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[2] == true && resources.isgridempty[6] == true) {
				//draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[7] == true && resources.isgridempty[1] == true) {
				//draw 1
				resources.isstart = true;
				resources.spgrid[1].setPosition(605, 135);
				resources.spgrid[1].setScale(0.5, 0.5);
				resources.spgrid[1].setTexture(texture.txo);
				resources.isgridempty[1] = false;
				resources.isx[1] = false;
				resources.iso[1] = true;
				resources.xoindecation++;
			}

			else if (resources.isx[5] == true && resources.isgridempty[3] == true) {
				//draw 3
				resources.isstart = true;
				resources.spgrid[3].setPosition(420, 300);
				resources.spgrid[3].setScale(0.5, 0.5);
				resources.spgrid[3].setTexture(texture.txo);
				resources.isx[3] = false;
				resources.iso[3] = true;
				resources.isgridempty[3] = false;
				resources.xoindecation++;
			}
			else if (resources.isx[3] == true && resources.isgridempty[5] == true) {
				//draw 5
				resources.isstart = true;
				resources.spgrid[5].setPosition(770, 300);
				resources.spgrid[5].setScale(0.5, 0.5);
				resources.spgrid[5].setTexture(texture.txo);
				resources.isx[5] = false;
				resources.iso[5] = true;
				resources.isgridempty[5] = false;
				resources.xoindecation++;
			}

			else if (resources.isx[1] == true && resources.isgridempty[7] == true) {
				//draw 7
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
			}

			else if (resources.isx[2] == true && resources.isgridempty[8] == true) {
				//draw 8
				
				resources.isstart = true;
				resources.spgrid[8].setPosition(770, 470);
				resources.spgrid[8].setScale(0.5, 0.5);
				resources.spgrid[8].setTexture(texture.txo);
				resources.isx[8] = false;
				resources.iso[8] = true;
				resources.isgridempty[8] = false;
				resources.xoindecation++;
			}
			else if (resources.isgridempty[6] == true)
			{
				
				//draw 6
				resources.isstart = true;
				resources.spgrid[6].setPosition(420, 470);
				resources.spgrid[6].setScale(0.5, 0.5);
				resources.spgrid[6].setTexture(texture.txo);
				resources.isx[6] = false;
				resources.iso[6] = true;
				resources.isgridempty[6] = false;
				resources.xoindecation++;
				}
			

		}

	}
}
void move4_1p(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	while (resources.xoindecation==7 ) {
		//wining
		if (resources.isgridempty[0] == true && resources.iso[1] == true && resources.iso[2] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;

		}
		else if (resources.isgridempty[0] == true && resources.iso[4] == true && resources.iso[8] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;

		}
		else  if (resources.isgridempty[0] == true && resources.iso[3] == true && resources.iso[6] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[1] == true && resources.iso[4] == true && resources.iso[7] == true) {
			//Draw [1]
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[1] == true && resources.iso[0] == true && resources.iso[2] == true) {
			//Draw [1]
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true && resources.iso[4] == true && resources.iso[6] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true && resources.iso[5] == true && resources.iso[8] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true && resources.iso[0] == true && resources.iso[1] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[3] == true && resources.iso[4] == true && resources.iso[5] == true) {
			//Draw [3]
			resources.isstart = true;
			resources.spgrid[3].setPosition(420, 300);
			resources.spgrid[3].setScale(0.5, 0.5);
			resources.spgrid[3].setTexture(texture.txo);
			resources.isx[3] = false;
			resources.iso[3] = true;
			resources.isgridempty[3] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[3] == true && resources.iso[0] == true && resources.iso[6] == true) {
			//Draw [3]
			resources.isstart = true;
			resources.spgrid[3].setPosition(420, 300);
			resources.spgrid[3].setScale(0.5, 0.5);
			resources.spgrid[3].setTexture(texture.txo);
			resources.isx[3] = false;
			resources.iso[3] = true;
			resources.isgridempty[3] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[5] == true && resources.iso[2] == true && resources.iso[8] == true) {
			//Draw [5]
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[5] == true && resources.iso[3] == true && resources.iso[4] == true) {
			//Draw [5]
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.iso[3] == true && resources.iso[0] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.iso[7] == true && resources.iso[8] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.iso[4] == true && resources.iso[2] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[7] == true && resources.iso[4] == true && resources.iso[1] == true) {
			//Draw [7]
			resources.isstart = true;
			resources.spgrid[7].setPosition(605, 470);
			resources.spgrid[7].setScale(0.5, 0.5);
			resources.spgrid[7].setTexture(texture.txo);
			resources.isx[7] = false;
			resources.iso[7] = true;
			resources.isgridempty[7] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[7] == true && resources.iso[6] == true && resources.iso[8] == true) {
			//Draw [7]
			resources.isstart = true;
			resources.spgrid[7].setPosition(605, 470);
			resources.spgrid[7].setScale(0.5, 0.5);
			resources.spgrid[7].setTexture(texture.txo);
			resources.isx[7] = false;
			resources.iso[7] = true;
			resources.isgridempty[7] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.iso[4] == true && resources.iso[0] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.iso[2] == true && resources.iso[5] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.iso[7] == true && resources.iso[8] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		//Not losing
		else if (resources.isx[4] == true && resources.isx[6] == true && resources.isgridempty[8] == true)
		{
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
			}
		else if (resources.isx[4] == true && resources.isx[3] == true && resources.isgridempty[5] == true)
		{
			//Draw [5]
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
			}
		else if (resources.isx[4] == true && resources.isx[1] == true && resources.isgridempty[7] == true)
		{
			
				//Draw [7]
				resources.isstart = true;
				resources.spgrid[7].setPosition(605, 470);
				resources.spgrid[7].setScale(0.5, 0.5);
				resources.spgrid[7].setTexture(texture.txo);
				resources.isx[7] = false;
				resources.iso[7] = true;
				resources.isgridempty[7] = false;
				resources.xoindecation++;
				break;
			
			}
		else if (resources.isx[4] == true && resources.isx[2] == true && resources.isgridempty[6] == true)
		{
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;


			}
		else if (resources.isx[4] == true && resources.isx[0] == true && resources.isgridempty[8] == true)
		{
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;

			}
		else if (resources.isx[4] == true && resources.isx[7] == true && resources.isgridempty[1] == true)
		{
			
			//Draw [1]
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;

			}
	
	
		else if (resources.isgridempty[0] == true && resources.isx[1] == true && resources.isx[2] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[0] == true && resources.isx[4] == true && resources.isx[8] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[0] == true && resources.isx[3] == true && resources.isx[6] == true) {
			//Draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[1] == true && resources.isx[4] == true && resources.isx[7] == true) {
			//Draw [1]
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[1] == true && resources.isx[0] == true && resources.isx[2] == true) {
			//Draw [1]
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;

		}
		else if (resources.isgridempty[2] == true && resources.isx[4] == true && resources.isx[6] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true && resources.isx[5] == true && resources.isx[8] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true && resources.isx[0] == true && resources.isx[1] == true) {
			//Draw [2]
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[3] == true && resources.isx[4] == true && resources.isx[5] == true) {
			//Draw [3]
			resources.isstart = true;
			resources.spgrid[3].setPosition(420, 300);
			resources.spgrid[3].setScale(0.5, 0.5);
			resources.spgrid[3].setTexture(texture.txo);
			resources.isx[3] = false;
			resources.iso[3] = true;
			resources.isgridempty[3] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[3] == true && resources.isx[0] == true && resources.isx[6] == true) {
			//Draw [3]
			resources.isstart = true;
			resources.spgrid[3].setPosition(420, 300);
			resources.spgrid[3].setScale(0.5, 0.5);
			resources.spgrid[3].setTexture(texture.txo);
			resources.isx[3] = false;
			resources.iso[3] = true;
			resources.isgridempty[3] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[5] == true && resources.isx[2] == true && resources.isx[8] == true) {
			//Draw [5]
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[5] == true && resources.isx[3] == true && resources.isx[4] == true) {
			//Draw [5]
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.isx[3] == true && resources.isx[0] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.isx[7] == true && resources.isx[8] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true && resources.isx[4] == true && resources.isx[2] == true) {
			//Draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[7] == true && resources.isx[4] == true && resources.isx[1] == true) {
			//Draw [7]
			resources.isstart = true;
			resources.spgrid[7].setPosition(605, 470);
			resources.spgrid[7].setScale(0.5, 0.5);
			resources.spgrid[7].setTexture(texture.txo);
			resources.isx[7] = false;
			resources.iso[7] = true;
			resources.isgridempty[7] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[7] == true && resources.isx[6] == true && resources.isx[8] == true) {
			//Draw [7]
			resources.isstart = true;
			resources.spgrid[7].setPosition(605, 470);
			resources.spgrid[7].setScale(0.5, 0.5);
			resources.spgrid[7].setTexture(texture.txo);
			resources.isx[7] = false;
			resources.iso[7] = true;
			resources.isgridempty[7] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.isx[4] == true && resources.isx[0] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.isx[2] == true && resources.isx[5] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true && resources.isx[7] == true && resources.isx[8] == true) {
			//Draw [8]
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[0] == true) {
			//draw [0]
			resources.isstart = true;
			resources.spgrid[0].setPosition(420, 125);
			resources.spgrid[0].setScale(0.5, 0.5);
			resources.spgrid[0].setTexture(texture.txo);
			resources.isx[0] = false;
			resources.iso[0] = true;
			resources.isgridempty[0] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[1] == true) {
			//draw [1]
			
			resources.isstart = true;
			resources.spgrid[1].setPosition(605, 135);
			resources.spgrid[1].setScale(0.5, 0.5);
			resources.spgrid[1].setTexture(texture.txo);
			resources.isgridempty[1] = false;
			resources.isx[1] = false;
			resources.iso[1] = true;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[2] == true) {
			//draw [2]
			
			resources.isstart = true;
			resources.spgrid[2].setPosition(770, 130);
			resources.spgrid[2].setScale(0.5, 0.5);
			resources.spgrid[2].setTexture(texture.txo);
			resources.isx[2] = false;
			resources.iso[2] = true;
			resources.isgridempty[2] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[3] == true) {
			//draw [3]
			
			resources.isstart = true;
			resources.spgrid[3].setPosition(420, 300);
			resources.spgrid[3].setScale(0.5, 0.5);
			resources.spgrid[3].setTexture(texture.txo);
			resources.isx[3] = false;
			resources.iso[3] = true;
			resources.isgridempty[3] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[5] == true) {
			//draw [5]
			
			resources.isstart = true;
			resources.spgrid[5].setPosition(770, 300);
			resources.spgrid[5].setScale(0.5, 0.5);
			resources.spgrid[5].setTexture(texture.txo);
			resources.isx[5] = false;
			resources.iso[5] = true;
			resources.isgridempty[5] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[6] == true) {
			//draw [6]
			resources.isstart = true;
			resources.spgrid[6].setPosition(420, 470);
			resources.spgrid[6].setScale(0.5, 0.5);
			resources.spgrid[6].setTexture(texture.txo);
			resources.isx[6] = false;
			resources.iso[6] = true;
			resources.isgridempty[6] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[7] == true) {
			//draw [7]
			
			resources.isstart = true;
			resources.spgrid[7].setPosition(605, 470);
			resources.spgrid[7].setScale(0.5, 0.5);
			resources.spgrid[7].setTexture(texture.txo);
			resources.isx[7] = false;
			resources.iso[7] = true;
			resources.isgridempty[7] = false;
			resources.xoindecation++;
			break;
		}
		else if (resources.isgridempty[8] == true) {
			//draw [8]
			
			resources.isstart = true;
			resources.spgrid[8].setPosition(770, 470);
			resources.spgrid[8].setScale(0.5, 0.5);
			resources.spgrid[8].setTexture(texture.txo);
			resources.isx[8] = false;
			resources.iso[8] = true;
			resources.isgridempty[8] = false;
			resources.xoindecation++;
			break;
		}
		
	}	
}

void fn1player(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	
	while (resources.screenindex == 2 && resources.isgameend==false) {
		cout << resources.xoindecation << endl;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
				exit(EXIT_SUCCESS);
			}
		}

		//Main menu button
		Vector2i mousePos = Mouse::getPosition(window);
		if (resources.isgameend == true) {
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (mousePos.x > 794 && mousePos.x < 1187 && mousePos.y>597 && mousePos.y < 677)
				{
					resources.screenindex = 0;
					break;

				}
			}
		}


		if (resources.isgameend == false) {
			if (resources.xoindecation == 1)
			{
				move1_1p(window, resources, texture, event);
			}
			 if (resources.xoindecation == 3)
			{
				move2_1p(window, resources, texture, event);
			}
			 if (resources.xoindecation == 5)
			{
				move3_1p(window, resources, texture, event);
			}
			
			 if (resources.xoindecation == 7 )
			{
				move4_1p(window, resources, texture, event);
			}
			 GOcheck(window, event, texture, resources);
			 //bug handeling
			/* if (resources.xoindecation == 8)
			 {
				 if(resources.isgridempty[0]==true)
				 resources.counter++;
				 if (resources.isgridempty[1] == true)
					 resources.counter++;
				 if (resources.isgridempty[2] == true)
					 resources.counter++;
				 if (resources.isgridempty[3] == true)
					 resources.counter++;
				 if (resources.isgridempty[4] == true)
					 resources.counter++;
				 if (resources.isgridempty[5] == true)
					 resources.counter++;
				 if (resources.isgridempty[6] == true)
					 resources.counter++;
				 if (resources.isgridempty[7] == true)
					 resources.counter++;
				 if (resources.isgridempty[8] == true)
					 resources.counter++;
				 if (resources.counter == 2)
					 resources.xoindecation--;
		}*/
			 
			 
				

			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (mousePos.x > 386 && mousePos.x < 569 && mousePos.y>99 && mousePos.y < 265)
					//Grid 1
				{
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[0] == true)
					{

						resources.isstart = true;
						resources.spgrid[0].setPosition(410, 140);
						resources.spgrid[0].setScale(0.6, 0.6);
						resources.spgrid[0].setTexture(texture.txx);
						resources.isx[0] = true;
						resources.iso[0] = false;
						resources.isgridempty[0] = false;
						resources.xoindecation++;

					}
				}
				// Grid 2
				if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>99 && mousePos.y < 265 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[1] == true)
					{

						resources.isstart = true;
						resources.spgrid[1].setPosition(590, 140);
						resources.spgrid[1].setScale(0.6, 0.6);
						resources.spgrid[1].setTexture(texture.txx);
						resources.isgridempty[1] = false;
						resources.isx[1] = true;
						resources.iso[1] = false;
						resources.xoindecation++;

					}

				}
				//Grid 3
				if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>99 && mousePos.y < 265 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[2] == true)
					{

						resources.isstart = true;
						resources.spgrid[2].setPosition(770, 140);
						resources.spgrid[2].setScale(0.6, 0.6);
						resources.spgrid[2].setTexture(texture.txx);
						resources.isx[2] = true;
						resources.iso[2] = false;
						resources.isgridempty[2] = false;
						resources.xoindecation++;
					}

				}
				//Grid 4
				if (mousePos.x > 386 && mousePos.x < 569 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[3] == true)
					{

						resources.isstart = true;
						resources.spgrid[3].setPosition(410, 310);
						resources.spgrid[3].setScale(0.6, 0.6);
						resources.spgrid[3].setTexture(texture.txx);
						resources.isx[3] = true;
						resources.iso[3] = false;
						resources.isgridempty[3] = false;
						resources.xoindecation++;
					}

				}

				//Grid 5
				if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[4] == true)
					{

						resources.isstart = true;
						resources.spgrid[4].setPosition(590, 310);
						resources.spgrid[4].setScale(0.6, 0.6);
						resources.spgrid[4].setTexture(texture.txx);
						resources.isx[4] = true;
						resources.iso[4] = false;
						resources.isgridempty[4] = false;
						resources.xoindecation++;
					}

				}
				//Grid 6
				if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>265 && mousePos.y < 436 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[5] == true)
					{

						resources.isstart = true;
						resources.spgrid[5].setPosition(770, 310);
						resources.spgrid[5].setScale(0.6, 0.6);
						resources.spgrid[5].setTexture(texture.txx);
						resources.isx[5] = true;
						resources.iso[5] = false;
						resources.isgridempty[5] = false;
						resources.xoindecation++;
					}

				}
				//Grid 7
				if (mousePos.x > 386 && mousePos.x < 596 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[6] == true)
					{

						resources.isstart = true;
						resources.spgrid[6].setPosition(410, 480);
						resources.spgrid[6].setScale(0.6, 0.6);
						resources.spgrid[6].setTexture(texture.txx);
						resources.isx[6] = true;
						resources.iso[6] = false;
						resources.isgridempty[6] = false;
						resources.xoindecation++;

					}

				}
				//Grid 8
				if (mousePos.x > 600 && mousePos.x < 728 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[7] == true)
					{

						resources.isstart = true;
						resources.spgrid[7].setPosition(590, 480);
						resources.spgrid[7].setScale(0.6, 0.6);
						resources.spgrid[7].setTexture(texture.txx);
						resources.isx[7] = true;
						resources.iso[7] = false;
						resources.isgridempty[7] = false;
						resources.xoindecation++;

					}

				}
				//Grid 9
				if (mousePos.x > 757 && mousePos.x < 915 && mousePos.y>457 && mousePos.y < 621 && resources.isgameend == false) {
					if (resources.xoindecation % 2 == 0 && resources.isgridempty[8] == true)
					{

						resources.isstart = true;
						resources.spgrid[8].setPosition(770, 480);
						resources.spgrid[8].setScale(0.6, 0.6);
						resources.spgrid[8].setTexture(texture.txx);
						resources.isx[8] = true;
						resources.iso[8] = false;
						resources.isgridempty[8] = false;
						resources.xoindecation++;

					}
				}
			}
			window.clear();
			if (resources.isdraw == true)
				window.draw(resources.drawscreen);
			if (resources.isxwin == true)
				window.draw(resources.youwonscreen);
			if (resources.isowin == true)
				window.draw(resources.aiwonscreen);
			if (resources.isdraw == true || resources.isxwin == true || resources.isowin == true)
			{

				resources.isgameend = true;
				fnreset(window, resources, texture, event);

			}
			for (int i = 0; i < 9; i++)
				window.draw(resources.spgrid[i]);
			
			window.draw(resources.spGrid);
			
			window.display();
		}
	
	}
}
void fnreset(RenderWindow& window, Menu& resources, Texs& texture, Event& event) {
	Vector2i mousePos = Mouse::getPosition(window);

	if (Mouse::isButtonPressed(Mouse::Left)) {
		if (mousePos.x > 120 && mousePos.x < 511 && mousePos.y>604 && mousePos.y < 678 && resources.timer >= 1) {
			window.close();
			main();


		}

	}
}
