#include <iostream>
#include <string>
using namespace std;
class LinkedList {

	char result_arr[3][3];
	char player;
	bool first_time = true;

	struct Node
	{
		char subarray[3][3];
		Node*next;
	};

	Node*head;
	Node*last;
	Node*node_four;
	Node*node_seven;

public:
	LinkedList() {
		head = NULL;
	}

	int X(int pos) {
		return pos / 3;
	}

	int Y(int pos) {
		return pos % 3 - 1;
	}

	void filling_board() {
		int number_of_nodes = 0;
		for (int cur_node = 1; cur_node <= 9; ++cur_node)
		{
			Node* newnode = new Node();

			if (cur_node == 4)
			{
				node_four = newnode;
			}
			if (cur_node == 7)
			{
				node_seven = newnode;
			}
			for (int sm_row = 0; sm_row < 3; ++sm_row)
			{
				for (int sm_col = 0; sm_col < 3; ++sm_col)
				{
					newnode->subarray[sm_row][sm_col] = '.';
				}


			}

			if (number_of_nodes == 0)
			{
				head = last = newnode;
				newnode->next = NULL;
			}
			else
			{
				last->next = newnode;
				newnode->next = NULL;
				last = newnode;
			}

			number_of_nodes++;


		}

		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				result_arr[row][col] = '.';
			}

		}
		player = 'x';
	}

	void print_board()
	{
		Node* cur = head;
		system("cls");
		cout << "\n";

		for (int ln_in_bg_arr = 0; ln_in_bg_arr < 3; ln_in_bg_arr++)
		{
			for (int sm_ln_in_node = 0; sm_ln_in_node < 3; sm_ln_in_node++)
			{
				for (int sm_col = 0; sm_col < 3; sm_col++)
				{
					cout << cur->subarray[ln_in_bg_arr][sm_col] << " ";
				}
				cur = cur->next;
				cout << "   ";
			}
			cout << endl;
			cur = head;
		}
		cout << "\n\n";

		cur = node_four;
		for (int ln_in_bg_arr = 0; ln_in_bg_arr < 3; ln_in_bg_arr++)
		{
			for (int sm_ln_in_node = 0; sm_ln_in_node < 3; sm_ln_in_node++)
			{
				for (int sm_col = 0; sm_col < 3; sm_col++)
				{
					cout << cur->subarray[ln_in_bg_arr][sm_col] << " ";
				}
				cur = cur->next;
				cout << "   ";
			}
			cout << endl;
			cur = node_four;
		}

		cout << "\n\n";

		cur = node_seven;
		for (int ln_in_bg_arr = 0; ln_in_bg_arr < 3; ln_in_bg_arr++)
		{
			for (int sm_ln_in_node = 0; sm_ln_in_node < 3; sm_ln_in_node++)
			{
				for (int sm_col = 0; sm_col < 3; sm_col++)
				{
					cout << cur->subarray[ln_in_bg_arr][sm_col] << " ";
				}
				cur = cur->next;
				cout << "   ";
			}
			cout << endl;
			cur = node_seven;
		}

		cout << "\n\n";
	}

	void play()
	{
		int cur_node_affectable;
		print_board();

		while (1) {
			cout << "\n  Player " << player << " - Enter Grid: ";
			cin >> cur_node_affectable;

			if (cur_node_affectable > 0 && cur_node_affectable < 10) {
				break;
			}

			print_board();
			cout << "\n  Try again.";
			cin.get();
		}

		int cur_node = cur_node_affectable;

		while (1) {
			print_board();
			int pos = 1;
			Node* cur = head;

			while (pos != cur_node)
			{
				cur = cur->next;
				pos++;
			}

			if (checkWin(cur->subarray)) {
				print_board();
				cout << "\n  Player " << player << " Won In The: " << cur_node << " Board";
				result_arr[X(cur_node)][Y(cur_node)] = player;
				if (checkWin(result_arr))
				{
					cout << "\n Congratulations! Player " << player << " Won finally!";
					break;
				}
				cin.get();
				cin.ignore();
			}

			if (first_time)
			{
				player = (player == 'x') ? 'x' : 'o';
				first_time = false;
			}
			else
			{
				player = (player == 'x') ? 'o' : 'x';
			}
			cur_node = cur_node_affectable;
			input(cur_node_affectable);
		}
	}

	void input(int& cur_node_affectable)
	{
		int pos_dot;
		Node* cur = head;
		while (1) {
			print_board();
			cout << "\n  Player " << player << " - Enter subgrid: ";
			cin >> pos_dot;
			if (pos_dot > 0 && pos_dot < 10)
			{
				int h = 1;

				while (h != cur_node_affectable)
				{
					cur = cur->next;
					h++;
				}

				if (cur->subarray[X(pos_dot)][Y(pos_dot)] == '.') {
					break;
				}
			}
			print_board();
			cout << "\n  Try again.";
			cin.ignore(); cin.get();
		}


		int z = 1;
		cur = head;
		while (z != cur_node_affectable)
		{
			cur = cur->next;
			z++;
		}

		cur->subarray[X(pos_dot)][Y(pos_dot)] = player;
		cur_node_affectable = pos_dot;
	}

	bool checkWin(char node[3][3])
	{
		char p = player;
		int row = 1, col = 1, main_diag = 1, anti_diag = 1;
		for (int i = 0; i < 3; ++i)
		{
			row = col = 1;
			if (node[i][3 - 1 - i] != p) {
				anti_diag = 0;
			}
			if (node[i][i] != p) {
				row = col = main_diag = 0;
			}

			else {
				for (int j = 0; j < 3; ++j)
				{
					if (node[i][j] != p) {
						row = 0;
					}
					if (node[j][i] != p) {
						col = 0;
					}
				}
			}

			if (row || col) {
				return 1;
			}
		}

		if (main_diag || anti_diag) {
			return 1;
		}
		return 0;
	}

};
void main() {

	cout << "Ultiamte Tic Tac Toe\n";
	LinkedList u;
	u.filling_board();
	u.print_board();

	bool check_choice = false;
	char YN = ' ';

	int input;

	while (!check_choice)
	{
		cout << " 1) Play\n 2) Quit\n" << "\n> ";
		cin >> input;

		switch (input) {
		case 1:
			u.play();
			cout << "Do you want to play again?(yes\\no)";
			cin >> YN;
			check_choice = (YN == 'Y') ? false : true;
			break;
		case 2:
			check_choice = true;
			break;
		default:
			cout << "Wronge Choice, Try again!\n";
			check_choice = false;
		}
		system("cls");
	}
	system("pause");
}