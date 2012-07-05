int run_game()
{
	int shot_val,
		current_player_index = 0,
		shot_x,
		shot_y,
		winner_index = -1;

		while(winner_index = -1) {
			print_friendly();
			print_enemy();
			read_coords();
			shot_val = shot();
			if(shot_val == 0)
				// смена игрока
			else if (shot_val == 1)
				winner_index = check_winner();
			else continue;
			print_friendly();
			print_enemy();
		}
			//вывод победителя
	return 0;
}
