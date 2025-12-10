# include <Siv3D.hpp> // Siv3D v0.6.14

void Main()
{
	int playerSelect = 0;
	int enemySelect = 0;
	Vec2 PosP = { 300,530 };
	Vec2 PosE = { 300,70 };
	Vec2 PosP1 = { 400,530 };
	Vec2 PosE1 = { 400,70 };
	Vec2 PosP2 = { 500,530 };
	Vec2 PosE2 = { 500,70 };
	Vec2 PosPs = { 300,530 };
	Vec2 PosEs = { 300,70 };

	
	int phase = 0;
	float timecounter = 0;
	while (System::Update())
	{
		
		Circle player{ PosP,35 };
		Circle enemy{ PosE,35 };
		Circle player1{ PosP1,35 };
		Circle enemy1{ PosE1,35 };
		Circle player2{ PosP2,35 };
		Circle enemy2{ PosE2,35 };
		Circle playerS{ PosPs,40 };
		Circle enemyS{ PosEs,40 };
		if (phase == 0) {
			playerS.draw(Palette::Red);
			player.draw();
			player1.draw();
			player2.draw();
		}

		if (phase == 2) {
			enemyS.draw(Palette::Red);
			enemy.draw();
			enemy1.draw();
			enemy2.draw();
		}

		PosPs.x = 300 + playerSelect * 100;
		PosEs.x = 300 + enemySelect * 100;
		if (phase == 0 || phase == 2) {
			timecounter += 1 * Scene::DeltaTime();
			if (timecounter <= 5) {
				phase = 0;
			}
			else {
				phase = 2;
			}
		}

		if (timecounter >= 10) {
			timecounter = timecounter - 10;
		}

		
		
		Print (playerSelect) ;
		if (phase == 0) {
			if (KeyA.down()) {
				playerSelect--;
				playerSelect %= 3;
				if (playerSelect < 0) {
					playerSelect += 3;
				}
			}
			if (KeyD.down()) {
				playerSelect++;
				playerSelect %= 3;
			}
			if (KeyEnter.down()) {
				phase = 1;
				timecounter = 5;
			}

		}
		if (phase == 1) {

		}

		if (phase == 2) {
			if (KeyA.down()) {
				enemySelect--;
				enemySelect %= 3;
				if (enemySelect < 0) {
					enemySelect += 3;
				}
			}
			if (KeyD.down()) {
				enemySelect++;
				enemySelect %= 3;
			}
			if (KeyEnter.down()) {
				timecounter = 10;
			}
		}
		
	}
}

