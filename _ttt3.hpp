void introduction();

void take_turn();

bool playerWins(const std::string &position, Player player);

// char chooseCustomCharacter(Player player);
void chooseCustomCharacter(Player &player);

std::string set_position(std::string pos, Player player);

void update_board(int x_score, int o_score, std::string player_x, std::string player_o);

std::string change_player(int i);

void draw(const std::string &position);

bool end_game();

bool ask(const char *question);