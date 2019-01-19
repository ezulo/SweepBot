struct Difficulty {
	int x;
	int y;
	int mines;
}

class Game {
	public:
		Game(Difficulty diff);
		~Game();
		void clickOnTile(int x_pos, int y_pos);
		void markTile(int x_pos, int y_pos);
	private:
		boolean[2] game_status;
		int** game_matrix;
		bool** reveal_matrix;
};
