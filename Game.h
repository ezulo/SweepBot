struct Difficulty {
	int x;
	int y;
	int mines;
}

class Game {
	public:
		Game(Difficulty diff);
		~Game();
		int clickOnTile(int x_pos, int y_pos);
		void flagTile(int x_pos, int y_pos);
	private:
		int game_status;
		TileMatrix* game_matrix;
};
