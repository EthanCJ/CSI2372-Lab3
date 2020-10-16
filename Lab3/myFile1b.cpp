#include <iostream>
using namespace std;
enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };
struct Card
{
	Color color;
	Face face;
};

typedef Card Hand[5];
bool testPair(const Hand& h)
{
	for (int i = 0; i < 5;i++) {
		for (int j = i+1; j < 5;j++) {
			if (h[j].face==h[i].face) {
				return true;
			}
		}
	}
	return false;
}

/*Example of main()*/
int main()
{
	bool testPair(const Hand&);
	Card A{ club,seven };
	Card B{ spades,nine };
	Card C{ diamond,ten };
	Card D{ heart,jack };
	Card E{ club,eight };

	Hand myHand = {A,B,C,D,E};
	cout << "\nI have at least:" << testPair(myHand) << " pair" << endl;
	return 0;
}