#pragma warning(disable : 4996)
#include <SFML/Graphics.hpp>
#include <iostream>
#include"map.h"
#include <time.h>

using namespace sf;
const int mount_of_bombs = 100;

void inMap(int a[h_map][w_map], const int hight, const int wight)
{
	for (int i = 0; i < hight; i++)
	{
		for (int j = 0; j < wight; j++)
		{
			a[i][j] = -1;
 		}

	}
}

void inSMap(int a[h_map][w_map], const int h_map, const int w_map)
{
	for (int i = 0; i < h_map; i++)
	{
		for (int j = 0; j < w_map; j++)
		{
			a[i][j] = 0;
		}
	}

	int rh = 0, rw = 0, counter = 0, counter2 = 0;

	while (counter < mount_of_bombs)
	{
		rh = 0; rw = 0;

		rh = 0 + rand() % h_map;
		rw = 0 + rand() % w_map;

		if (a[rh][rw] != 9)
		{
			a[rh][rw] = 9;
			counter++;
		}
		else
		{
			continue;
		}		
	}


	for (int i = 0; i < h_map; i++)
	{

		for (int j = 0; j < w_map; j++)
		{

			if (i == 0 && j == 0 && a[i][j] != 9) // Левый верхний угол
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = 0; r < 2; r++)
					{
						if (a[i + k][j + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (i == 0 && (j > 0 && j < w_map - 1) && a[i][j] != 9) //середина верх
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = -1; r < 2; r++)
					{
						if (a[i + k][j + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (i == 0 && j == w_map - 1 && a[i][j] != 9) 
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = -1; r < 1; r++)
					{
						if (a[i + k][j + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (j == 0 && (i > 0 && i < h_map - 1) && a[i][j] != 9) 
			{
				for (int k = 0; k < 3; k++)
				{
					for (int r = 0; r < 2; r++)
					{
						if (a[i - 1 + k][j + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (j == 0 && i == h_map - 1 && a[i][j] != 9)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = 0; r < 2; r++)
					{
						if (a[i - 1 + k][j + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (i == h_map - 1 && (j > 0 && j < w_map - 1) && a[i][j] != 9)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = 0; r < 3; r++)
					{
						if (a[i - 1 + k][j - 1 + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (j == w_map - 1 && i == h_map - 1 && a[i][j] != 9)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int r = 0; r < 2; r++)
					{
						if (a[i - 1 + k][j - 1 + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (j == w_map - 1 && (i > 0 && i < h_map - 1) && a[i][j] != 9) 
			{
				for (int k = 0; k < 3; k++)
				{
					for (int r = 0; r < 2; r++)
					{
						if (a[i - 1 + k][j - 1 + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


			if (a[i][j] != 9 && i != 0 && j != 0 && i != h_map - 1 && j != w_map - 1) 
			{
				for (int k = 0; k < 3; k++)
				{
					for (int r = 0; r < 3; r++)
					{
						if (a[i - 1 + k][j - 1 + r] == 9)
						{
							counter2++;
						}
					}

				}

				a[i][j] = counter2;
				counter2 = 0;
			}


		}
	}

}
void showMap(int a[h_map][w_map], const int h_map, const int w_map)
{
	int c = 0;
	for (int i = 0; i < h_map; i++)
	{
		for (int j = 0; j < w_map; j++)
		{
			if (a[i][j] == 9) c++;
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << c++;
}

class Block
{
public:  //// ??????
	Image map_image;
	Texture map_texture;
	Sprite map_sprite;

	Block(String path_to_file)
	{
		map_image.loadFromFile(path_to_file);
		map_texture.loadFromImage(map_image);
		map_sprite.setTexture(map_texture);
		map_sprite.setTextureRect(IntRect(0, 0, 29, 29));
	}

	Sprite getSprite()
	{
		return map_sprite;
	}
	
};



int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(790, 580), "Minesweeper");
	
	inMap(map, h_map, w_map);
	inSMap(smap, h_map, w_map);
	showMap(smap, h_map, w_map);

	Block white("imagine/white_field29.png"), gray("imagine/field29.png"), bomb("imagine/myBomb.png"), flag("imagine/flag.png"),
		one("imagine/one.png"),
		two("imagine/two.png"),
		three("imagine/three.png"),
		four("imagine/four.png"),
		five("imagine/five.png"),
		six("imagine/six.png"),
		seven("imagine/seven.png"),
		eight("imagine/eight.png");

	Image  frameImage, restartImage;
	
	frameImage.loadFromFile("imagine/frame.png");
	restartImage.loadFromFile("imagine/reset.png");
	Texture frameTexture,restartTexture;
	frameTexture.loadFromImage(frameImage);
	restartTexture.loadFromImage(restartImage);
	Sprite frameSprite,restartSprite;
	frameSprite.setTexture(frameTexture);
	restartSprite.setTexture(restartTexture);
	restartSprite.setPosition(715, 20);

	bool loss = false, showblocks = true;
	
	Font font;
	font.loadFromFile("font/font.ttf");
	Text text("", font, 20);
	text.setColor(Color::Red);
	text.setStyle(Text::Bold);

	int counterofreefields = 0;

	Vector2i pos;
	
	while (window.isOpen())
	{	
		pos = Mouse::getPosition(window);
		int x = pos.x/29;
		int y = pos.y/29;
		

		Event event;

		while (window.pollEvent(event))
		{
			/*std::cout << pos.x << " " << pos.y << std::endl;*/
			if (event.type == Event::Closed)
				window.close(); 
			if (event.type == Event::MouseButtonPressed)
			{
				if(IntRect(721, 28, 772,74).contains(Mouse::getPosition(window)))
				{
					inMap(map, h_map, w_map);
					inSMap(smap, h_map, w_map);
					showblocks = true;
					loss = false;
				}

				if (showblocks)
				{

					if (event.key.code == Mouse::Left)// инициализация map
					{
						if (smap[x][y] == 0 && map[x][y] != -2) { map[x][y] = 0;  }
						if (smap[x][y] == 1 && map[x][y] != -2) { map[x][y] = 1;  }
						if (smap[x][y] == 2 && map[x][y] != -2) { map[x][y] = 2;  }
						if (smap[x][y] == 3 && map[x][y] != -2) { map[x][y] = 3;  }
						if (smap[x][y] == 4 && map[x][y] != -2) { map[x][y] = 4;  }
						if (smap[x][y] == 5 && map[x][y] != -2) { map[x][y] = 5;  }
						if (smap[x][y] == 6 && map[x][y] != -2) { map[x][y] = 6;  }
						if (smap[x][y] == 7 && map[x][y] != -2) { map[x][y] = 7;  }
						if (smap[x][y] == 8 && map[x][y] != -2) { map[x][y] = 8;  }
						if (smap[x][y] == 9 && map[x][y] != -2)  loss = true;
					}

					if (event.key.code == Mouse::Right)//флажок
					{
						if (map[x][y] < 0)
						{
							if (map[x][y] == -2)
							{
								map[x][y] = -1;
							}

							else
							{
								map[x][y] = -2;
							}
						}

					}

				}
			}

		}
		
		
		window.clear();

		frameSprite.setPosition(694, 0);
		window.draw(frameSprite);
		window.draw(restartSprite);

		if (!loss)
		{
			for (int i = 0; i < h_map; i++)
			{
				for (int j = 0; j < w_map; j++)// создание поля
				{
					if (map[i][j] == -2) { flag.map_sprite.setPosition(i * 29, j * 29); window.draw(flag.getSprite());}
					if (map[i][j] == -1) { gray.map_sprite.setPosition(i * 29, j * 29); window.draw(gray.getSprite());}
					if (map[i][j] == 0) { white.map_sprite.setPosition(i * 29, j * 29); window.draw(white.getSprite());counterofreefields++;}
					if (map[i][j] == 1) { one.map_sprite.setPosition(i * 29, j * 29); window.draw(one.getSprite());counterofreefields++;}
					if (map[i][j] == 2) { two.map_sprite.setPosition(i * 29, j * 29); window.draw(two.getSprite());counterofreefields++;}
					if (map[i][j] == 3) { three.map_sprite.setPosition(i * 29, j * 29); window.draw(three.getSprite()); counterofreefields++; }
					if (map[i][j] == 4) { four.map_sprite.setPosition(i * 29, j * 29); window.draw(four.getSprite()); counterofreefields++;}
					if (map[i][j] == 5) { five.map_sprite.setPosition(i * 29, j * 29); window.draw(five.getSprite());counterofreefields++;}
					if (map[i][j] == 6) { six.map_sprite.setPosition(i * 29, j * 29); window.draw(six.getSprite());counterofreefields++;}
					if (map[i][j] == 7) { seven.map_sprite.setPosition(i * 29, j * 29); window.draw(seven.getSprite());counterofreefields++;}
					if (map[i][j] == 8) { eight.map_sprite.setPosition(i * 29, j * 29); window.draw(eight.getSprite());counterofreefields++; }
				}
			}

			if (counterofreefields == h_map * w_map - mount_of_bombs)
			{
				text.setString("You won");
				text.setPosition(700, 100);
				window.draw(text);
				showblocks = false;
			}
			counterofreefields = 0;
		}
		else
		{

			for (int i = 0; i < h_map; i++)
			{
				for (int j = 0; j < w_map; j++)// создание поля
				{
					if (map[i][j] == -2) { flag.map_sprite.setPosition(i * 29, j * 29); window.draw(flag.getSprite()); }
					if (map[i][j] == -1) { gray.map_sprite.setPosition(i * 29, j * 29); window.draw(gray.getSprite()); }
					if (map[i][j] == 0) { white.map_sprite.setPosition(i * 29, j * 29); window.draw(white.getSprite()); }
					if (map[i][j] == 1) { one.map_sprite.setPosition(i * 29, j * 29); window.draw(one.getSprite()); }
					if (map[i][j] == 2) { two.map_sprite.setPosition(i * 29, j * 29); window.draw(two.getSprite()); }
					if (map[i][j] == 3) { three.map_sprite.setPosition(i * 29, j * 29); window.draw(three.getSprite()); }
					if (map[i][j] == 4) { four.map_sprite.setPosition(i * 29, j * 29); window.draw(four.getSprite()); }
					if (map[i][j] == 5) { five.map_sprite.setPosition(i * 29, j * 29); window.draw(five.getSprite()); }
					if (map[i][j] == 6) { six.map_sprite.setPosition(i * 29, j * 29); window.draw(six.getSprite()); }
					if (map[i][j] == 7) { seven.map_sprite.setPosition(i * 29, j * 29); window.draw(seven.getSprite()); }
					if (map[i][j] == 8) { eight.map_sprite.setPosition(i * 29, j * 29); window.draw(eight.getSprite()); }
					if (smap[i][j] == 9) { bomb.map_sprite.setPosition(i * 29, j * 29); window.draw(bomb.getSprite()); }
				}
			}

			showblocks = false;

			text.setString("You loss");	
			text.setPosition(700, 100);
			window.draw(text);
		}

		window.display();
	}

	return 0;
}	