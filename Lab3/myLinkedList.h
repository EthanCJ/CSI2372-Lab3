#include <iostream>
#include <iomanip>
#include <process.h>
#include <limits.h>
using namespace std;
const int s = 20;

struct Evaluation {
	char student[s];
	int grade;
	Evaluation* next;
};

Evaluation* add(Evaluation* e, int& i) {
	int pos = -1;
	Evaluation* newEval = new Evaluation;

	do {
		cout << "Enter position:" << endl;
		cout << "(Only numbers higher than/equal to 0.)" << endl;
		cin >> pos;
	} while (pos < 0);
	cout << "Enter student name:" << endl;
	cin >> setw(s) >> newEval->student;
	cout << "Enter student grade:" << endl;
	cin >> newEval->grade;

	if (e == NULL) {
		newEval->next = NULL;
		i++;
		return newEval;
	}
	if (pos == 0) {
		newEval->next = e;
		i++;
		return newEval;
	}
	else {
		Evaluation* iter = e;
		while (pos > 1 && iter->next != NULL) {
			iter = iter->next;
			pos--;
		};
		if (iter->next == NULL) {
			newEval->next = NULL;
			iter->next = newEval;
		}
		else {
			Evaluation* n = iter->next;
			newEval->next = n;
			iter->next = newEval;
		}

		i++;
		return e;
	}
};

Evaluation* remove(Evaluation* e, int& i) {
	if (e == NULL) {
		cout << "Nothing to remove!";
		return e;
	}

	int pos = -1;
	Evaluation* newEval = new Evaluation;

	do {
		cout << "Enter position:" << endl;
		cout << "(Only numbers higher than/equal to 0.)" << endl;
		cin >> pos;
	} while (pos < 0);

	if (e->next == NULL) {
		i--;
		return NULL;
	}
	if (pos == 0) {
		i--;
		return e->next;
	}
	else {
		Evaluation* iter = e;
		Evaluation* prev = e;
		while (pos > 0 && iter->next != NULL) {
			prev = iter;
			iter = iter->next;
			pos--;
		};
		if (iter->next == NULL) {
			prev->next = NULL;
		}
		else {
			Evaluation* n = iter->next;
			prev->next = n;
		}

		i--;
		return e;
	}
};

void display(Evaluation* e) {
	Evaluation* iter = e;
	while (iter != NULL) {
		cout << (*iter).student << ", " << (*iter).grade << endl;
		iter = iter->next;
	}
};

int average(Evaluation* e, int const& s) {
	Evaluation* iter = e;
	int c = s;
	double avg = 0;
	while (c > 0) {
		if (iter == NULL) {
			cout << "HEY!!!! You re freaking Stupid.";
			return 0;
		}
		avg += (*iter).grade;
		iter = iter->next;
		c--;
	}
	cout << (avg / s);
	return 1;
};