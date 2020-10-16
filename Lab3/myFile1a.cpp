#include <iostream>
using namespace std;
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };

struct Card
{
	Color color;
	Face face;
};

int main()
{
	Card game[32];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 4; ++j) {
            game[4 * i + j].color = Color(j);
            game[4 * i + j].face = Face(i);
            cout << game[4 * i + j].face << " " << game[4 * i + j].color<<endl;
        }
    }
}